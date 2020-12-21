//³©Í¨¹¤³Ì
#include <bits/stdc++.h>
using namespace std;
const int MAX(1005);
int N, M;
int a, b;
int sum;
int pre[MAX];

void zip(const int r, int x) {
    int t;
    while (pre[x] ^ r) {
        t = pre[x];
        pre[x] = r;
        x = t;
    }
}
int find(const int x) {
    int r = x;
    while (pre[r] ^ r) {
        r = pre[r];
    }
    zip(r, x);
    return r;
}
bool join(const int x, const int y) {
    const int xr = find(x), yr = find(y);
    if (xr ^ yr) {
        pre[yr] = xr;
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (1) {
        cin >> N;
        if (!N) break;
        cin >> M;
        sum = 0;
        for (int i = 1; i <= N; ++i) {
            pre[i] = i;
        }
        while (M--) {
            cin >> a >> b;
            join(a, b);
        }
        for (int i = 1; i <= N; ++i) {
            sum += join(1, i);
        }
        cout << "res: " << sum << endl;
    }

    return 0;
}