//cxh
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int root_dp[31][31][1001] = {0};
bool cord_dp[31][31][1001] = {0};

int dp(int n, int x, int s) {
    if (n == 1) {
        if (x >= s && s >= 1)
            return 1;
        return 0;
    }
    if (cord_dp[n][x][s] == 1)
        return root_dp[n][x][s];
    int sum = 0;
    for (int i = 1; i <= s - n + 1; ++i) {
        sum += dp(1, x, i) * dp(n - 1, x, s - i);
        sum %= MOD;
    }
    cord_dp[n][x][s] = 1;
    root_dp[n][x][s] = sum;
    return sum;
}

int main() {
    int n, x, s;
    while (~scanf("%d%d%d", &n, &x, &s))
        printf("%d\n", dp(n, x, s));
    return 0;
}