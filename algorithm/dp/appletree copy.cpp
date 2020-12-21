
#include <bits/stdc++.h>
using namespace std;

int day, num;

int day_cut(int **root, int day) {
    int i = 1, mx, mxi;
    for (; i <= num; ++i) {
        if (root[0][i] == 0) {
            mx = root[day][i];
            mxi = i;
            break;
        }
    }
    for (++i; i <= num; ++i) {
        if (root[0][i] == 0) {
            mx = max(mx, root[day][i]);
            mxi = i;
        }
    }
    root[0][mxi] = 1;
    return mx;
}

int main() {

    while (~scanf("%d%d", &num, &day)) {
        int root[day + 1][num + 1] = {0};
        int grow[num + 1];
        for (int i = 1; i <= num; ++i) {
            scanf("%d", &root[1][i]);
        }
        for (int i = 1; i <= num; ++i) {
            scanf("%d", &grow[i]);
        }
        for (int i = 2; i <= day; ++i) {
            for (int j = 1; j <= num; ++j) {
                root[i][j] = root[i][j - 1] + grow[j];
            }
        }
        int sum = 0;
        for (int i = day; i >= 1; --i) {
            sum += day_cut(root, i);
        }
        printf("%d\n", sum);
    }
    return 0;
}