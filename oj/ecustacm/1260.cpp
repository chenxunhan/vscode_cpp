#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int x1 = 2; x1 <= 49; ++x1) {
        for (int x2 = x1 + 2; x2 <= 49; ++x2) {
            int sum = 0;
            for (int i = 1; i <= 49; ++i) {
                if (i == x1 || i == x2) {
                    sum = sum - (i - 1) + (i - 1) * i;
                } else {
                    sum += i;
                }
            }
            if (sum == 2015) {
                cout << x1 - 1 << endl;
            }
        }
    }
    return 0;
}