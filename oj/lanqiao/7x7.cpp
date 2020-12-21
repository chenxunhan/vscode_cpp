#include <bits/stdc++.h>
using namespace std;

int res;

struct pos {
    int x, y;
};

pos in[15];
// int indx = 0;

void printpos() {
    for (int i = 0; i < 12; ++i) {
        printf("(%d,%d)->", in[i].x, in[i].y);
    }
    putchar('\n');
}

bool table[8][8] = {0};

bool outRange(pos p) {
    if (p.x < 0 || p.y < 0 || p.x > 7 || p.y > 7) {
        return 1;
    }
    return 0;
}

int dx[4] = {0, -1, 0, 1},
    dy[4] = {-1, 0, 1, 0};

void dfs(int step, pos p) { //step[0~11]
    if (outRange(p)) {
        return;
    }
    if (step >= 12) {
        return;
    }
    if (table[p.x][p.y] == 1) {
        return;
    }
    if (step == 11 && p.x == 0 && p.x == p.y) {
        printpos();
        ++res;
        return;
    }

    for (int di = 0; di < 4; ++di) {
        table[p.x][p.y] = 1;
        in[step] = p;
        dfs(step + 1, {p.x + dx[di], p.y + dy[di]});
        table[p.x][p.y] = 0;
    }
}

int main() {
    res = 0;
    dfs(0, {0, 0});
    cout << res;
    return 0;
}