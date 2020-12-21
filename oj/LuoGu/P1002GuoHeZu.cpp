#include <bits/stdc++.h>

const int N = 21;

long long table[N][N] = {0};
int n, m;
bool isOut(int x, int y) {
    if (x > n || y > m || x < 0 || y < 0) {
        return 1;
    }
    return 0;
}

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2},
    dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void setHourse(int x, int y) {
    table[x][y] = -1;
    int nx, ny;
    for (int i = 0; i < 8; ++i) {
        nx = x + dx[i], ny = y + dy[i];
        if (!isOut(nx, ny)) {
            table[nx][ny] = -1;
        }
    }
}

bool band(int x, int y) {
    if (table[x][y] == -1) {
        return 1;
    }
    return 0;
}

void dp() {
    if (table[0][0] == -1) {
        return;
    }
    table[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (band(i, j)) {
                continue;
            }
            int nx = i + 1, ny = j;
            if (!isOut(nx, ny) && !band(nx, ny)) {
                table[nx][ny] += table[i][j];
            }
            nx = i, ny = j + 1;
            if (!isOut(nx, ny) && !band(nx, ny)) {
                table[nx][ny] += table[i][j];
            }
        }
    }
}

void print_() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%lld", table[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    n = a, m = b;
    setHourse(c, d);
    // print_();
    dp();
    // print_();
    if (table[n][m] == -1) {
        table[n][m] = 0;
    }
    printf("%lld", table[n][m]);
    return 0;
}