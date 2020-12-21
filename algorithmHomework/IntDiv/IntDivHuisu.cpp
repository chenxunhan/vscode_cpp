#include <bits/stdc++.h>
using namespace std;

int main() {
    void IntDiv(int n);
    int n;
    while (~scanf("%d", &n)) {
        double time0 = clock();
        IntDiv(n);
        printf("%lf", (double) ((clock() - time0) / CLOCKS_PER_SEC));
        putchar('\n');
    }
    return 0;
}

int a[100];
void IntDiv(int n) {
    void IntDivf(int p);
    memset(a, 0, 4 * 100);
    printf("%d;\n", a[0] = n);
    IntDivf(0);
}
void IntDivf(int p) {
    void print(int a[], int p);
    if (a[p] > 1) {
        for (int i = p + 2; a[i] != 0; ++i) {
            a[p + 1] += a[i];
            a[i] = 0;
        }
        a[p]--, ++p, ++a[p];
    } else {
        return;
    }
    bool ok = 1;
    for (int pt = 1; pt <= p; ++pt)
        if (a[pt - 1] < a[pt]) {
            ok = 0;
            break;
        }
    if (ok == 1) {
        print(a, p);
        if (a[1] == 1) {
            printf(";\n");
        } else {
            printf(",");
        }
    }
    IntDivf(p);
    --p;

    IntDivf(p);
}
void print(int a[], int p) {
    printf("%d", a[0]);
    int i = 1;
    while (i <= p) {
        printf("+%d", a[i++]);
    }
}
