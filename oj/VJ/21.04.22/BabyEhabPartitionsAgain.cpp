#include <bits/stdc++.h>
using namespace std;
int n, a[105];

int sum() {
    int r = 0;
    for (int i = 1; i <= n; ++i)
        r += a[i];
    return r;
}

int jiPos() {
    for (int i = 1; i <= n; ++i)
        if (a[i] & 1)
            return i;
    return n;
}

bool solve() {
    //ji
    if (sum() & 1) {
        puts("0");
        return 1;
    }
    //ou
    int jipos = jiPos();
    if (jipos != n) {
        printf("1\n%d", jipos);
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    while (!solve())
        for (int i = 1; i <= n; ++i)
            a[i] >>= 1;
    return 0;
}
