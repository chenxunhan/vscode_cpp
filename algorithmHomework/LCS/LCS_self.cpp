#include <bits/stdc++.h>
using namespace std;
const int N(20);
int dp[N][N] = {0};

//2Î¬·¨
void LCS(const string a, const string b, string &res, int &ans) {
    res = "";
    for (int i = 1; i - 1 < a.size(); ++i) {
        for (int j = 1; j - 1 < b.size(); ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (dp[i][j] < min(i, j)) {
                if ((a[i - 1] == b[j - 1])) {
                    dp[i][j] += 1;
                    res += a[i - 1];
                }
            }
        }
    }
    ans = dp[a.size()][b.size()];
}

int main() {
    string a = "abcdefg", b = "aceftaeds";
    string res;
    int ans;
    LCS(a, b, res, ans);
    cout << res << endl
         << ans;
    return 0;
}