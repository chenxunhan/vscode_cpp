#include <bits/stdc++.h>

/*
 *
 * 二维数组表示意义与大部分人的不同
 * 他人[i][j]:代表第i个位置到第j个位置
 * 本代码[i][l]:代表以第i个位置为始,跨越长度为l(第i个位置到i+l的位置)
 *
*/

enum Mode { Max,
            Min };

const int MAXHEAPNUMBER = 20; //石头堆最大数目

//heap_number:石头堆数目, heap_score[i]:顺时针第i堆的分数(从0记起)
int heap_number, heap_score[MAXHEAPNUMBER];
/*subheap_score_sum[i][l]: 以顺时针第i堆开始记起长度为l(从0记起,实际连续弧堆长度为l+1)
的连续石头弧堆的总石头分数和
eg.heap_score[]={4, 4, 5, 9} 时
subheap_score_sum[0][1]=4+4=8,
subheap_score_sum[2][2]=5+9+4=18 */
int subheap_score_sum[MAXHEAPNUMBER][MAXHEAPNUMBER];

int order_pointer; //下方结构体里order的指针,记录时用到而已

//保存合并石头堆获得最大/小分数时的各种信息
struct MaxMinMerge {
    //[i][l]:第i堆记起长度l的连续石头堆合并可获得最大/小分数和
    int score[MAXHEAPNUMBER][MAXHEAPNUMBER];
    //[i][l]:第i堆记起长度l的连续石头堆合并获得最大/小分数和时合并处前一个石头的堆序下标
    int headpart_lastindex[MAXHEAPNUMBER][MAXHEAPNUMBER];
    int headpart_firstindex;  /*代表将圆圈石头堆展开成一维石头堆的切分位置,
                                其中切分位置避开最大/小合并方案中所有的合并位置,
                                保留这个信息方便后面输出最大/小分合并石堆方案<>表示法*/
    int order[MAXHEAPNUMBER]; /*最大/小依次合并顺序
                            [i]:代表第i次(0记起)合并时合并的是第order[i]和order[i]+1石头*/
} merge;

//为了石头堆输出详细合并具体过程时使用的结构体
struct MergeScore {
    int score;                //这个位置的石头堆分数
    int pre;                  //这个位置的石头堆前指针石头堆下标
    int next;                 //这个位置的石头堆后指针石头堆下标
} merge_score[MAXHEAPNUMBER]; //使用并查集更新其中的pre,next
//总体作用:合并时利用pre合并分数,输出时根据next遍历减少时间复杂度

/*因为石头堆是圆圈的,放在一维数组里,直接拿取下标时会越界,因此需要取余圆圈长度,即堆的数目
因此每一次调用heap_score[],取下标时用这个函数*/
int getHeapIndex(const int &start_index_, const int &length_) {
    return (start_index_ + length_) % heap_number;
}

//初始化石头堆 和 连续石头弧堆的总石头分数和
void initHeap(const int &heap_number_, const int heap_score_[]) {
    heap_number = heap_number_;
    for (int i = 0; i < heap_number; ++i) //初始化石头堆 和 长度为0的连续石头弧堆总石头分数和
        subheap_score_sum[i][0] = heap_score[i] = heap_score_[i];

    for (int i = 0; i < heap_number; ++i)     //初始化起始坐标为[0,heap_number)的连续石头弧堆总石头分数和
        for (int l = 1; l < heap_number; ++l) //初始化长度为[1,heap_number)的连续石头弧堆总石头分数和
            //在起始坐标固定情况下,长度为l的分数和 是 长度l-1的分数和+当前石头的分数
            subheap_score_sum[i][l] = subheap_score_sum[i][l - 1] + heap_score[getHeapIndex(i, l)];
}

//输出初始化信息
void printInitMessage() {
    printf("初始化信息:\n");
    printf("heap_score[i]: \n"
           "*代表顺时针记起第i堆石头的分数*\n"
           "堆序:",
           heap_number);
    for (int i = 0; i < heap_number; ++i)
        printf(" [%3d]", i);
    printf("\n分数:");
    for (int i = 0; i < heap_number; ++i)
        printf(" {%3d}", heap_score[i]);
    printf("\n\nsubheap_score_sum[i][l]: \n");
    printf(
        "*代表从第i堆记起长度l的连续子弧堆\n石头总分数*\n"
        "i\\l ");
    for (int i = 0; i < heap_number; ++i)
        printf("[%3d]", i);
    putchar('\n');
    for (int i = 0; i < heap_number; ++i) {
        printf("[%2d]", i);
        for (int l = 0; l < heap_number; ++l)
            printf("%4d ", subheap_score_sum[i][l]);
        putchar('\n');
    }
    putchar('\n');
}

