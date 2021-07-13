#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        ((t > m) && (m = t));
    }
    printf("%.9lf", double(m));
    return 0;
}