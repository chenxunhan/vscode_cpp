#include <bits/stdc++.h>
using namespace std;

bool has4(int n) {
    bool has = false;
    while (n && !has) {
        has = ((n % 10) == 4);
        n /= 10;
    }
    return has;
}

int main() {
    int sum = 0;
    for (int i = 10000; i <= 99999; ++i) {
        sum += !has4(i);
    }
    cout << sum;
    return 0;
}