#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef double real;

int main() {
    //  freopen("data.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int h1, h2, w;
        real p1, p2;
        scanf("%d%d%d", &h2, &h1, &w);
        scanf("%lf", &p1);
        p2 = 1 - p1;
        h1 = h1 / w + (h1 % w!=0 ? 1 : 0);
        h2 = h2 / w + (h2 % w!=0 ? 1 : 0);
        real ans1 = 0, ans2 = 0, tmp;
        int op = 0;
        for (int i = 0; i < h2; i++) {
            if (i == 0)
                tmp = 1;
            else {
                tmp *= p2;
                tmp = tmp / i * (h1 + i - 1);
            }
            ans1 += tmp * (h1 + i);
            while (op < h1 && (ans1 > 1e15 || tmp > 1e15)) {
                ans1 *= p1;
                tmp *= p1;
                op++;
            }
        }
        while (op < h1) {
            ans1 *= p1;
            op++;
        }
        op = 0;
        for (int i = 0; i < h1; i++) {
            if (i == 0)
                tmp = 1;
            else {
                tmp *= p1;
                tmp = tmp / i * (h2 + i - 1);
            }
            ans2 += tmp * (h2 + i);
            while (op < h2 && (ans2 > 1e15 || tmp > 1e15)) {
                ans2 *= p2;
                tmp *= p2;
                op++;
            }
        }
        while (op < h2) {
            ans2 *= p2;
            op++;
        }
        printf("%.6lf\n", ans2 + ans1);
    }
    return 0;
}