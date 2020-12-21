//Â·¾¶ µÚ 2590 Ìâ
//³ÂÑ·å«
#include <bits/stdc++.h>
#define N 31
using namespace std;

int m, n;
int path[N][N] = {0};
int dp[N][N] = {0};

int set_dp(int i, int j) {
    if (path[i][j] == 1) {
        return 0;
    }
    dp[1][1] = 1;
    if (dp[i][j]) {
        return dp[i][j];
    }
    if (i == 1) {
        dp[i][j] += set_dp(i, j - 1);
        return dp[i][j];
    }
    if (j == 1) {
        dp[i][j] += set_dp(i - 1, j);
        return dp[i][j];
    }
    dp[i][j] = set_dp(i - 1, j) + set_dp(i, j - 1);
    return dp[i][j];
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> path[i][j];
        }
    }
    cout << set_dp(m, n);
    return 0;
}
