#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6 + 5;

int n, t;
bool ok[SIZE];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        if (t % 2020 <= t / 2020) {
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}

// newele = 2020 * beishu + yushu
 yushu <= beishu

newele =2020+2020+2020+2021+2021
        =2020+2020+2020+2020+2020+1+1
        [2020*n,2020*n+(<=n))]