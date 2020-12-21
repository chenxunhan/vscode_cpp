//×ßÂ¥ÌÝ µÚ 2766 Ìâ
//³ÂÑ·å«
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 100003
using namespace std;
int dp[MAX];
int main() {
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
        memset(dp, 0, 4 * MAX);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            if (i <= k)
                dp[i] = dp[i - 1] * 2 % MOD;
            else
                dp[i] = (dp[i - 1] * 2 - dp[i - k - 1]) % MOD;
        cout << (dp[n] + MOD) % MOD << endl;
    }
    return 0;
}