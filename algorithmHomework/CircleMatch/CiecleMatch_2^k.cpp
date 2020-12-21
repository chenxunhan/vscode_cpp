#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[9][9];
    int n = 1, i;
    for (int i = 1; i <= 3; ++i)
        n *= 2;
    for (i = 1; i <= n; ++i)
        a[1][i] = i;
    int m = 1;
    for (int s = 1; s <= 3; ++s) {
        n /= 2;
        for (int t = 1; t <= n; ++t)
            for (i = m + 1; i <= 2 * m; ++i)
                for (int j = m + 1; j <= 2 * m; ++j) {
                    a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m];
                    a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2];
                }
        m *= 2;
    }
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}