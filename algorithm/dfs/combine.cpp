#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int res[N];
bool used[N];
int k, mx;

void print() {
    for (int i = 0; i < k; ++i) {
        printf("%d ", res[i]);
    }
    putchar('\n');
}

void f(int pos, int num) {
    if (num == k) {
        print();
        return;
    }
    if (pos > mx || num > k)
        return;

    for (int i = 0; i <= mx; ++i) {
        if (used[i] == 0 && (i >= res[pos - 1] || pos - 1 < 0)) {
            used[i] = 1;
            res[pos] = i;
            f(pos + 1, num + 1);
            used[i] = 0;
        }
    }
}
// choose a in b
void combine(int a, int b) {
    memset(used, 0, sizeof(used));
    k = a, mx = b;
    f(0, 0);
}

int main() {
    combine(4, 7);
    return 0;
}