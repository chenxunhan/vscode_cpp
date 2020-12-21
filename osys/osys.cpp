#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int d, m, y;
    scanf("%d", &n);
    int r[n + 1];
    for (int i = 0; i < n; ++i) {
        scanf("%2d/%2d/%4d", &d, &m, &y);
        r[i] = y * 10000 + m * 100 + d;
    }
    sort(r, r + n);
    putchar('\n');
    for (int i = 0; i < n; ++i) {
        printf("%02d/%02d/%04d\n", r[i] % 100, (r[i] % 10000) / 100, r[i] / 10000);
    }
    return 0;
}