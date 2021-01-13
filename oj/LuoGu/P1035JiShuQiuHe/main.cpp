#include <bits/stdc++.h>
using namespace std;

// 1^2+2^2+3^2+4^2+...+n^2
// 1+2+3+4=day
// 1+...+n=day
// (1+n)*n/2>=day
// (1+n)*n>=day*2
// n+n*n>=day*2

// 1+...+(n-1)
// n*(n-1)/2

int main() {
    int n = 1;
    int day;
    cin >> day;
    while (1) {
        if (n + n * n >= day + day) {
            break;
        }
        ++n;
    }
    int rest = day - (n * (n - 1) / 2);
    int res(n * rest);
    for (int i(1); i < n; ++i) {
        res += i * i;
    }
    cout << res;
    return 0;
}