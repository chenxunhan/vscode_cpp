#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[55];
bool b[55]; //not chou mi

int Min = INT_MAX;
int res, notok;

bool isok(int a, int b) {
    return max(a, b) <= 2 * min(a, b);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        res = notok = 0;
        scanf("%d", &n);
        scanf("%d", &a[0]);
        for (int i = 1; i < n; ++i) {
            scanf("%d", a + i);
            if (!isok(a[i - 1], a[i])) {
                ++notok;
                int mn = min(a[i], a[i - 1]), mx = max(a[i], a[i - 1]);
                while (mn * 2 < mx) {
                    mn *= 2;
                    ++res;
                }
            }
        }
        if (notok == 0) {
            printf("0\n");
        } else
            printf("%d\n", res);
    }
    return 0;
}