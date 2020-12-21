#include <cstring>
#include <iostream>
#include <limits.h>
using namespace std;
typedef long long LL;
const int MAX = 2019 + 1;
const LL MOD = INT_MAX;
int prime[MAX], primeNumber;
bool isPrime[MAX];

void eulerSeive(int n) {
    primeNumber = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i <= n; ++i) {
        ((isPrime[i]) && (prime[primeNumber++] = i));
        for (int j = 0; i * prime[j] <= n; ++j) {
            isPrime[i * prime[j]] = 0;
            if (!(i % prime[j]))
                break;
        }
    }
}

int statist(int n) {
    int facNumber = 0;
    for (int i = 0; i < primeNumber; ++i) {
        for (int j = prime[i]; j <= n; j *= prime[i]) {
            ++facNumber;
        }
    }
    return facNumber;
}

LL qpow(LL a, int n, const LL &mod = MOD) {
    if (!a)
        return a;
    LL ans(1);
    while (n)
        ((n & 1) && (ans = ans * a % mod), printf("%lld\n", ans)),
            a = a * a % mod,
            n >>= 1;
    return ans;
}

int main() {
    int n = 2019;
    eulerSeive(n);
    int stat = statist(n);
    printf("%lld\n", stat);
    printf("%lld", qpow(2, stat));
    return 0;
}