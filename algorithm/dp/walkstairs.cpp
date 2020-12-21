//walkstairs.cpp
#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[91];

void init() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 90; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    int n;
    init();
    while (~scanf("%d", &n)) {
        printf("%llu\n", dp[n]);
    }
    return 0;
}