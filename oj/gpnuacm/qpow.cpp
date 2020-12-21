//
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//qpow(a,n), if n_bits[i]==1, then ans*=a^(2^i)
//快速幂原理https://blog.csdn.net/csdnqixiaoxin/article/details/80958620
// ll qpow(ll a, ll n, const ll &mod) {
//     if (!a)
//         return a;
//     ll ans(1);
//     while (n)
//         ((n & 1) && (ans = ans * a % mod)),
//             a = a * a % mod,
//             n >>= 1;
//     return ans;
// }

//递归法求组合数
ll C(ll m, ll n) {
    ll a[m + 1][m + 1];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("[%d][%d]:%d\n", i, j, a[i][j]);
        }
    }
    for (int i = 0; i <= m; ++i) {
        a[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    return a[m][n];
}

int main() {
    ll a, b;
    a = 5, b = 2;
    cout << a << " " << b << endl;
    cout << C(a, b) << endl;

    return 0;
}