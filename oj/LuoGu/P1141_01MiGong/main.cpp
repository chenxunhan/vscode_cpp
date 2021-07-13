#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
const int MAXN = 1000 + 5, MAXM = 100000 + 5;
int n, m;
char mg[MAXN][MAXN];
bool hasAns[MAXN][MAXN] = {0};
int realAns[MAXN][MAXN];
bool inRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}
struct Pos {
    int x;
    int y;
} hasStep[MAXN*MAXN];
int hasStepNum;
// vector<Pos> hasStep;
void bfs(int x0, int y0) {
    // hasStep.clear();
    hasStepNum = 0;
    // hasStep.push_back(Pos{x0, y0});
    hasStep[hasStepNum] = Pos{x0, y0};
                ++hasStepNum;
    hasAns[x0][y0] = 1;
    for (int i = 0, x, y; i < hasStepNum /*hasStep.size()*/; ++i) {
        x = hasStep[i].x, y = hasStep[i].y;
        for (int di = 0; di < 4; ++di) {
            if (inRange(x + dx[di], y + dy[di]) &&
                mg[x][y] != mg[x + dx[di]][y + dy[di]] &&
                !hasAns[x + dx[di]][y + dy[di]]) {
                // hasStep.push_back(Pos{x + dx[di], y + dy[di]});
                hasStep[hasStepNum] = Pos{x + dx[di], y + dy[di]};
                ++hasStepNum;
                hasAns[x + dx[di]][y + dy[di]] = 1;
            }
        }
    }
    for (int i = 0, x, y, t = hasStepNum/*hasStep.size()*/; i < t; ++i) {
        x = hasStep[i].x, y = hasStep[i].y;
        realAns[x][y] = t;
    }
}

int ans(int x, int y) {
    if (hasAns[x][y]) {
        return realAns[x][y];
    }
    bfs(x, y);
    return ans(x, y);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", mg[i] + 1);
        // printf("=%s\n", mg[i] + 1);
    }
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        printf("%d\n", ans(x, y));
    }
    return 0;
}