//动态规划打出结构体里score[][]可获得最大/小分数和表
void dpMergeScore(const Mode &mode_) {
    //处理merge
    for (int start_index_ = 0; start_index_ < heap_number; ++start_index_) //长度为0,不合并,合并得分为0
        merge.score[start_index_][0] = 0;
    for (int length_ = 1; length_ < heap_number; ++length_) {                    //计算长度为[1,heap_number)的
        for (int start_index_ = 0; start_index_ < heap_number; ++start_index_) { //计算初始坐标为[0,heap_number)
            int current_merge_score = (mode_ == Max ? INT_MIN : INT_MAX),        //临时记录最大/小分数合并的分数
                current_merge_headpartlastindex;                                 //临时记录最大/小分数合并位置前一颗石子的下标
            for (int divide_position = start_index_;
                 divide_position < start_index_ + length_;
                 ++divide_position) { //对当前合并段的各个位置都和并一次,得到可以获得最大/小分的合并位置
                int current_merge_score_ = subheap_score_sum[start_index_][length_] +
                                           merge.score[start_index_][divide_position - start_index_] +
                                           merge.score[getHeapIndex(0, divide_position + 1)][start_index_ + length_ - (divide_position + 1)]; //对当前合并段divide_position位置进行和并后的当前得分和

                //求最大模式时若当前分数和大于临时分数和
                if (((mode_ == Max) && (current_merge_score_ > current_merge_score)) ||
                    //求最小模式时若当前分数和小于临时分数和
                    ((mode_ == Min) && (current_merge_score_ < current_merge_score))) {
                    current_merge_score = current_merge_score_;        //临时记录合并分数为当前合并分数
                    current_merge_headpartlastindex = divide_position; //临时记录合并位置为当前合并位置
                }
            }
            merge.score[start_index_][length_] = current_merge_score; //临时分数记入表中
            merge.headpart_lastindex[start_index_][length_] =
                getHeapIndex(0, current_merge_headpartlastindex); //临时合并位置记入表中
        }
    }

    /*因为石头堆是圆圈的,因此要遍历依次看看以各个位置为起始位置时(把圆圈展开成一维线段,起始位置不会被分割),
    长度为总长度的所有石头堆 哪一个的合并分数最大/小,记录<>合并表示法的输出起点,保证<>内的合并不会被断开*/
    for (int merge_headpart_firstindex_ = 0, current_merge_score = (mode_ == Max ? INT_MIN : INT_MAX);
         merge_headpart_firstindex_ < heap_number;
         ++merge_headpart_firstindex_) {
        int merge_score_ = merge.score[merge_headpart_firstindex_][heap_number - 1];
        if (((mode_ == Max) && (merge_score_ > current_merge_score)) ||
            ((mode_ == Min) && (merge_score_ < current_merge_score))) {
            current_merge_score = merge_score_;
            merge.headpart_firstindex = merge_headpart_firstindex_;
        }
    }

    printf("-↓-↓-获得最");
    printf(mode_ == Max ? "大" : "小");
    printf("分情况-↓-↓-\n");
}

//输出各子连续石头堆合并后获得的目标分数
void printMergeScore() {
    printf("merge.score[i][l]: \n");
    printf(
        "*代表从第i堆记起长度l的连续子弧堆\n"
        "所有石头合并可获得的目标分数*\n"
        "i\\l ");
    for (int i = 0; i < heap_number; ++i)
        printf("[%3d]", i);
    putchar('\n');
    for (int i = 0; i < heap_number; ++i) {
        printf("[%2d]", i);
        for (int l = 0; l < heap_number; ++l)
            printf("%4d ", merge.score[i][l]);
        putchar('\n');
    }
    putchar('\n');
}

//输出各子连续石头堆合并位置前前一堆最后一堆石子的分数
void printMergeHeadPartLastindex() {
    printf("merge.headpart_lastindex[i][l]: \n");
    printf(
        "*代表从第i堆记起长度l的连续子弧堆\n"
        "所有石头合并可获得的目标分数时\n"
        "前一个合并弧顺时针记起尾堆石头堆序*\n"
        "i\\l ");
    for (int i = 0; i < heap_number; ++i)
        printf("[%3d]", i);
    putchar('\n');
    for (int i = 0; i < heap_number; ++i) {
        printf("[%2d]", i);
        for (int l = 0; l < heap_number; ++l)
            printf("%4d ", merge.headpart_lastindex[i][l]);
        putchar('\n');
    }
    putchar('\n');
}

//并查集的查,找到这对石子被合并在了哪个石子堆里
int findRoot(int index) {
    int root = index, pre_index;
    while (merge_score[root].pre != root) {
        root = merge_score[root].pre;
    }
    while (merge_score[index].pre != root) {
        pre_index = merge_score[index].pre;
        merge_score[index].pre = root;
        index = pre_index;
    }
    return root;
}

