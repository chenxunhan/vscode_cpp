//统计阶乘质因子的数目
/*
要求：
给定n，创建小于n的所有素数存放的数组prime[]，再创建primeFactorNumber[]存放n的第i个质因数的个数
*/

#include <cstring>
#include <stdio.h>
using namespace std;

const int MAXSIZE = 10000;

int prime[MAXSIZE], primeNumber;
bool isPrime[MAXSIZE];
int primeFactorNumber[MAXSIZE];

void eulerSieve(int primeMax) {
    primeNumber = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int b = 2; b <= primeMax; ++b) {
        ((isPrime[b]) && (prime[primeNumber++] = b));
        for (int i = 0;/*i < primeNumber && */b * prime[i] <= primeMax; ++i) {
            isPrime[prime[i] * b] = 0;
            if (!(b % prime[i]))
                break;
        }
    }
}

void statist(int facNum,int prime_) {
    memset(primeFactorNumber, 0, sizeof(primeFactorNumber));
    for (int i = 0; i < primeNumber; ++i) {
        for (int bi = prime[i]; bi <= facNum; bi *= prime[i]) {
            primeFactorNumber[i] += facNum / bi;
        }
    }
}

int main() {
    int n = 10;
    printf("n:%d\n", n);
    eulerSieve(n);
    statist(n);
    for (int i = 0; i < primeNumber; ++i) {
        printf("i:%d,p:%d,n:%d\n", i, prime[i], primeFactorNumber[i]);
    }
    return 0;
}