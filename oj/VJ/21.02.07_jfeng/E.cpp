#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;

int t, n, k;
int in;
int eleNum[1005];
int ele[1005];
long long res;

bool cmp(int a, int b) {
    return a > b;
}

int qmi(int a, int k) // 快速幂模板
{
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % MOD;
        a = (LL) a * a % MOD;
        k >>= 1;
    }
    return res;
}

int C(int a, int b) // 通过定理求组合数C(a, b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, --j) {
        res = (LL) res * j % MOD;
        res = (LL) res * qmi(i, MOD - 2) % MOD;
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        memset(eleNum, 0, sizeof(eleNum));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", ele + i);
            ++eleNum[ele[i]];
        }
        sort(ele + 1, ele + n + 1, cmp);
        if (k + 1 <= n && ele[k] == ele[k + 1]) {
            in = 0;
            for (int i = k; ele[i] == ele[k + 1]; --i) {
                ++in;
            }
            printf("%d\n", C(eleNum[ele[k + 1]], in));
        } else {
            printf("%d\n", 1);
        }
    }
    return 0;
}