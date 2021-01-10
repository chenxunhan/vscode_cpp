#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 5, g = 0;
    // cin >> n;
    while (n--) {
        for (int i = 0; i <= n; ++i)
            printf("%02d", ++g);
        putchar('\n');
    }
    return 0;
}