
#include <bits/stdc++.h>
using namespace std;

class tree_class {
  public:
    int base;
    int grow;
};

int n, m, mx; //tree_num:n;day:m
tree_class tree[200];

bool treecmp(tree_class a, tree_class b) {
    return a.grow > b.grow;
}

int nowsum() {
    int sum = 0;
    for (int ti = 0; ti < m; ++ti) {
        sum += tree[ti].base + (m - ti - 1) * tree[ti].grow;
    }
    return sum;
}

int ifswapsumadd(int a) {
    int swapsumadd = 0;
    ++a;
    while (a < m) {
        swapsumadd += tree[a++].grow;
    }
    return swapsumadd;
}

int ifswapsum(int a, int b) {
    int swapsum = mx;
    swapsum -= tree[a].base + (m - a - 1) * tree[a].grow; //
    swapsum += ifswapsumadd(a) + tree[b].base;
    return swapsum; //
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tree[i].base);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tree[i].grow);
        }
        sort(tree, tree + n, treecmp);
        mx = nowsum();
        for (int b = m, rmx = mx, rpos; b < n; ++b) { //rpos最终放入的位置
            rpos = b;
            for (int a = 0, t; a < m; ++a) {
                t = ifswapsum(a, b);
                if (t > rmx) {
                    rpos = a;
                    rmx = t;
                }
            }
            if (rpos != b) {
                for (int i = rpos; i < m - 1; ++i) {
                    tree[i] = tree[i + 1];
                }
                tree[m - 1] = tree[b];
                mx = rmx;
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}