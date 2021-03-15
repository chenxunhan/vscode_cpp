/*
 UVA #10179 "Irreducible Basic Fractions"[Difficulty: Easy]
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXSIZE = 1e9 + 5;

int prime[100000000]; //放着第i个素数
int primeNum;   //素数个数，也是下标

bool isNotprime[MAXSIZE]; //是不是素数

//欧拉筛
void eulerSieve() {
    primeNum = 0; //下标别忘了初始化
    // memset(isNotprime, 1, sizeof(isNotprime));//数组无法直接{1}初始化全部1
    for (int i = 2; i <= MAXSIZE - 5; ++i) {                                //遍历[i~指定的end]
        if(!isNotprime[i]) prime[primeNum++] = i;                //如果没被筛到,就是素数，记录进去
        for (int j = 0; j < primeNum && i * prime[j] <= MAXSIZE - 5; ++j) { //遍历所有的prime 且 在end筛选范围内
            isNotprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) { //不重复标记，后面再来标记
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
