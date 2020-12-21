//疯狂三角形 第 2767 题
//陈逊瀚
#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
typedef unsigned long long ull;

ull qpow2(ull n) {
    ull a = 2, ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

int main() {
    int t;
    //t = 1;
    ull n;
    cin >> t;
    while (t--) {
        scanf("%lld", &n);
        //n = 1;
        n = qpow2(n);
        printf("%llu\n", (n * (1 + n) / 2) % 1000000007);
    }
    return 0;
}
