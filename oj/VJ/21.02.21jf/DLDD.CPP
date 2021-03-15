#include <cstring>
#include <iostream>
using namespace std;

int father[100 + 5], number[100 + 5], deep[100 + 5];

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int n;
        cin >> n;
        for (int i(0); i < n; ++i) {
            cin >> number[i];
        }
        memset(deep, -1, sizeof(int) * n);

        father[0] = -1;

        for (int i(1); i < n; ++i) {
            int p(i - 1);

            if (number[i] < number[p]) {
                father[i] = p;
            } else {
                while (~father[p] &&
                       number[i] > number[father[p]]) {
                    p = father[p];
                }

                father[i] = father[p];
                father[p] = i;
            }
        }

        for (int i(0), dp, p; i < n; ++i) {
            if (~deep[i]) {
                cout << deep[i] << ' ';
                continue;
            }

            dp = 0;
            p = i;
            while (~father[p]) {
                ++dp;
                p = father[p];

                if (~deep[p]) {
                    dp += deep[p];
                    break;
                }
            }
            deep[i] = dp;
            cout << dp << ' ';
        }
        cout << endl;
    }

    return 0;
}