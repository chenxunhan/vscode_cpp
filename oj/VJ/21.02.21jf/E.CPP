#include <bits/stdc++.h>
using namespace std;

const long long SIZE = 2 * 1e5 + 5;

long long t, n, win;
struct Peo {
    long long idx;
    long long val;
} peo[SIZE];
long long bSum[SIZE] = {0};
long long oval[SIZE] = {0};

bool cmp(Peo a, Peo b) {
    return a.val < b.val;
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &peo[i].val);
            peo[i].idx = i;
            oval[i] = peo[i].val;
            bSum[i] = 0;
        }
        sort(peo + 1, peo + n + 1, cmp);
        win = 1;
        // memset(bSum, 0, sizeof(bSum));
        for (int i = 1; i < n; ++i) {
            bSum[i] += peo[i].val + bSum[i - 1];
            if (bSum[i] < peo[i + 1].val) {
                win = i + 1;
            }
        }
        printf("%lld\n", n - win + 1);
        for (int i = 1; i <= n; ++i) {
            if (oval[i] >= peo[win].val) {
                printf("%lld ", i);
            }
        }
        putchar('\n');
    }
    return 0;
}