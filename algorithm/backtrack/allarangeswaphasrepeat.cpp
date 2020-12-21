//cxh
#include <bits/stdc++.h>
using namespace std;

void Allarrange(char *root, int bg, int ed) {
    if (bg == ed) {
        puts(root);
        return;
    }
    for (int i = bg; i <= ed; ++i) {
        swap(root[i], root[bg]);
        Allarrange(root, bg + 1, ed);
        swap(root[i], root[bg]);
    }
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        char root[n + 1] = {0};
        scanf("%s", root);
        Allarrange(root, 0, n - 1);
    }
    return 0;
}