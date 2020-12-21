#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n;
struct W {
    int no;
    int wei;
} w[1005];

struct S {
    int no;
    int size;
} s[1005];
// int w[1005], s[1005];

bool wcmp(W a, W b) {
    return a.wei <= b.wei;
}
bool scmp(S a, S b) {
    return a.size >= b.size;
}

int comres[1005][1005] = {0};
char bj[1005][1005] = {0};
void getres() {
    // int idx
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (w[i].no == s[j].no) {
                comres[i][j] = comres[i - 1][j - 1] + 1;
                bj[i][j] = 'x';
                continue;
            }
            if (comres[i - 1][j] >= comres[i][j - 1]) {
                comres[i][j] = comres[i - 1][j];
                bj[i][j] = 's';
                continue;
            }
            comres[i][j] = comres[i][j - 1];
            bj[i][j] = 'z';
        }
    }
}

void printRes(const int &a, const int &b) {
    if (!a || !b) {
        return;
    }
    switch (bj[a][b]) {
    case 'z':
        printRes(a, b - 1);
        break;
    case 's':
        printRes(a - 1, b);
        break;
    default:
        printRes(a - 1, b - 1);
        printf("%d\n", w[a].no);
        break;
    }
}

int main() {
    n = 1;
    while (~scanf("%d%d", &w[n].wei, &s[n].size)) {
        w[n].no = s[n].no = n;
        ++n;
    }
    sort(w + 1, w + n, wcmp);
    sort(s + 1, s + n, scmp);
    --n;
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d ", w[i].no);
    // }
    // putchar('\n');
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d ", s[i].no);
    // } 
    getres();
    printf("%d\n", comres[n][n]);
    printRes(n, n);
    return 0;
}