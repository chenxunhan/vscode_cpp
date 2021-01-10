#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 105

int cnt[N], a[N], n, s_len;

bool dfs(int dep) {
    bool Check[N] = {0};
    for (int i = dep - 1; i >= 0; i--) {
        if (2 * a[i] <= a[dep - 1]) break;
        for (int j = i; j >= 0; j--) {
            if (a[i] + a[j] <= a[dep - 1]) break;
            if (a[i] + a[j] > n) continue;
            if (Check[a[i] + a[j]]) continue;
            a[dep] = a[i] + a[j];
            Check[a[dep]] = 1;
            if (a[dep] == n) {
                s_len = dep;
                return 1;
            }
            if (dep + cnt[a[dep]] <= s_len)
                if (dfs(dep + 1)) return 1;
        }
    }
    return 0;
}

int main() {
    while (~scanf("%d", &n) && n) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (x * 2 <= n)
                cnt[i]++, x <<= 1;
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        if (n == 2) {
            printf("1 2\n");
            continue;
        }
        a[1] = 1;
        a[2] = 2;
        s_len = 3;
        while (!dfs(3))
            s_len++;

        for (int i = 1; i <= s_len; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}