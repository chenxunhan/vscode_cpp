//子集 第 2784 题
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int table[600][10];

void arrcat(int *dest, int *sor) {
    while (*sor) {
        *dest = *sor;
        ++dest;
        ++sor;
    }
}

void printarr(int *a) {
    while (*a) {
        printf("%d ", *a);
        ++a;
    }
    putchar('\n');
}

int main() {
    int n;
    int a[9];
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int head = n;
        int pt = 0;
        while (head--) {
            if (head == n - 1) {
                table[pt][0] = a[head];
                ++pt;
            } else {
                int pti = 0, npt = pt;
                for (; pti < pt; ++pti) {
                    table[npt][0] = a[head];
                    arrcat(table[npt] + 1, table[npt] + pti);
                    ++++npt;
                }
                pt = npt;
            }
        }
        while (pt--) {
            printarr(table[pt]);
        }
    }
    return 0;
}