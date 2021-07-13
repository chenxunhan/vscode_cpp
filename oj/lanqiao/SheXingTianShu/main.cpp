#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int table[5][5];
int ans = 0;
void clearTable() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            table[i][j] = 0;
        }
    }
}
void disp() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            printf("%3d", table[i][j]);
        }
        puts("");
    }
    puts("");
}
bool isInRan(int x, int y) {
    return 1 <= x && x <= 4 && 1 <= y && y <= 4;
}
void dfs(int x, int y, int step) {
    table[x][y] = step;
    if (step == 16) {
        disp();
        ++ans;
        return;
    }
    for (int di = 0; di < 5; ++di) {
        int nx = x + dx[di], ny = y + dy[di];
        if (!isInRan(nx, ny))
            continue;
        if (table[nx][ny] == 0) {
            dfs(nx, ny, step + 1);
            table[nx][ny] = 0;
        }
    }
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            clearTable();
            dfs(i, j, 1);
        }
    }
    printf("%d", ans);
    return 0;
}