#include <bits/stdc++.h>

/*
 *
 * ��ά�����ʾ������󲿷��˵Ĳ�ͬ
 * ����[i][j]:�����i��λ�õ���j��λ��
 * ������[i][l]:�����Ե�i��λ��Ϊʼ,��Խ����Ϊl(��i��λ�õ�i+l��λ��)
 *
*/

enum Mode { Max,
            Min };

const int MAXHEAPNUMBER = 20; //ʯͷ�������Ŀ

//heap_number:ʯͷ����Ŀ, heap_score[i]:˳ʱ���i�ѵķ���(��0����)
int heap_number, heap_score[MAXHEAPNUMBER];
/*subheap_score_sum[i][l]: ��˳ʱ���i�ѿ�ʼ���𳤶�Ϊl(��0����,ʵ���������ѳ���Ϊl+1)
������ʯͷ���ѵ���ʯͷ������
eg.heap_score[]={4, 4, 5, 9} ʱ
subheap_score_sum[0][1]=4+4=8,
subheap_score_sum[2][2]=5+9+4=18 */
int subheap_score_sum[MAXHEAPNUMBER][MAXHEAPNUMBER];

int order_pointer; //�·��ṹ����order��ָ��,��¼ʱ�õ�����

//����ϲ�ʯͷ�ѻ�����/С����ʱ�ĸ�����Ϣ
struct MaxMinMerge {
    //[i][l]:��i�Ѽ��𳤶�l������ʯͷ�Ѻϲ��ɻ�����/С������
    int score[MAXHEAPNUMBER][MAXHEAPNUMBER];
    //[i][l]:��i�Ѽ��𳤶�l������ʯͷ�Ѻϲ�������/С������ʱ�ϲ���ǰһ��ʯͷ�Ķ����±�
    int headpart_lastindex[MAXHEAPNUMBER][MAXHEAPNUMBER];
    int headpart_firstindex;  /*����ԲȦʯͷ��չ����һάʯͷ�ѵ��з�λ��,
                                �����з�λ�ñܿ����/С�ϲ����������еĺϲ�λ��,
                                ���������Ϣ�������������/С�ֺϲ�ʯ�ѷ���<>��ʾ��*/
    int order[MAXHEAPNUMBER]; /*���/С���κϲ�˳��
                            [i]:�����i��(0����)�ϲ�ʱ�ϲ����ǵ�order[i]��order[i]+1ʯͷ*/
} merge;

//Ϊ��ʯͷ�������ϸ�ϲ��������ʱʹ�õĽṹ��
struct MergeScore {
    int score;                //���λ�õ�ʯͷ�ѷ���
    int pre;                  //���λ�õ�ʯͷ��ǰָ��ʯͷ���±�
    int next;                 //���λ�õ�ʯͷ�Ѻ�ָ��ʯͷ���±�
} merge_score[MAXHEAPNUMBER]; //ʹ�ò��鼯�������е�pre,next
//��������:�ϲ�ʱ����pre�ϲ�����,���ʱ����next��������ʱ�临�Ӷ�

/*��Ϊʯͷ����ԲȦ��,����һά������,ֱ����ȡ�±�ʱ��Խ��,�����Ҫȡ��ԲȦ����,���ѵ���Ŀ
���ÿһ�ε���heap_score[],ȡ�±�ʱ���������*/
int getHeapIndex(const int &start_index_, const int &length_) {
    return (start_index_ + length_) % heap_number;
}

//��ʼ��ʯͷ�� �� ����ʯͷ���ѵ���ʯͷ������
void initHeap(const int &heap_number_, const int heap_score_[]) {
    heap_number = heap_number_;
    for (int i = 0; i < heap_number; ++i) //��ʼ��ʯͷ�� �� ����Ϊ0������ʯͷ������ʯͷ������
        subheap_score_sum[i][0] = heap_score[i] = heap_score_[i];

    for (int i = 0; i < heap_number; ++i)     //��ʼ����ʼ����Ϊ[0,heap_number)������ʯͷ������ʯͷ������
        for (int l = 1; l < heap_number; ++l) //��ʼ������Ϊ[1,heap_number)������ʯͷ������ʯͷ������
            //����ʼ����̶������,����Ϊl�ķ����� �� ����l-1�ķ�����+��ǰʯͷ�ķ���
            subheap_score_sum[i][l] = subheap_score_sum[i][l - 1] + heap_score[getHeapIndex(i, l)];
}

