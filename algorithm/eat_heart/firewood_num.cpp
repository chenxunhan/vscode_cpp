//firewood_num
//cxh
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n & 1) {
            putchar('7');
            --n;
        } else {
            putchar('1');
        }
        --n;
        --n;
        while (n--) {
            --n;
            putchar('1');
        }
        putchar('\n');
    }
    return 0;
}
