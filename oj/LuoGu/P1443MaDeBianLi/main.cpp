#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400 + 5, MAXM = 400 + 5;
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[] = {2, 2, 1, -1, -2, -2, 1, -1};

queue<pair<int, int>> q; //放着队列
int stepNum[MAXN][MAXM];
bool hasStep[MAXN][MAXM] = {0};

int n, m, x, y; //边界，初始位置
int ox, oy, nx, ny;

//是否在棋盘内
bool isIn(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    memset(stepNum, -1, sizeof(stepNum));
    scanf("%d%d%d%d", &n, &m, &x, &y);
    stepNum[x][y] = 0, hasStep[x][y] = 1;
    q.push(make_pair(x, y)); //make_pair 可以调用生成pair
    while (!q.empty()) {
        ox = q.front().first, oy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            nx = ox + dx[i], ny = oy + dy[i];
            if (isIn(nx, ny) && !hasStep[nx][ny]) {
                stepNum[nx][ny] = stepNum[ox][oy] + 1;
                hasStep[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%-5d", stepNum[i][j]);
        }
        puts("");
    }
    return 0;
}