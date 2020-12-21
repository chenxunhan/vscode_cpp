#include <bits/stdc++.h>
#define N 50 //����������������
using namespace std;

int n; //ȫ�ֱ������������ľ���������

//m[i][j]��Ϊ��������¼��������� Ai A(i+1)...A(j-1) Aj ����С�������
//s[i][j]��Ϊ��Ǻ������������ Ai A(i+1)...A(j-1) Aj �����һ�ηָ�λ��
int m[N][N], s[N][N];

//l[i]��������� A1 A2 A3...An �ĵ�i���ո�λ��Ӧ����l[i]�� ������(,����i��0��ʼ����
//r[i]��������� A1 A2 A3...An �ĵ�i���ո�λ��Ӧ����r[i]�� ������),����i��0��ʼ����
int l[N], r[N];

//P[]�������������,n���������ľ���������
//���������������¼����Ǻ������𰸱��ʽ�Լ��������������ٴ���
void RecurMatrixChain(int P[]) {
    //��������¼�ͱ�Ǻ������
    memset(m, 0, sizeof(m)), memset(s, 0, sizeof(s));
    //������m[i][i]��ֵΪ0,s[i][i]Ϊi,1<=i<=n,��Ҳ�Ǿ���������Ϊ1�����
    for (int i = 1; i <= n; ++i)
        m[i][i] = 0, s[i][i] = i;
    //lenΪ��ǰ���������(�������ģ)
    for (int len = 2; len <= n; ++len) {
        //n-len+1Ϊ���һ��len����ǰ�߽�
        for (int idx1 = 1; idx1 <= n - len + 1; ++idx1) {
            //����ǰ�߽�Ϊidx1,��Ϊlen���ľ�������߽�idx2
            int idx2 = idx1 + len - 1;
            m[idx1][idx2] = INT_MAX;                 //���õ�ǰ�����������С�������Ϊ�����
            for (int k = idx1; k <= idx2 - 1; ++k) { //����
                int now = m[idx1][k] +
                          m[k + 1][idx2] +
                          P[idx1 - 1] * P[k] * P[idx2]; //����λ��(Aidx1 ... Ak)(Ak+1 ... Aidx2)
                if (m[idx1][idx2] > now) {
                    m[idx1][idx2] = now, s[idx1][idx2] = k; //�ø��õ�ֵ�滻
                }
            }
        }
    }
}

//�����������¼m[][]
void printm() {
    printf("��������¼:\n  m:");
    for (int i = 1; i <= n; ++i) {
        printf("    [%2d]", i);
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i) {
        printf("[%2d]", i);
        for (int j = 1; j <= n; ++j) {
            printf("%8d", m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//�����Ǻ���s[][]
void prints() {
    printf("  ��Ǻ���:\n  s:");
    for (int i = 1; i <= n; ++i) {
        printf("    [%2d]", i);
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i) {
        printf("[%2d]", i);
        for (int j = 1; j <= n; ++j) {
            printf("%8d", s[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//�ú������n���ַ�c
void printChar(char c, int n) {
    while (n--)
        putchar(c);
}

//����innerlrΪ������ Aa A(a+1)...A(b-1) Ab ���ʽ��ǰ�����˼�������()
//�����ñ�Ǻ����ھ��������ڲ��ָ�����ݹ��������
//�����(���Żᱣ����l[]��,�����)���Żᱣ����r[]��
//l[i]��������� A1 A2 A3...An �ĵ�i���ո�λ��Ӧ����l[i]��(,����i��0��ʼ����
//r[i]��������� A1 A2 A3...An �ĵ�i���ո�λ��Ӧ����r[i]��),����i��0��ʼ����
void innerlr(int a, int b) {
    if (a == b) //�ݹ���ֹ����:���������ĳ���Ϊ1ʱ���������Ų��˳�����
        return;
    ++l[a], ++r[b + 1];      //Ϊ��������ǰ�����˼�������()
    innerlr(a, s[a][b]);     //Ϊ�������ָ�λ��ǰ�������˼�������()���ݹ�
    innerlr(s[a][b] + 1, b); //Ϊ�������ָ�λ�ú󲿷����˼�������()���ݹ�
}

//����������ŵľ������𰸱��ʽ
void printres() {
    //��վ�������λ������Ҫ�������ź���������Ŀ
    memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));

    //��һ��ʹ��innerlr�����������ľ��������˲���Ҫ�ؼ�������
    //�����Ҫ�����ôβ���,��������Ҫ���������������Ŀ����Ϊ-1
    l[1] = r[n + 1] = -1;
    innerlr(1, n);

    printf("�����������ŵı��ʽ��:");
    for (int i = 1; i <= n; ++i) { //����ÿ��λ��
        printChar(')', r[i]);      //�����λ������Ҫ��������)��Ŀ
        printChar('(', l[i]);      //�����λ������Ҫ��������(��Ŀ
        printf("A%d", i);          //�����λ�õľ���Ai
    }
    printChar(')', r[n + 1]); //���ĩ��λ������Ҫ��������)��Ŀ
    printf("\n�����������:%d\n\n", m[1][n]);
}

void printP(int P[]) {
    printf("P<");
    for (int i = 0; i < n; ++i) {
        printf("%d,", P[i]);
    }
    printf("%d>\n\n", P[n]);
}

int main() {
    // int n0 = 2, P[] = {30, 35, 15};
    // int n0 = 5, P[] = {30, 35, 15, 5, 10, 20};
    int n0 = 6, P[] = {20, 70, 25, 30, 5, 35, 10};
    n = n0;              //��ֵȫ�ֱ������������ľ���������,�����������ʹ��
    printP(P);           //����������������P
    RecurMatrixChain(P); //������������
    printm();            //�������¼
    prints();            //�����Ǻ���
    printres();          //�����
    return 0;
}