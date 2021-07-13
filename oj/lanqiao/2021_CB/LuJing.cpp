#include <bits/stdc++.h>
using namespace std;

const int gap = 21;

int dp[2100];

int mgbs(int a, int b) {
    return a * b / __gcd(a, b);
}

int main() {
    for (int i = 2; i <= 2021; ++i) {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= 2021; ++i) {
        for (int g = 1; g <= gap; ++g) {
            if (dp[i + g] > dp[i] + mgbs(i, i + g)) {
                dp[i + g] = dp[i] + mgbs(i, i + g);
            }
        }
    }
    printf("%d", dp[2021]);
    return 0;
}