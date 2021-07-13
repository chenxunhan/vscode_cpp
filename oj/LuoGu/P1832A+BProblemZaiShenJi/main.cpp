#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int prime[MAXN], primeNum(0);
bool isNotPrime[MAXN];
void eulerSieve(int end) {
    for (int i = 2; i <= end; ++i) {
        ((!isNotPrime[i]) && (prime[primeNum++] = i));
        for (int pi = 0; pi < primeNum && i * prime[pi] <= end && ((isNotPrime[i * prime[pi]] = 1), (i % prime[pi])); ++pi)
            ;
    }
}

int n;
long long ans[MAXN] = {1};

int main() {
     n = 200;
    // scanf("%d", &n);
    eulerSieve(n);
    for (int pi = 0; pi < primeNum; ++pi) {
        for (int i = 0; i + prime[pi] <= n; ++i) {
            ans[i + prime[pi]] += ans[i];
        }
    }
    // for (int i = 0; i <= n; ++i)
    //     printf("%d:%lld\n", i, ans[i]);
    printf("%lld\n", ans[n]);
    return 0;
}