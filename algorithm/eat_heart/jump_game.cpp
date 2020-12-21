//jump game
//cxh
#include <stdio.h>

int main() {
    int n, ok, t;
    int a[105];
    while (~scanf("%d", &n)) {
        ok = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if (ok >= i) {
                t = i + *(a + i);
                ok = ok > t ? ok : t;
            }
        }
        if (ok >= n)
            puts("1");
        else
            puts("0");
    }
    return 0;
}
