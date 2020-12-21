//会传递的困意 第 2589 题
//陈逊瀚
#include <bits/stdc++.h>
using namespace std;

int x, y;
int a, b, n;

int set_row_sleep(int left, int right) {
    left = max(1, left);
    right = min(y, right);
    return right - left + 1;
}

int after_mins_sleep_num(int a, int b, int mins) {
    if (mins) {
        int re = set_row_sleep(b - mins, b + mins);
        for (int i = 1; i <= mins && re < x * y; ++i) {
            int add = set_row_sleep(b - mins + i, b + mins - i);
            if (a - i >= 1)
                re += add;
            if (a + i <= x)
                re += add;
        }
        return re;
    }
    return 1;
}

int main() {
    cin >> x >> y;
    while (cin >> a >> b >> n) {
        cout << after_mins_sleep_num(a, b, n) << endl;
    }
    return 0;
}