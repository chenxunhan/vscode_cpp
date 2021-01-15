#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[2] = {1, 1};
    int res[2] = {1, 1};
    int r = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i & 1];
        if (a[i & 1] == a[!(i & 1)] + 1) {
            res[i & 1] = res[!(i & 1)] + 1;
        } else {
            res[i & 1] = 1;
        }
        r = max(r, res[i & 1]);
    }
    cout << r;
    return 0;
}