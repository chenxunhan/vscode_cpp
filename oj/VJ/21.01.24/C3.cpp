#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 5000 + 5;
int n, m;
char mat[MAXSIZE];
int dp[MAXSIZE][MAXSIZE] = {0}; //roll
int res = 0;

inline bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", mat + 1);
        for (int j = 1; j <= m; ++j) {
            // scanf("%1d", mat);
            ((mat[j] == '1') && (dp[j][i] = dp[j - 1][i] + 1));
        }
    }
    for (int j = 1; j <= m; ++j) {
        sort(dp[j] + 1, dp[j] + 1 + n, cmp);
        for (int i = 1; i <= n && dp[j][i]; ++i) {
            // res = max(res, dp[j][i] * i);
            if (res < dp[j][i] * i) {
                res = dp[j][i] * i;
            }
        }
    }
    printf("%d", res);
    return 0;
}
