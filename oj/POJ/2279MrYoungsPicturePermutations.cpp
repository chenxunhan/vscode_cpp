#include <cstring>
#include <stdio.h>
using namespace std;

const int MAXSIZE = 150 + 1;
const int MaxRowNumber = 5 + 1;
const int MaxeachRowPeoNum = 30 + 1;

int rowNumber;
int eachRowPeoNum[MaxRowNumber];
int prime[MAXSIZE], primeNumber;
bool isPrime[MAXSIZE];
int primeFactorNumber[MAXSIZE];

void eulerSieve(int primeMax) {
    primeNumber = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int b = 2; b <= primeMax; ++b) {
        ((isPrime[b]) && (prime[primeNumber++] = b));
        for (int i = 0; /*i < primeNumber && */ b * prime[i] <= primeMax; ++i) {
            isPrime[prime[i] * b] = 0;
            if (!(b % prime[i]))
                break;
        }
    }
}

int FacPrimeFactorNum(int n, int p) {
    int res = 0;
    while (n) {
        n /= p;
        res += n;
    }
    return res;
}



int main() {
    while (scanf("%d", &rowNumber) && rowNumber) {
        for (int i = 1; i <= rowNumber; ++i) {
            scanf("%d", eachRowPeoNum + i);
            // printf(">%d", N[i]);
        }

    
    }
    return 0;
}

// int k;                                     //有多少排
// int N[6] = {0};                            //第i排应该站多少人
// unsigned int dp[31][31][31][31][31] = {0}; //
// int main() {
//     while (scanf("%d", &k) && k) {
//         memset(dp, 0, sizeof(dp));
//         memset(N, 0, sizeof(N));
//         dp[0][0][0][0][0] = 1;
//         for (int i = 1; i <= k; ++i) {
//             scanf("%d", N + i);
//             // printf(">%d", N[i]);
//         }
//         for (int a1 = 0; a1 <= N[1]; ++a1) {
//             for (int a2 = 0; a2 <= N[2]; ++a2) {
//                 for (int a3 = 0; a3 <= N[3]; ++a3) {
//                     for (int a4 = 0; a4 <= N[4]; ++a4) {
//                         for (int a5 = 0; a5 <= N[5]; ++a5) {
//                             ((a1 < N[1]) && (dp[a1 + 1][a2][a3][a4][a5] += dp[a1][a2][a3][a4][a5]));
//                             ((a2 < N[2] && a2 < a1) && (dp[a1][a2 + 1][a3][a4][a5] += dp[a1][a2][a3][a4][a5]));
//                             ((a3 < N[3] && a3 < a2) && (dp[a1][a2][a3 + 1][a4][a5] += dp[a1][a2][a3][a4][a5]));
//                             ((a4 < N[4] && a4 < a3) && (dp[a1][a2][a3][a4 + 1][a5] += dp[a1][a2][a3][a4][a5]));
//                             ((a5 < N[5] && a5 < a4) && (dp[a1][a2][a3][a4][a5 + 1] += dp[a1][a2][a3][a4][a5]));
//                         }
//                     }
//                 }
//             }
//         }
//         printf("%u\n", dp[N[1]][N[2]][N[3]][N[4]][N[5]]);
//         /*
//         i:第几个人
//         dp[0][0][0][0][0]=1;
//          a1<N[1] dp[a1+1][a2][a3][a4][a5]+=dp[a1][a2][a3][a4][a5]
//          else a2~a5
//          a2<a1 && a2<N[2] dp[a1][a2+1][a3][a4][a5]+=dp[a1][a2][a3][a4][a5]
//         */
//     }

//     return 0;
// }