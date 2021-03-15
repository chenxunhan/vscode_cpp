#include <bits/stdc++.h>
using namespace std;

const int MAX = 200 + 5;

int n, at, bt;
int aOrder[MAX], bOrder[MAX];
int aScore, bScore;
int aIdx, bIdx;

enum res {
    w = 1,
    l = -1,
    s = 0
};
res table[5][5] = {{s, l, w, w, l},
                   {w, s, l, w, l},
                   {l, w, s, l, w},
                   {l, l, w, s, w},
                   {w, w, l, l, s}};
void process() {
    switch (table[aOrder[aIdx]][bOrder[bIdx]]) {
    case w:
        ++aScore;
        break;
    case l:
        ++bScore;
        break;
    case s:
        break;
    default:
        break;
    }
}

int main() {
    scanf("%d%d%d", &n, &at, &bt);
    for (int i = 1; i <= at; ++i) {
        scanf("%d", aOrder + i);
    }
    for (int i = 1; i <= bt; ++i) {
        scanf("%d", bOrder + i);
    }
    aScore = bScore = 0;
    for (int i = 1; i <= n; ++i) {
        aIdx = (i % at ? i % at : at);
        bIdx = (i % bt ? i % bt : bt);
        process();
    }
    printf("%d %d", aScore, bScore);
    return 0;
}