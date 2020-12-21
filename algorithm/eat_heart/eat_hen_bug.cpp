//eat_hen_bug.cpp
//cxh
#include <bits/stdc++.h>
#define MAXSIZE 5000005

using namespace std;

class gap_class {
  public:
    int mn = INT_MAX;
    int mx = INT_MIN;
    bool filled = 0;
};

int n, t;
int root_arr[MAXSIZE];
int root_max, root_min;

int main() {
    while (~scanf("%d", &n)) {
        root_max = INT_MIN;
        root_min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            scanf("%d", root_arr + i);
            root_max = max(root_max, *(root_arr + i));
            root_min = min(root_min, *(root_arr + i));
        }
        if (root_max == root_min) {
            puts("0");
            continue;
        }
        int gap_size = max((root_max - root_min) / (n - 1), 1);
        int gap_num = (root_max - root_min) / gap_size + 1;
        gap_class gap[gap_num];
        for (int i = 0; i < n; ++i) {
            int idx = (root_arr[i] - root_min) / gap_size;
            gap[idx].filled = 1;
            gap[idx].mn = min(gap[idx].mn, *(root_arr + i));
            gap[idx].mx = max(gap[idx].mx, *(root_arr + i));
        }
        int pre_gap_mx = root_min, max_gap = 1;
        for (int i = 0; i < gap_num; ++i) {
            if (!gap[i].filled) {
                continue;
            }
            max_gap = max(max_gap, gap[i].mn - pre_gap_mx);
            pre_gap_mx = gap[i].mx;
        }
        printf("%d\n", max_gap);
    }
    return 0;
}