#include <bits/stdc++.h>
using std::cout;

//最大、最小情况的值
typedef struct ValueMaxMin {
    int whilemax, whilemin;
} vmm;
vmm **make2DArray(size_t rows, size_t cols) {
    vmm **p;
    p = new vmm *[rows];
    for (size_t i(0); i < rows; ++i)
        p[i] = new vmm[cols];
    return p;
}

void DP();
void output();

vmm **allStoneGrade /*总分数备忘录*/, **mark /*切分点备忘录*/;
int *stone, *Pressedstone /*石子数目前缀和*/, len /*石头初始组数*/;

int main() {
    // int _stone[] = {4, 4, 5, 9};
    // int _stone[] = {2, 3, 4, 6, 5, 4};
    int _stone[] = {7, 6, 5, 7, 100};
    stone = _stone;
    len = (sizeof(_stone) / sizeof(int));
    allStoneGrade = make2DArray(len, len);
    mark = make2DArray(len, len);
    Pressedstone = new int[len];
    Pressedstone[0] = stone[0];
    for (int i(1); i < len; ++i)
        Pressedstone[i] = Pressedstone[i - 1] + stone[i]; //前缀和化

    DP();

    output();

    delete Pressedstone;
    for (int i(0); i < len; ++i) {
        delete allStoneGrade[i];
        delete mark[i];
    }
    delete allStoneGrade;
    delete mark;

    return 0;
}

//获取区间石子数量和
int stoneSum(int start, int end) {
    if (start <= end)
        return Pressedstone[end] - (start > 0 ? Pressedstone[start - 1] : 0);
    return Pressedstone[len - 1] - (Pressedstone[start - 1] - Pressedstone[end]);
}

/*
 *思路和矩阵链相似
 *计算 每个起点(cur_start)下 长度(width)从2到n的
 *的分段的最优分割(cur_div)，将分割点和总分数记入备忘录
 *备忘录是二维数组，行索引和列索引 分别是 分段的起点和终点，闭区间，
 *方向是石头位置递增的方向，越过最后一个石子后到第一个石子
 */
void DP() {
    //未合并的时候(宽度为1) 分数为0
    for (int i(0); i < len; ++i)
        allStoneGrade[i][i] = {0, 0};
    //宽度从从2遍历到n
    for (int width(2); width <= len; ++width) {
        //起点终点宽度为wide,遍历每一个起点(0到len-1)
        for (int cur_start = 0 /*切分起点*/; cur_start < len; ++cur_start) {
            int cur_end /*切分终点*/ = cur_start + width - 1;
            if (cur_end >= len) cur_end -= len;
            mark[cur_start][cur_end] = {cur_start, cur_start};
            allStoneGrade[cur_start][cur_end].whilemin = 0xffffffff >> 1;
            allStoneGrade[cur_start][cur_end].whilemax = 0;
            for (int cur_div =
                         cur_start /*切分点默认是下标所索引的石子与下一个石子之间*/,
                     temp;
                 cur_div != cur_end; //因为不方便判断大小 所以使用不等号
                 ++cur_div, (cur_div >= len) && (cur_div -= len)) {
                //比较、更新极值和最优分割点
                if ((temp = allStoneGrade[cur_start][cur_div].whilemax +
                            allStoneGrade[(cur_div + 1) % len][cur_end].whilemax) >
                    allStoneGrade[cur_start][cur_end].whilemax) {
                    allStoneGrade[cur_start][cur_end].whilemax = temp;
                    mark[cur_start][cur_end].whilemax = cur_div;
                }
                if ((temp = allStoneGrade[cur_start][cur_div].whilemin +
                            allStoneGrade[(cur_div + 1) % len][cur_end].whilemin) <
                    allStoneGrade[cur_start][cur_end].whilemin) {
                    allStoneGrade[cur_start][cur_end].whilemin = temp;
                    mark[cur_start][cur_end].whilemin = cur_div;
                }
            }
            //之前得分和 再加上当前得分(石子数)
            allStoneGrade[cur_start][cur_end].whilemax +=
                stoneSum(cur_start, cur_end);
            allStoneGrade[cur_start][cur_end].whilemin +=
                stoneSum(cur_start, cur_end);
        }
    }
}

/*
 *输出是模拟每次的结合情况
 *数据结构上使用数组式链表
 *合并时将后一个石堆添加到前一个石堆，并在“链表”中跳过后一个石堆
 *输出的时候走链表路线(实际是记录索引,因为int内存小于指针内存)
 *这样可以同时利用两者优势
 */
enum { MAX,
       MIN };
int times, score;
int start_point /*输出起点*/;
int *stoneHeap, *nextHeap;

//"链表式"输出模拟石堆状态
void prStoneHeap() {
    int pin(start_point);
    do {
        cout << stoneHeap[pin] << ' ';
        pin = nextHeap[pin];
    } while (pin != start_point);
}

//递归获取切分点并输出
void output_(const int start, const int end,
             const bool mode /*输出模式,MAX||MIN*/) {
    if (start == end) {
        return;
    }

    //此处将vmm结构体作为长为2的数组处理，mode做下标获取值
    int div = ((int *) &mark[start][end])[mode], divp = (div + 1) % len;
    output_(start, div, mode), output_(divp, end, mode);
    cout << "第" << ++times << "次:";
    stoneHeap[start] += stoneHeap[divp];
    nextHeap[start] = nextHeap[divp];
    if (divp == start_point) start_point = nextHeap[start];
    prStoneHeap();
    std::cout << "   得分:" << stoneSum(start, end) << std::endl;
}

void output() {
    stoneHeap = new int[len];
    nextHeap = new int[len];

    //找到总分数最大和最小的分段起点
    int max, min, start_min(0), start_max(0), temp;
    max = allStoneGrade[0][-1 + len].whilemax,
    min = allStoneGrade[0][-1 + len].whilemin;
    for (int start(1); start < len; ++start) {
        (temp = allStoneGrade[start][start - 1].whilemax) > max &&
            (max = temp, start_max = start);
        (temp = allStoneGrade[start][start - 1].whilemin) < max &&
            (min = temp, start_min = start);
    }
    //输出最大分数的模拟
    memcpy(stoneHeap, stone, len * sizeof(len));
    for (int i(0); i < len; ++i) {
        nextHeap[i] = i + 1;
    }
    nextHeap[len - 1] = 0;
    times = score = 0;
    start_point = start_max;
    cout << "初始：";
    prStoneHeap();
    putchar('\n');
    output_(start_point, (start_point - 1 + len) % len, MAX);
    cout << "总分:" << max << "\n\n";
    //输出最小分数的模拟
    memcpy(stoneHeap, stone, len * sizeof(len));
    for (int i(0); i < len; ++i) {
        nextHeap[i] = i + 1;
    }
    nextHeap[len - 1] = 0;
    times = score = 0;
    start_point = start_min;
    cout << "初始:";
    prStoneHeap();
    putchar('\n');
    output_(start_min, (start_min - 1 + len) % len, MIN);
    cout << "总分:" << min << std::endl;

    delete stoneHeap;
    delete nextHeap;
}
