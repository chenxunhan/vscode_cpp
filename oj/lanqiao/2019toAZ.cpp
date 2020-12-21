#include <bits/stdc++.h>
using namespace std;

/*
A B C D ... Z
0 1 2 3 ... 25


*/

string con(int n) {
    string s;
    int t;
    while (n) {
        t = n % 26;
        ((t == 0) && (n-- && (t = 26)));
        s = char('A' - 1 + t) + s;
        n /= 26;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int cn;
    while (cin >> cn) {
        cout << con(cn) << endl;
    }
    return 0;
}
