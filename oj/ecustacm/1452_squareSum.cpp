#include <bits/stdc++.h>
using namespace std;

bool isIntersetNum(int n) {
    while (n) {
        int s = n % 10;
        if (s == 2 || s == 0 || s == 1 || s == 9) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    unsigned long long ans = 0;
    for (int i = 1; i <= 2019; ++i) {
        if (isIntersetNum(i)) {
            ans += i * i;
        }
    }
    printf("%llu", ans);
    /*
    for (int i = 1; i <= 40; ++i) {
        cout << i << "--";
        if (isIntersetNum(i)) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }*/
    return 0;
}