#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    ull dp[2], t;
    while (~scanf("%d", &n)) {
        if (n == 1) {
            scanf("%llu", &t);
            printf("%llu\n", t);
            continue;
        }
        scanf("%llu", dp);
        scanf("%llu", dp + 1);
        dp[1] = max(dp[0], dp[1]);
        n -= 2;
        while (n--) {
            scanf("%llu", &t);
            t = max(t + dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = t;
        }
        printf("%llu\n", dp[1]);
    }
    return 0;
}