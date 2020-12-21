//del_again_num.cpp
//cxh
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAX = 1001;
    bool note[MAX];
    int n, t;
    while (~scanf("%d", &n)) {
        memset(note, 0, MAX);
        while (n--) {
            scanf("%d", &t);
            if (*(note + t)) {
                continue;
            }
            *(note + t) = 1;
            printf("%d ", t);
        }
        putchar('\n');
    }
    return 0;
}
