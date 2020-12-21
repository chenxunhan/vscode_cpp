#include <bits/stdc++.h>
using namespace std;

int mat[82][82];
int n, m;
int head[82], tail[82];



int operator^(const int &a, const int &b) {
    return pow(a, b);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        head[i] = 1, tail[i] = m;
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    unsigned long long res = 0;
    for (int mi = 1; mi <= m; ++mi) {
        for (int ni = 1; ni <= n; ++ni) {
            if (mat[ni][head[ni]] < mat[ni][tail[ni]]) {
                res += mat[ni][head[ni]] * pow(2, mi);
                ++head[ni];
            } else {
                res += mat[ni][tail[ni]] * pow(2, mi);
                --tail[ni];
            }
        }
    }
    printf("%llu", res);
    return 0;
}