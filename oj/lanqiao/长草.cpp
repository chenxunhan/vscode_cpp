#include <bits/stdc++.h>
#include <deque>
using namespace std;
const int N = 1005;
typedef struct
{
    int x, y;
} block;

int n, m, k;
int nowqlen, nextqlen;
bool gra[N][N];
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
queue<block> bls;

bool st(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || gra[x][y] == 1) {
        return false;
    }
    return true;
}

void grow(block b) {
    block nb;
    int x, y;
    for (int i = 0; i < 4; ++i) {
        x = b.x + dx[i], y = b.y + dy[i];
        if (st(x, y)) {
            nb.x = x, nb.y = y;
            ++nextqlen;
            bls.push(nb);
            gra[x][y] = 1;
        }
    }
}

void print() {
    putchar('\n');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf(gra[i][j] ? "g" : ".");
        }
        putchar('\n');
    }
}

int main() {
    memset(gra, 0, sizeof(gra));
    nowqlen = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'g') {
                gra[i][j] = 1;
                ++nowqlen;
                bls.push({i, j});
            }
        }
    }
    scanf("%d", &k);
    while (k--) {
        while (nowqlen--) {
            block b = bls.front();
            bls.pop();
            grow(b);
        }
        nowqlen = nextqlen;
        nextqlen = 0;
    }
    print();
    getchar();
    return 0;
}
