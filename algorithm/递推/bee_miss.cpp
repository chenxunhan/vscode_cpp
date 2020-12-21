//·ä³²ÃÔ¹¬ µÚ 2765 Ìâ
//³ÂÑ·å«
#include <bits/stdc++.h>
using namespace std;

long long dp[55] = {0};

void set_ans() {
    int i = 0;
    dp[i] = 1;
    while (i <= 50) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
        ++i;
    }
}

int main() {
    set_ans();
    int a, b;
    while (cin >> a >> b) {
        cout << dp[b - a] << endl;
    }
    return 0;
}
