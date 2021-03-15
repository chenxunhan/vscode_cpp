#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[55];
    bool used[55];
    int res;
    scanf("%d", &t);
    while (t--) {
        memset(used, 0, sizeof(used));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                used[a[j] - a[i]] = 1;
            }
        }
        res = 0;
        for (int i = 0; i < 55; ++i) {
            res += used[i];
        }
        printf("%d\n", res);
    }
    return 0;
}