//�����ʼ����Ϣ
void printInitMessage() {
    printf("��ʼ����Ϣ:\n");
    printf("heap_score[i]: \n"
           "*����˳ʱ������i��ʯͷ�ķ���*\n"
           "����:",
           heap_number);
    for (int i = 0; i < heap_number; ++i)
        printf(" [%3d]", i);
    printf("\n����:");
    for (int i = 0; i < heap_number; ++i)
        printf(" {%3d}", heap_score[i]);
    printf("\n\nsubheap_score_sum[i][l]: \n");
    printf(
        "*����ӵ�i�Ѽ��𳤶�l�������ӻ���\nʯͷ�ܷ���*\n"
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

//��̬�滮����ṹ����score[][]�ɻ�����/С�����ͱ�
void dpMergeScore(const Mode &mode_) {
    //����merge
    for (int start_index_ = 0; start_index_ < heap_number; ++start_index_) //����Ϊ0,���ϲ�,�ϲ��÷�Ϊ0
        merge.score[start_index_][0] = 0;
    for (int length_ = 1; length_ < heap_number; ++length_) {                    //���㳤��Ϊ[1,heap_number)��
        for (int start_index_ = 0; start_index_ < heap_number; ++start_index_) { //�����ʼ����Ϊ[0,heap_number)
            int current_merge_score = (mode_ == Max ? INT_MIN : INT_MAX),        //��ʱ��¼���/С�����ϲ��ķ���
                current_merge_headpartlastindex;                                 //��ʱ��¼���/С�����ϲ�λ��ǰһ��ʯ�ӵ��±�
            for (int divide_position = start_index_;
                 divide_position < start_index_ + length_;
                 ++divide_position) { //�Ե�ǰ�ϲ��εĸ���λ�ö��Ͳ�һ��,�õ����Ի�����/С�ֵĺϲ�λ��
                int current_merge_score_ = subheap_score_sum[start_index_][length_] +
                                           merge.score[start_index_][divide_position - start_index_] +
                                           merge.score[getHeapIndex(0, divide_position + 1)][start_index_ + length_ - (divide_position + 1)]; //�Ե�ǰ�ϲ���divide_positionλ�ý��кͲ���ĵ�ǰ�÷ֺ�

                //�����ģʽʱ����ǰ�����ʹ�����ʱ������
                if (((mode_ == Max) && (current_merge_score_ > current_merge_score)) ||
                    //����Сģʽʱ����ǰ������С����ʱ������
                    ((mode_ == Min) && (current_merge_score_ < current_merge_score))) {
                    current_merge_score = current_merge_score_;        //��ʱ��¼�ϲ�����Ϊ��ǰ�ϲ�����
                    current_merge_headpartlastindex = divide_position; //��ʱ��¼�ϲ�λ��Ϊ��ǰ�ϲ�λ��
                }
            }
            merge.score[start_index_][length_] = current_merge_score; //��ʱ�����������
            merge.headpart_lastindex[start_index_][length_] =
                getHeapIndex(0, current_merge_headpartlastindex); //��ʱ�ϲ�λ�ü������
        }
    }

    /*��Ϊʯͷ����ԲȦ��,���Ҫ�������ο����Ը���λ��Ϊ��ʼλ��ʱ(��ԲȦչ����һά�߶�,��ʼλ�ò��ᱻ�ָ�),
    ����Ϊ�ܳ��ȵ�����ʯͷ�� ��һ���ĺϲ��������/С,��¼<>�ϲ���ʾ����������,��֤<>�ڵĺϲ����ᱻ�Ͽ�*/
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

    printf("-��-��-�����");
    printf(mode_ == Max ? "��" : "С");
    printf("�����-��-��-\n");
}

//�����������ʯͷ�Ѻϲ����õ�Ŀ�����
void printMergeScore() {
    printf("merge.score[i][l]: \n");
    printf(
        "*����ӵ�i�Ѽ��𳤶�l�������ӻ���\n"
        "����ʯͷ�ϲ��ɻ�õ�Ŀ�����*\n"
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

//�����������ʯͷ�Ѻϲ�λ��ǰǰһ�����һ��ʯ�ӵķ���
void printMergeHeadPartLastindex() {
    printf("merge.headpart_lastindex[i][l]: \n");
    printf(
        "*����ӵ�i�Ѽ��𳤶�l�������ӻ���\n"
        "����ʯͷ�ϲ��ɻ�õ�Ŀ�����ʱ\n"
        "ǰһ���ϲ���˳ʱ�����β��ʯͷ����*\n"
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

//���鼯�Ĳ�,�ҵ����ʯ�ӱ��ϲ������ĸ�ʯ�Ӷ���
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
    int total_score = 0; //�ܷ�
    //��ʼ�����鼯��Ҫʹ�õĽṹ��
    for (int i = 0; i < heap_number; ++i) {
        merge_score[i].score = heap_score[i];
        merge_score[i].pre = i;
        merge_score[i].next = i + 1;
    }
    merge_score[heap_number - 1].next = 0;

    for (int i = 0; i < heap_number - 1; ++i) {      //�ܹ���heap_number-1�κϲ�
        int heapscore_merge_index_ = merge.order[i], //��ֵ��i�κϲ��ĺϲ�λ��
            heapscore_mergeindex_next = merge_score[heapscore_merge_index_].next;

        //����֮ǰ��������ȥ��ʯͷ������,��Ϊ�˴κϲ�λ��
        heapscore_merge_index_ = findRoot(heapscore_merge_index_);

        //���ϲ�λ�ú��ʯͷ������������ϲ�λ�õ�ʯͷ������
        merge_score[heapscore_merge_index_].score += merge_score[heapscore_mergeindex_next].score;
        //���������ʯͷ��ǰָ����Ϊ��ǰ�ϲ�λ��,�������ʯͷ���ϲ�����
        merge_score[heapscore_mergeindex_next].pre = heapscore_merge_index_;
        //�����ǰλ�ú�ֱ�������һ��λ��,��˺ϲ�λ�õ�ʯͷ��ָ��ָ�򲢽�ȥʯͷ����ָ��
        merge_score[heapscore_merge_index_].next = merge_score[heapscore_mergeindex_next].next;

        //��¼�˴ε÷����ܷ�
        total_score += merge_score[heapscore_merge_index_].score;
        printf("�÷�:%3d, ", merge_score[heapscore_merge_index_].score);
        printf("��%d��: ", i + 1);

        //����ϲ���Ϣ��ÿ�κϲ�(i++)��ֻ�����heap_number - i�ѵ�ʯͷ��Ϣ
        int print_index = findRoot(0); //�ҵ�������
        for (int t = 1; t < heap_number - i; ++t) {
            printf("{%3d}", merge_score[print_index].score);
            print_index = merge_score[print_index].next;
        }
        putchar('\n');
    }
    printf("�ܵ÷�: %d\n", total_score);
    printf("-��-��-��-��-��----��-��-��-��-��-\n\n");
}

//����ϲ������/С�ֵľ���ϲ�����
//�����start_index_��ʼ,����Ϊlength_��ʯͷ�ѵĺϲ��������
void printMergePlan(int start_index_ = merge.headpart_firstindex,
                    int length_ = heap_number - 1, bool first = 1) {
    if (first) { //��һ�����
        printf("merge.headpart_firstindex:%d\n", merge.headpart_firstindex);
        printf("*����ԲȦʯͷ��չ����һάʯͷ�ѵ��з�λ��,\n"
               "�����з�λ�ñܿ��ϲ����������еĺϲ�λ��*\n\n");
        printf("�ϲ�ʯ�ѷ���<>��ʾ��:\n");
        order_pointer = 0;
    }
    //�ݹ�ײ�����:����Ϊ0,Ҳ����ֻʣ��һ��ʯͷ,���û���,ֱ�����
    if (length_ == 0) {
        printf("{%d}", heap_score[start_index_]);
        return;
    }
    //�ϲ�λ��ǰ��ѵĳ���
    int length_1 = merge.headpart_lastindex[start_index_][length_] - start_index_,
        //�ϲ�λ�ú��ѵ�һ��ʯ�ӵ��±�
        index_2 = (merge.headpart_lastindex[start_index_][length_] + 1) % heap_number,
        //�ϲ�λ�ú��ѵĳ���
        length_2 = start_index_ + length_ - index_2;
    printf("<");
    //����ϲ�λ��ǰ��Ѿ���ϲ�����
    printMergePlan(start_index_, length_1 < 0 ? length_1 + heap_number : length_1, 0);
    //����ϲ�λ�ú��Ѿ���ϲ�����
    printMergePlan(index_2, length_2 % heap_number, 0);
    printf(">");
    //��¼ÿһ�κϲ��úϲ�λ��
    merge.order[order_pointer++] = merge.headpart_lastindex[start_index_][length_];
    if (first) {
        printf("\n\nmerge.order[]:\n"
               "*���κϲ�˳��[i]->[j]\n"
               "�Ⱥϲ���i����i+1��,\n"
               "�ٺϲ���j����j+1��*\n"
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
    initHeap(sizeof(heap_score_) / sizeof(int), heap_score_); //��ʼ��ʯͷ�� �� ����ʯͷ���ѵ���ʯͷ������
    printInitMessage();                                       //�����ʼ����Ϣ

    //���������ֵ�
    dpMergeScore(Max);             //��̬�滮����ṹ����score[][]�ɻ�����/С�����ͱ�
    printMergeScore();             //�����������ʯͷ�Ѻϲ����õ�Ŀ�����
    printMergeHeadPartLastindex(); //�����������ʯͷ�Ѻϲ�λ��ǰǰһ�����һ��ʯ�ӵķ���
    printMergePlan();              //����ϲ������/С�ֵľ���ϲ�����

    //��������С�ֵ�
    dpMergeScore(Min);
    printMergeScore();
    printMergeHeadPartLastindex();
    printMergePlan();

    return 0;
}
