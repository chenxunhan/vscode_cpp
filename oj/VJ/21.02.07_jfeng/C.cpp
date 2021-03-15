#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 5;
int t, a, b, k;
int boy[SIZE], girl[SIZE];
long long res;

bool ok(int b1, int g1, int b2, int g2) {
    return ((b1 != b2) && (g1 != g2));
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", boy + i);
        }
        for (int i = 1; i <= k; ++i) {
            scanf("%d", girl + i);
        }
        res = 0;
        for (int i = 1; i <= k - 1; ++i) {
            for (int j = i + 1; j <= k; ++j) {
                res += ok(boy[i], girl[i], boy[j], girl[j]);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}