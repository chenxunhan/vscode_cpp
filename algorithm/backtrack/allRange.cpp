// 20.9.13
// ���˽�������㷨֮��
// �Լ������ȫ��������
// Ŀ����Ϊ�˽��������������

/*1
#include <bits/stdc++.h>
#define N 5
using namespace std;

int a[N] = {1, 2, 3, 4, 5};
bool dp[N] = {0};
int res[N];
int sumdp() {
    int sum = 0;
    for (bool i : dp) {
        sum += i;
    }
    return sum;
}

void print() {
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    cout << endl;
}

void f(int n) {
    if (sumdp() == N) {
        print();
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (dp[i] == 0) {
            dp[i] = 1;
            res[sumdp() - 1] = a[i];
            f(i);
            dp[i] = 0;
            res[sumdp()] = 0;
        }
    }
}*/

#include <bits/stdc++.h>
#define N 4
using namespace std;

int a[N] = {1, 2, 3, 4}; //׼�����е�����
bool dp[N] = {0};        //��¼�����Ƿ��ù�
int res[N];              //��¼��ǰѡ���������������
int sumdp = 0;           //��¼��ǰѡ���ù��������ж��ٸ�

void print() { //�����res
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    cout << endl;
}

void f(int n) {       //n��ָa[]�е�ָ�����ֵ��±꣬���ǵ�ǰѡ�����ֵ��±�
    if (sumdp == N) { //����Ѿ�ѡ����ȫ�������֣������
        print();
        return;
    }
    for (int i = 0; i < N; ++i) { //һ��һ��ѡ��ȥ����ͼ����õ�https://www.cnblogs.com/blogtech/p/12295551.html
        if (!dp[i]) {             //û��ѡ���Ļ�����ʼѡ
            dp[i] = 1;
            res[sumdp] = a[i];
            ++sumdp;
            f(i);      //�������
            dp[i] = 0; //�˳�����ʱ����ѡ��
            --sumdp;
            res[sumdp] = 0;
        }
    }
}

int main() {
    f(0);
    return 0;
}