#include <bits/stdc++.h>
using namespace std;

int ysnum(int n) {
    int res = 0;
    int sq = (int) sqrt(n);
    for (int i = 1; i < sqrt(n); ++i) {
        if (n % i == 0)
            res += 2;
    }
    if (n == sq * sq) {
        ++res;
    }
    return res;
}

int main() {
    // for (int t = 1; t < 13; ++t) {
    //     cout << t << "-" << ysnum(t) << endl;
    // }
    for (int i = 1;; ++i) {
        if (ysnum(i) == 100) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}