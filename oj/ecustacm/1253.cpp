#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void dfs(const int pos, const int num) {
    const int im = (4 < 13 - num ? 4 : 13 - num);
    for (int i = 0; i <= im; ++i) {
        if (pos == 13) {
            ((num + i == 13) && ++sum);
            continue;
        }
        dfs(pos + 1, num + i);
    }
}

int main() {
    dfs(1, 0);
    printf("%d", sum);
    return 0;
}