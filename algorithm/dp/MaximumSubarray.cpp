//
#include <bits/stdc++.h>
using namespace std;

int n;
int num[1001];
int result[1001];
int mx;

void init() {
    mx = result[1] = num[1];
    for (int i = 2; i <= n; ++i) {
        result[i] = max(num[i], num[i] + result[i - 1]);
        mx = max(result[i], mx);
    }
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", num + i);
        }
        init();
        printf("%d\n", mx);
    }
    return 0;
}