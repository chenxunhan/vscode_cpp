#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1000 + 5, MAXM = 100 + 5;

int T, M;
struct Drug {
    int t = 0;
    int v = 0;
} drug[MAXM];

int DP[MAXM][MAXT]; //itemIdx time

int dp(int mi, int ti) {
    if (DP[mi][ti] != -1) {
        return DP[mi][ti];
    }
    if (mi == 0 || ti == 0) {
        return DP[mi][ti] = 0;
    }
    if (ti - drug[mi].t >= 0)
        return DP[mi][ti] = max(dp(mi - 1, ti), dp(mi - 1, ti - drug[mi].t) + drug[mi].v);
    return DP[mi][ti] = dp(mi - 1, ti);
}

void reset() {
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 0; j < MAXT; ++j) {
            DP[i][j] = -1;
        }
    }
}

int main() {
    scanf("%d%d", &T, &M);
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &drug[i].t, &drug[i].v);
    }
    reset();
    printf("%d", dp(M, T));
    return 0;
}