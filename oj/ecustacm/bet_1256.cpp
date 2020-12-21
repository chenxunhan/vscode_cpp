#include <bits/stdc++.h>
// typedef long long ull;
using namespace std;

const int MOD = 1000000007;
int a, b;
//everytime count this level
int res[2][7] = {0};

int sumof(const bool i) {
    int sum = 0;
    for (int k = 1; k < 7; ++k) {
        sum += res[i][k];
        sum %= MOD;
    }
    return sum;
}

void dp(const int lv) {
    //lv=1
    for (int i = 1; i <= 6; ++i) {
        res[1][i] = 4;
    }
    for (int l = 2; l <= lv; ++l) {
        for (int i = 1; i <= 6; ++i) {
            if (i != a && i != b) {
                res[l & 1][i] = sumof(!(l & 1)) * 4;
                res[l & 1][i] %= MOD;
                continue;
            }
            res[l & 1][i] = (sumof(!(l & 1)) - res[!(l & 1)][(i == a) ? b : a]) * 4;
            res[l & 1][i] %= MOD;
        }
    }
    cout << sumof(lv & 1) << endl;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        dp(n);
    }

    return 0;
}