void printMergePlanProcess() {
    int total_score = 0; //总分
    //初始化并查集需要使用的结构体
    for (int i = 0; i < heap_number; ++i) {
        merge_score[i].score = heap_score[i];
        merge_score[i].pre = i;
        merge_score[i].next = i + 1;
    }
    merge_score[heap_number - 1].next = 0;

    for (int i = 0; i < heap_number - 1; ++i) {      //总共有heap_number-1次合并
        int heapscore_merge_index_ = merge.order[i], //赋值第i次合并的合并位置
            heapscore_mergeindex_next = merge_score[heapscore_merge_index_].next;

        //查找之前把它并进去的石头的坐标,作为此次合并位置
        heapscore_merge_index_ = findRoot(heapscore_merge_index_);

        //将合并位置后的石头分数并到这个合并位置的石头分数上
        merge_score[heapscore_merge_index_].score += merge_score[heapscore_mergeindex_next].score;
        //并将后面的石头的前指针置为当前合并位置,代表这颗石头被合并掉了
        merge_score[heapscore_mergeindex_next].pre = heapscore_merge_index_;
        //输出当前位置后直接输出下一个位置,因此合并位置的石头下指针指向并进去石头的下指针
        merge_score[heapscore_merge_index_].next = merge_score[heapscore_mergeindex_next].next;

        //记录此次得分入总分
        total_score += merge_score[heapscore_merge_index_].score;
        printf("得分:%3d, ", merge_score[heapscore_merge_index_].score);
        printf("第%d次: ", i + 1);

        //输出合并信息，每次合并(i++)后只需输出heap_number - i堆的石头信息
        int print_index = findRoot(0); //找到输出起点
        for (int t = 1; t < heap_number - i; ++t) {
            printf("{%3d}", merge_score[print_index].score);
            print_index = merge_score[print_index].next;
        }
        putchar('\n');
    }
    printf("总得分: %d\n", total_score);
    printf("-↑-↑-↑-↑-↑----↑-↑-↑-↑-↑-\n\n");
}

//输出合并得最大/小分的具体合并过程
//输出从start_index_开始,长度为length_的石头堆的合并具体过程
void printMergePlan(int start_index_ = merge.headpart_firstindex,
                    int length_ = heap_number - 1, bool first = 1) {
    if (first) { //第一次输出
        printf("merge.headpart_firstindex:%d\n", merge.headpart_firstindex);
        printf("*代表将圆圈石头堆展开成一维石头堆的切分位置,\n"
               "其中切分位置避开合并方案中所有的合并位置*\n\n");
        printf("合并石堆方案<>表示法:\n");
        order_pointer = 0;
    }
    //递归底层条件:长度为0,也就是只剩下一个石头,不用划分,直接输出
    if (length_ == 0) {
        printf("{%d}", heap_score[start_index_]);
        return;
    }
    //合并位置前半堆的长度
    int length_1 = merge.headpart_lastindex[start_index_][length_] - start_index_,
        //合并位置后半堆第一个石子的下标
        index_2 = (merge.headpart_lastindex[start_index_][length_] + 1) % heap_number,
        //合并位置后半堆的长度
        length_2 = start_index_ + length_ - index_2;
    printf("<");
    //输出合并位置前半堆具体合并过程
    printMergePlan(start_index_, length_1 < 0 ? length_1 + heap_number : length_1, 0);
    //输出合并位置后半堆具体合并过程
    printMergePlan(index_2, length_2 % heap_number, 0);
    printf(">");
    //记录每一次合并得合并位置
    merge.order[order_pointer++] = merge.headpart_lastindex[start_index_][length_];
    if (first) {
        printf("\n\nmerge.order[]:\n"
               "*依次合并顺序[i]->[j]\n"
               "先合并第i堆与i+1堆,\n"
               "再合并第j堆与j+1堆*\n"
               "[%d]",
               merge.order[0]);
        for (int i = 1; i < heap_number - 1; ++i)
            printf("->[%d]", merge.order[i]);
        printf("\n\n");
        printMergePlanProcess();
    }
}

int main() {

    int heap_score_[] = {4, 4, 5, 9};
    // int heap_score_[] = {2, 3, 4, 6, 5, 4};
    // int heap_score_[] = {7, 6, 5, 7, 100};
    initHeap(sizeof(heap_score_) / sizeof(int), heap_score_); //初始化石头堆 和 连续石头弧堆的总石头分数和
    printInitMessage();                                       //输出初始化信息

    //输出获得最大分的
    dpMergeScore(Max);             //动态规划打出结构体里score[][]可获得最大/小分数和表
    printMergeScore();             //输出各子连续石头堆合并后获得的目标分数
    printMergeHeadPartLastindex(); //输出各子连续石头堆合并位置前前一堆最后一堆石子的分数
    printMergePlan();              //输出合并得最大/小分的具体合并过程

    //输出获得最小分的
    dpMergeScore(Min);
    printMergeScore();
    printMergeHeadPartLastindex();
    printMergePlan();

    return 0;
}
