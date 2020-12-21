#include <bits/stdc++.h>
using std::cout;

//�����С�����ֵ
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

vmm **allStoneGrade /*�ܷ�������¼*/, **mark /*�зֵ㱸��¼*/;
int *stone, *Pressedstone /*ʯ����Ŀǰ׺��*/, len /*ʯͷ��ʼ����*/;

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
        Pressedstone[i] = Pressedstone[i - 1] + stone[i]; //ǰ׺�ͻ�

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

//��ȡ����ʯ��������
int stoneSum(int start, int end) {
    if (start <= end)
        return Pressedstone[end] - (start > 0 ? Pressedstone[start - 1] : 0);
    return Pressedstone[len - 1] - (Pressedstone[start - 1] - Pressedstone[end]);
}

/*
 *˼·�;���������
 *���� ÿ�����(cur_start)�� ����(width)��2��n��
 *�ķֶε����ŷָ�(cur_div)�����ָ����ܷ������뱸��¼
 *����¼�Ƕ�ά���飬�������������� �ֱ��� �ֶε������յ㣬�����䣬
 *������ʯͷλ�õ����ķ���Խ�����һ��ʯ�Ӻ󵽵�һ��ʯ��
 */
void DP() {
    //δ�ϲ���ʱ��(���Ϊ1) ����Ϊ0
    for (int i(0); i < len; ++i)
        allStoneGrade[i][i] = {0, 0};
    //��ȴӴ�2������n
    for (int width(2); width <= len; ++width) {
        //����յ���Ϊwide,����ÿһ�����(0��len-1)
        for (int cur_start = 0 /*�з����*/; cur_start < len; ++cur_start) {
            int cur_end /*�з��յ�*/ = cur_start + width - 1;
            if (cur_end >= len) cur_end -= len;
            mark[cur_start][cur_end] = {cur_start, cur_start};
            allStoneGrade[cur_start][cur_end].whilemin = 0xffffffff >> 1;
            allStoneGrade[cur_start][cur_end].whilemax = 0;
            for (int cur_div =
                         cur_start /*�зֵ�Ĭ�����±���������ʯ������һ��ʯ��֮��*/,
                     temp;
                 cur_div != cur_end; //��Ϊ�������жϴ�С ����ʹ�ò��Ⱥ�
                 ++cur_div, (cur_div >= len) && (cur_div -= len)) {
                //�Ƚϡ����¼�ֵ�����ŷָ��
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
            //֮ǰ�÷ֺ� �ټ��ϵ�ǰ�÷�(ʯ����)
            allStoneGrade[cur_start][cur_end].whilemax +=
                stoneSum(cur_start, cur_end);
            allStoneGrade[cur_start][cur_end].whilemin +=
                stoneSum(cur_start, cur_end);
        }
    }
}

/*
 *�����ģ��ÿ�εĽ�����
 *���ݽṹ��ʹ������ʽ����
 *�ϲ�ʱ����һ��ʯ����ӵ�ǰһ��ʯ�ѣ����ڡ�������������һ��ʯ��
 *�����ʱ��������·��(ʵ���Ǽ�¼����,��Ϊint�ڴ�С��ָ���ڴ�)
 *��������ͬʱ������������
 */
enum { MAX,
       MIN };
int times, score;
int start_point /*������*/;
int *stoneHeap, *nextHeap;

//"����ʽ"���ģ��ʯ��״̬
void prStoneHeap() {
    int pin(start_point);
    do {
        cout << stoneHeap[pin] << ' ';
        pin = nextHeap[pin];
    } while (pin != start_point);
}

//�ݹ��ȡ�зֵ㲢���
void output_(const int start, const int end,
             const bool mode /*���ģʽ,MAX||MIN*/) {
    if (start == end) {
        return;
    }

    //�˴���vmm�ṹ����Ϊ��Ϊ2�����鴦��mode���±��ȡֵ
    int div = ((int *) &mark[start][end])[mode], divp = (div + 1) % len;
    output_(start, div, mode), output_(divp, end, mode);
    cout << "��" << ++times << "��:";
    stoneHeap[start] += stoneHeap[divp];
    nextHeap[start] = nextHeap[divp];
    if (divp == start_point) start_point = nextHeap[start];
    prStoneHeap();
    std::cout << "   �÷�:" << stoneSum(start, end) << std::endl;
}

void output() {
    stoneHeap = new int[len];
    nextHeap = new int[len];

    //�ҵ��ܷ���������С�ķֶ����
    int max, min, start_min(0), start_max(0), temp;
    max = allStoneGrade[0][-1 + len].whilemax,
    min = allStoneGrade[0][-1 + len].whilemin;
    for (int start(1); start < len; ++start) {
        (temp = allStoneGrade[start][start - 1].whilemax) > max &&
            (max = temp, start_max = start);
        (temp = allStoneGrade[start][start - 1].whilemin) < max &&
            (min = temp, start_min = start);
    }
    //�����������ģ��
    memcpy(stoneHeap, stone, len * sizeof(len));
    for (int i(0); i < len; ++i) {
        nextHeap[i] = i + 1;
    }
    nextHeap[len - 1] = 0;
    times = score = 0;
    start_point = start_max;
    cout << "��ʼ��";
    prStoneHeap();
    putchar('\n');
    output_(start_point, (start_point - 1 + len) % len, MAX);
    cout << "�ܷ�:" << max << "\n\n";
    //�����С������ģ��
    memcpy(stoneHeap, stone, len * sizeof(len));
    for (int i(0); i < len; ++i) {
        nextHeap[i] = i + 1;
    }
    nextHeap[len - 1] = 0;
    times = score = 0;
    start_point = start_min;
    cout << "��ʼ:";
    prStoneHeap();
    putchar('\n');
    output_(start_min, (start_min - 1 + len) % len, MIN);
    cout << "�ܷ�:" << min << std::endl;

    delete stoneHeap;
    delete nextHeap;
}
