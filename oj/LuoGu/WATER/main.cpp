#include <bits/stdc++.h>
using namespace std;

// void print_x(int n) {
//     if (n) {
//         printf("x^%d", n);
//     }
// }

void print_x(int a, int b, bool sg) {

    if (a) {
        if (a > 0) {
            if (sg)
                printf("+");
            if (a == 1) {
                if (b == 0) {
                    printf("%d", a);
                } else if (b) {
                    if (b == 1) {
                        printf("x");
                    } else if (b != 1)
                        printf("x^%d", b);
                }
            } else if (a != 1) {
                if (b == 0) {
                    printf("%d", a);
                } else if (b) {
                    printf("%d", a);

                    if (b == 1) {
                        printf("x");
                    } else if (b != 1)
                        printf("x^%d", b);
                }
            }
        } else if (a < 0) {
            if (a == -1) {
                if (b == 0) {
                    printf("%d", a);
                } else if (b) {
                    if (b == 1) {
                        printf("-x");
                    } else if (b != 1)
                        printf("-x^%d", b);
                }
            } else if (a != -1) {
                if (b == 0) {
                    printf("%d", a);
                } else if (b) {
                    printf("%d", a);
                    if (b == 1) {
                        printf("x");
                    } else if (b != 1)
                        printf("x^%d", b);
                }
            }
        }
    }
}
int n;
int t[105];
// bool all0() {
//     for (int i = 0; i <= n; ++i) {
//         if (t[i]) {
//             return 0;
//         }
//     }
//     return 1;
// }
int main() {

    cin >> n;
    for (int i = 0; i <= n; ++i) {
        scanf("%d", t + i);
    }
    // if (all0()) {
    //     printf("0");
    //     return 0;
    // }
    for (int i = 0; i <= n; ++i) {
        print_x(t[i], n - i, i);
    }
    return 0;
}