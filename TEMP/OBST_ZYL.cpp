#include <iostream>
using namespace std;

double m[100][100] = {0};                                                      // m[i][j]表示以从 i 到 j 为一棵二分搜索树的最小平均比较次数
double w[100][100] = {0};                                                      // w[i][j]表示从i到j，节点和空位的概率之和
int lenght = 5;                                                                // 节点个数
char S[100] = {' ', 'A', 'B', 'C', 'D', 'E'};                                  // 表示需要被排序的数据集
double P[200] = {0.04, 0.1, 0.02, 0.3, 0.02, 0.1, 0.05, 0.2, 0.06, 0.1, 0.01}; // 分别交替表示节点和空隙被查找的概率
int root[100][100] = {0};                                                      // root[i][j]用于存放从 i 到 j 构成的二叉树的根节点
double probability_sum(int i, int j) {
    int x = 2 * i - 2;
    int y = 2 * j;
    double sum_w = 0;
    for (; x <= y; x++) {
        sum_w += P[x];
    }
    w[i][j] = sum_w;
    return sum_w;
}

int min(int x, int y) {
    return x > y ? y : x;
}

int main() {

    for (int i = 1; i <= lenght; i++) {
        for (int j = 1; j <= lenght; j++) {
            printf("%.2f ", probability_sum(i, j));
        }
        putchar('\n');
    }

    for (int i = 1; i <= lenght; i++) {
        m[i][i] = probability_sum(i, i);
    }

    for (int i = 2; i <= lenght; i++) {               // 表示 i 个节点形成一棵树
        for (int j = 1; j <= (lenght + 1 - i); j++) { // 表示每i个节点需要求 j 次, 每个 j 下的下标从j开始j+i结束，即需要求j个m[j][j+i]
            int last_index = j + i - 1;
            m[j][last_index] = 32767;
            for (int root_dex = j; root_dex <= last_index; root_dex++) { // 当根节点为root时
                if (root_dex == j) {
                    if (m[j][last_index] > m[root_dex + 1][last_index]) {
                        m[j][last_index] = m[root_dex + 1][last_index]; // 当根节点为当前序列的第一个时
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[root_dex + i][j + i]); // 当根节点为当前序列的第一个时
                    // root[i][last_index] = m[j][last_index] > m[root_dex + i][j + i] ? root[i][last_index] : root_dex;
                } else if (root_dex == last_index) {
                    if (m[j][last_index] > m[j][root_dex - 1]) {
                        m[j][last_index] = m[j][root_dex - 1]; // 当根节点为当前序列的最后一个时
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[j][last_index]); // 当根节点为当前序列的最后一个时
                    // root[i][last_index] = m[j][last_index] > m[j][last_index] ? root[i][last_index] : root_dex;
                } else {
                    if (m[j][last_index] > m[root_dex + 1][last_index] + m[j][root_dex - 1]) {
                        m[j][last_index] = m[root_dex + 1][last_index] + m[j][root_dex - 1];
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[j][root_dex - 1] + m[root_dex + 1][j + i]); // 当根节点不在当前序列的首尾时
                    // root[i][last_index] = m[j][last_index] > (m[j][root_dex - 1] + m[root_dex + 1][j + i]) ? root[i][last_index] : root_dex;
                }
            }
            m[j][last_index] += probability_sum(j, j + i - 1);
        }
    }
    putchar('\n');
    for (int i = 1; i <= lenght; i++) {
        for (int j = 1; j <= lenght; j++) {
            printf("%.2f ", m[i][j]);
        }
        putchar('\n');
    }

    // for(int i = 0; i <= lenght; i++){
    //  printf("%.2f ", probability_sum(i,i));
    // }
    return 0;
}