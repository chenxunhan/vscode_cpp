#include <bits/stdc++.h>
using namespace std;

// dp[i][j]=dp[i-1][j]+dp[i][j-1]

int dp[2][10] = {0};
int n = 5;
int main() {
    //i
    for (int i = 0; i < n; ++i) { //左列上行全是1
        dp[0][i] = dp[i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
            printf("%4d", dp[i & 1][j]);
        }
        putchar('\n');
    }
    return 0;
}