#include <cmath>
#include <iostream>
using namespace std;

uint64_t Pow3[10001];

int main() {
    for (int i(0); i <= 10000; ++i)
        Pow3[i] = (uint64_t) i * i * i;

    int cases;
    cin >> cases;

    int left, right, limit;
    while (cases--) {
        uint64_t target;
        cin >> target;
        right = left = pow(target >> 1, 1. / 3);
        if ((Pow3[right + 1] << 1) <= target) left = right = right + 1;

        limit = (right + 1) << 1;

        if (left == 0) {
            cout << "NO\n";
            continue;
        }

        while (Pow3[left] + Pow3[right] ^ target) {
            if (Pow3[left] + Pow3[right] < target) {
                ++right;
                if (right > limit) break;
            } else {
                --left;
                if (left <= 0) break;
            }
        }

        cout << ((Pow3[left] + Pow3[right] ^ target) ? "NO\n" : "YES\n");
    }

    return 0;
}