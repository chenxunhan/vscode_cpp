#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x, y;
};
const int MAX = 21;
int peanut[MAX][MAX] = {0};

int M, N, K;
int maxGetNum = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isOutRange(Pos p) {
    if (p.x < 0 || p.y < 1 || p.x > M || p.y > N) {
        return 1;
    }
    return 0;
}

void BFS(Pos pos, int hasPastTime, int hasGetNum) {
    if (K - hasPastTime < pos.y) {
        return;
    }
    if (hasPastTime >= K) {
        if (pos.x == 0) {
            if (hasGetNum > maxGetNum) {
                maxGetNum = hasGetNum;
            }
        }
        return;
    }
    for (int di = 0; di < 4; ++di) {
        if (!isOutRange({pos.x + dx[di], pos.y + dy[di]})) {
            BFS({pos.x + dx[di], pos.y + dy[di]}, hasPastTime + 1, hasGetNum);
        }
    }
    if (peanut[pos.x][pos.y] == 0) {
        return;
    }
    int nextHasGetNum = hasGetNum + peanut[pos.x][pos.y];
    int savePeanut = peanut[pos.x][pos.y];
    peanut[pos.x][pos.y] = 0;
    BFS(pos, hasPastTime + 1, nextHasGetNum);
    peanut[pos.x][pos.y] = savePeanut;
}

int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &peanut[i][j]);
        }
    }
    for (int inity = 1; inity <= N; ++inity) {
        BFS({0, inity}, 0, 0);
    }
    printf("%d", maxGetNum);
    return 0;
}