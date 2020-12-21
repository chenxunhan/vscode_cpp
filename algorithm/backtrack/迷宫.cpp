//陈逊瀚递归回溯
#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 7;
int dp[MAXSIZE][MAXSIZE] = {0};
bool walked[MAXSIZE][MAXSIZE] = {0};

int rx[4] = {0, 0, 1, -1};
int ry[4] = {-1, 1, 0, 0};

unsigned long long num;
int ex, ey, sx, sy;
int n, m;
void fc(int x, int y) {
    if (x == ex && y == ey) {
        ++num;
        return;
    } else {
        for (int i = 0; i <= 3; i++) {
            if (walked[x + rx[i]][y + ry[i]] == 0 && dp[x + rx[i]][y + ry[i]] == 1) {
                walked[x][y] = 1;
                fc(x + rx[i], y + ry[i]); //还能优化
                walked[x][y] = 0;
            }
        }
    }
}
int main() {
    while (~scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey)) {
        ++sx, ++sy, ++ex, ++ey;
        num = 0;
        for (int xi = 1; xi <= n; ++xi)
            for (int yi = 1; yi <= m; ++yi)
                scanf("%d", &dp[xi][yi]);
        if (dp[sx][sy]) {
            fc(sx, sy);
            printf("%d\n", num);
        } else
            printf("0\n");
        for (int xi = 1; xi <= n; ++xi)
            for (int yi = 1; yi <= m; ++yi)
                dp[xi][yi] = 0;
    }

    return 0;
}