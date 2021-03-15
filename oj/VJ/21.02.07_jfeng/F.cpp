#include <bits/stdc++.h>
using namespace std;
int n, r;
int a1[1000][1000], a2[1000][1000], b[1000][1000];

bool istran1(int row) {
    // bool re = (a1[row][0] != b[row][0]);
    // for (int i = 1; i < r; ++i) {
    //     if (!(!re && a1[row][i] == b[row][i]) || !(re && a1[row][i] != b[row][i])) {
    //         return 0;
    //     }
    // }
    if (a1[row][0] != b[row][0]) {
        for (int i = 1; i < r; ++i) {
            if (a1[row][i] == b[row][i]) {
                return 0;
            }
        }
    } else {
        for (int i = 1; i < r; ++i) {
            if (a1[row][i] != b[row][i]) {
                return 0;
            }
        }
    }

    return 1;
}
bool istran2(int row) {

    // for (int i = 1; i < r; ++i) {

    if (a2[row][0] != b[row][0]) {
        for (int i = 1; i < r; ++i) {
            if (a2[row][i] == b[row][i]) {
                return 0;
            }
        }
    } else {
        for (int i = 1; i < r; ++i) {
            if (a2[row][i] != b[row][i]) {
                return 0;
            }
        }
    }

    return 1;

    // bool re = (a2[row][0] != b[row][0]);
    // for (int i = 1; i < r; ++i) {
    //     if (!(!re && a2[row][i] == b[row][i]) || !(re && a2[row][i] != b[row][i])) {
    //         return 0;
    //     }
    // }
    // return 1;
}
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &r);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                scanf("%1d", &a1[i][j]);
            }
        }
        for (int i = 0; i < r; ++i) {
            a2[0][i] = !a1[0][i];
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                scanf("%1d", &b[i][j]);
            }
        }
        if (r == 1) {
            printf("YES\n");
            continue;
        }

        //zheng
        for (int i = 0; i < r; ++i) {
            if (a1[0][i] != b[0][i]) {
                for (int j = 0; j < r; ++j) {
                    a1[j][i] ^= 1;
                }
            }
        }
        bool ok = 1;
        for (int i = 1; i < r && ok; ++i) {
            if (!istran1(i)) {
                ok = 0;
                printf("NO\n");
                break;
            }
        }
        if (ok == 0) {
            continue;
        }
        //ni
        for (int i = 0; i < r; ++i) {
            if (a2[0][i] != b[0][i]) {
                for (int j = 0; j < r; ++j) {
                    a2[j][i] ^= 1;
                }
            }
        }
        for (int i = 1; i < r && ok; ++i) {
            if (!istran2(i)) {
                ok = 0;
                printf("NO\n");
                break;
            }
        }
                if (ok == 0) {
            continue;
        }
        printf("YES\n");
    }
    return 0;
}