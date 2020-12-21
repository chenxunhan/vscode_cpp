#include <bits/stdc++.h>
using namespace std;

int a[100] = {0};

void printNum(int m) {
    printf("%d", a[0]);
    for (int i = 1; i < m; ++i) {
        printf("+%d", a[i]);
    }
    putchar('\n');
}

void Div(int n, int m) {
    int i;
    if (n == 0) {
        printNum(m);
    } else {
        for (int i = n; i >= 1; --i) {
            if (i <= a[m - 1]) {
                a[m] = i;
                Div(n - i, m + 1);
            }
        }
    }
}

void IntDiv(int n) {
    Div(n, 0);
}

int main() {
    int n;
    //int n, i, m = 0;
    printf("input:");
    while (~scanf("%d", &n)) {
        double time0 = clock();
        IntDiv(n);
        printf("input:");
        printf("%lf", (double) ((clock() - time0) / CLOCKS_PER_SEC));
    }
    return 0;
}