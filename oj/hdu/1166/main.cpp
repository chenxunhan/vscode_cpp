#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 5e4 + 5;

int caseNum;
int baseNum, base[MAXN], baseTree[MAXN];
char cmd[10];

int lowbit(const int &x) {
    return x & (-x);
}

void updata(int i, const int &k) {
    while (i <= baseNum) {
        baseTree[i] += k;
        i += lowbit(i);
    }
}

int getSum(int i) {
    int res = 0;
    while (i > 0) {
        res += baseTree[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    scanf("%d", &caseNum);
    for (int casei = 1, i, j; casei <= caseNum; ++casei) {
        scanf("%d", &baseNum);
        memset(baseTree, 0, sizeof(baseTree));
        for (int i = 1; i <= baseNum; ++i) {
            // cin >> base[i];
            scanf("%d", base + i);
            updata(i, base[i]);
        }
        printf("Case %d:\n", casei);
        while (scanf("%s", cmd) && cmd[0] != 'E') {
            // cin >> i >> j;
            scanf("%d%d", &i, &j);
            if (cmd[0] == 'Q') {
                printf("%d\n", getSum(j) - getSum(i - 1));
                continue;
            }
            updata(i, (cmd[0] == 'A' ? 1 : -1) * j);
        }
    }
    return 0;
}