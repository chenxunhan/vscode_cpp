//最长连续字段和

#include <bits/stdc++.h>
using namespace std;

int res, start_index, end_index;

void f(int *arr, int n) {
    res = INT_MIN, start_index = 0;
    int cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum += arr[i];
        if (res < cur_sum) {
            res = cur_sum;
            end_index = i;
        }
        if (cur_sum < 0) {
            cur_sum = 0;
            start_index = i + 1;
        }
    }
}

int main() {
    int array[] = {1, -2, 43, -15, -12, 423, -45, 235, 254, -235};
    f(array, sizeof(array) / sizeof(int));
    cout << "res:" << res << endl
         << "sidx:" << start_index << endl
         << "eidx:" << end_index << endl;
    return 0;
}