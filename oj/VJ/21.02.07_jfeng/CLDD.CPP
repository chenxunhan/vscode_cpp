#include <cstring>
#include <iostream>

using namespace std;

inline uint64_t combine2(int n) { return (static_cast<long long>(n) * (n - 1)) >> 1; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int number_of_case;
    cin >> number_of_case;

    while (number_of_case--) {
        int numberBoy, numberGirl, pairs;
        cin >> numberBoy >> numberGirl >> pairs;

        int boyCounts[numberBoy], girlCounts[numberGirl];
        memset(boyCounts, 0, sizeof(boyCounts));
        memset(girlCounts, 0, sizeof(girlCounts));

        for (int i(0), posit; i < pairs; ++i) {
            cin >> posit;
            ++boyCounts[posit - 1];
        }
        for (int i(0), posit; i < pairs; ++i) {
            cin >> posit;
            ++girlCounts[posit - 1];
        }

        uint64_t ans(combine2(pairs));
        for (int i(0); i < numberBoy; ++i) {
            boyCounts[i] > 1 && (ans -= combine2(boyCounts[i]));
        }
        for (int i(0); i < numberGirl; ++i) {
            girlCounts[i] > 1 && (ans -= combine2(girlCounts[i]));
        }
        cout << ans << endl;
    }

    return 0;
}