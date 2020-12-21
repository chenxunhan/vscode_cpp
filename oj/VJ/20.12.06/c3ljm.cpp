#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int w, s, n, c;
} m[1005];

bool cmp(Node a, Node b) {
    return a.w < b.w;
}

int main() {
    int cnt = 0;
    vector<int> v[1005];
    while (scanf("%d%d", &m[cnt].w, &m[cnt].s))
        m[cnt].n = cnt, ++cnt;

    sort(m, m + cnt, cmp);

    m[0].c = 1;
    for (int i = 1; i < cnt; ++i) {
        int mxcnt = 1, mxidx = i;
        for (int j = i - 1; j >= 0; --j)
            if (m[j].s > m[j].)
    }
}