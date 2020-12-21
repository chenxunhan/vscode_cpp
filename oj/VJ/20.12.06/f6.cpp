#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
int n, a, b;
ull v[55];

bool cmp(ull a, ull b) {
    return a > b;
}

double ex() {
    double sum = 0;
    for (int i = 0; i < a; ++i) {
        sum += v[i];
    }
    return sum / a;
}

int findIn(int t) {
    int c = 1;
    for (int i = a - 2; i >= 0 && v[i] == v[i + 1]; --i) {
        // c += (v[i] == t);
        ++c;
    }
    return c;
}

int findNotIn(int t) {
    int c = 0;
    for (int i = a; i < n && v[i] == v[i - 1]; ++i) {
        ++c;
    }
    return c;
}

ull c[55][55] = {0};
ull C(int m, int n) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
    return c[m][n];
}

int main() {
    // for (int i = 0; i <= 50; ++i) {
    //     printf("C(%d,%d)=%llu\n", 50, i, C(50, i));
    // }
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%llu", v + i);
    }
    sort(v, v + n, cmp);
    printf("%.6lf\n", ex());
    if (v[0] == v[a - 1]) {
        ull res = 0;
        for (int i = a; i <= b; ++i) {
            res += C(findIn(v[i - 1]) + findNotIn(v[i - 1]), i);

            // printf("C(%d,%d)=%d\n", findIn(v[i - 1]) + findNotIn(v[i - 1]), findIn(v[i - 1]), C(findIn(v[i - 1]) + findNotIn(v[i - 1]), findIn(v[i - 1])));
        }
        printf("%llu", res);
    } else
        printf("%llu", C(findIn(v[a - 1]) + findNotIn(v[a - 1]), findIn(v[a - 1])));
    return 0;
}