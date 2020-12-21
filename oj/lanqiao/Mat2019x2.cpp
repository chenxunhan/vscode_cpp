#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 2020;
LL dp[2020][2020] = {0}; //安排第1,2行分别有i,j人时已经有多少种可能

int main() {

    int n = 1010;
    dp[0][0] = 1;
    /*
    (i<n):dp[i+1][j]+=dp[i][j];
    (j<i&&j<n):dp[i][j+1]+=dp[i][j];
    */
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            ((i < n) && (dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= MOD));
            ((j < i && j < n) && (dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= MOD));
        }
    }
    printf("%lld", dp[n][n]);
    return 0;
}