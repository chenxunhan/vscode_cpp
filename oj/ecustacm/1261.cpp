#include <bits/stdc++.h>
using namespace std;

int w, m, n;

int row(int x) {
    return ((--x) / w) + 1;
}

int col(int x) {
    if (!(row(x) & 1)) {
        return w + 1 - (x % w);
    }
    return x % w;
}

int main() {
    while (~scanf("%d%d%d", &w, &m, &n)) {
        printf("%d\n", abs(col(m) - col(n)) + abs(row(m) - row(n)));
    }

    return 0;
}