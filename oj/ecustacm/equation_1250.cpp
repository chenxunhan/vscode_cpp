#include <bits/stdc++.h>
using namespace std;

int n;
bool has;
int main() {
    while (~scanf("%d", &n)) {
        has = 0;
        for (int a = 1; a * a <= n; ++a) {
            int bt = n - a * a;
            for (int b = 1; b * b <= bt; ++b) {
                for (int c = 1; c * c <= (bt - b * b); ++c) {
                    if (a * a + b * b + c * c == n & a <= b & b <= c) {
                        has = 1;
                        printf("%d %d %d\n", a, b, c);
                    }
                }
            }
        }
        if (has == 0) {
            printf("No Solution\n");
        }
    }

    return 0;
}