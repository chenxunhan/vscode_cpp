#include <iostream>
using namespace std;

double m[100][100] = {0};                                                      // m[i][j]��ʾ�Դ� i �� j Ϊһ�ö�������������Сƽ���Ƚϴ���
double w[100][100] = {0};                                                      // w[i][j]��ʾ��i��j���ڵ�Ϳ�λ�ĸ���֮��
int lenght = 5;                                                                // �ڵ����
char S[100] = {' ', 'A', 'B', 'C', 'D', 'E'};                                  // ��ʾ��Ҫ����������ݼ�
double P[200] = {0.04, 0.1, 0.02, 0.3, 0.02, 0.1, 0.05, 0.2, 0.06, 0.1, 0.01}; // �ֱ����ʾ�ڵ�Ϳ�϶�����ҵĸ���
int root[100][100] = {0};                                                      // root[i][j]���ڴ�Ŵ� i �� j ���ɵĶ������ĸ��ڵ�
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

    for (int i = 2; i <= lenght; i++) {               // ��ʾ i ���ڵ��γ�һ����
        for (int j = 1; j <= (lenght + 1 - i); j++) { // ��ʾÿi���ڵ���Ҫ�� j ��, ÿ�� j �µ��±��j��ʼj+i����������Ҫ��j��m[j][j+i]
            int last_index = j + i - 1;
            m[j][last_index] = 32767;
            for (int root_dex = j; root_dex <= last_index; root_dex++) { // �����ڵ�Ϊrootʱ
                if (root_dex == j) {
                    if (m[j][last_index] > m[root_dex + 1][last_index]) {
                        m[j][last_index] = m[root_dex + 1][last_index]; // �����ڵ�Ϊ��ǰ���еĵ�һ��ʱ
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[root_dex + i][j + i]); // �����ڵ�Ϊ��ǰ���еĵ�һ��ʱ
                    // root[i][last_index] = m[j][last_index] > m[root_dex + i][j + i] ? root[i][last_index] : root_dex;
                } else if (root_dex == last_index) {
                    if (m[j][last_index] > m[j][root_dex - 1]) {
                        m[j][last_index] = m[j][root_dex - 1]; // �����ڵ�Ϊ��ǰ���е����һ��ʱ
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[j][last_index]); // �����ڵ�Ϊ��ǰ���е����һ��ʱ
                    // root[i][last_index] = m[j][last_index] > m[j][last_index] ? root[i][last_index] : root_dex;
                } else {
                    if (m[j][last_index] > m[root_dex + 1][last_index] + m[j][root_dex - 1]) {
                        m[j][last_index] = m[root_dex + 1][last_index] + m[j][root_dex - 1];
                        root[j][last_index] = root_dex;
                    }
                    // m[j][last_index] = min(m[j][last_index], m[j][root_dex - 1] + m[root_dex + 1][j + i]); // �����ڵ㲻�ڵ�ǰ���е���βʱ
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