/*
 UVA #10179 "Irreducible Basic Fractions"[Difficulty: Easy]
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXSIZE = 1e9 + 5;

int prime[100000000]; //���ŵ�i������
int primeNum;   //����������Ҳ���±�

bool isNotprime[MAXSIZE]; //�ǲ�������

//ŷ��ɸ
void eulerSieve() {
    primeNum = 0; //�±�����˳�ʼ��
    // memset(isNotprime, 1, sizeof(isNotprime));//�����޷�ֱ��{1}��ʼ��ȫ��1
    for (int i = 2; i <= MAXSIZE - 5; ++i) {                                //����[i~ָ����end]
        if(!isNotprime[i]) prime[primeNum++] = i;                //���û��ɸ��,������������¼��ȥ
        for (int j = 0; j < primeNum && i * prime[j] <= MAXSIZE - 5; ++j) { //�������е�prime �� ��endɸѡ��Χ��
            isNotprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) { //���ظ���ǣ������������
                break;
            }
        }
    }
}

int main() {
    int n;
    int quitNum;
    eulerSieve();

    while (scanf("%d", &n) && n) {
        quitNum = 0;
        
        for (int i=0; prime[i] * prime[i] <= n; ++i) {
            if (n % prime[i] == 0) {
                quitNum += n / prime[i] - 1;
            }
        }
        printf("%d\n", n - quitNum);
    }
    return 0;
}
