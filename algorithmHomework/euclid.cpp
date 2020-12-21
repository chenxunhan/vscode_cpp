#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, r;
    cin >> m >> n;
    while ( n ) {
        r = m % n;
        m = n;
        n = r;
    }
    cout << m; 
    return 0;
}

/*大除小，小除�?
    小除�?==0时终�?
*/