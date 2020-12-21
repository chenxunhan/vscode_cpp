//eat_hen_bug.cpp
//cxh
//去重的做法
#include <bits/stdc++.h>
#define MAXSIZE 5000005
#define MAXNUM 1000000005

using namespace std;

class gap_class {
  public:
    int mn = INT_MAX, mx = INT_MIN;
    bool filled = 0;
};

int n, t;
int real_num;
bool root_again[MAXNUM]; //del again
int root_arr[MAXSIZE];
int root_max, root_min;

int main() {
    while (~scanf("%d", &n)) {
        root_max = INT_MIN;
        root_min = INT_MAX;
        real_num = 0;
        memset(root_again, 0, MAXNUM);
        while (n--) { //scanf + delagain
            scanf("%d", &t);
            if (root_again[t]) { //again
                continue;
            } //not again
            root_arr[real_num] = t;
            ++real_num;
            root_again[t] = 1;
            //next can better
            root_max = max(root_max, t);
            root_min = min(root_min, t);
        }
        if (real_num < 2) { //only one
            puts("0");
            continue;
        }
        if (root_max - root_min + 1 == real_num) { //all lianxu,no gap
            puts("1");
            continue;
        }
        int gap_size = (root_max - root_min) / (real_num - 1);
        int gap_num = (root_max - root_min) / gap_size + 1;
        gap_class gap[gap_num];
        for (int i = 0; i < real_num; ++i) {
            int idx = (root_arr[i] - root_min) / gap_size;
            gap[idx].filled = 1;
            gap[idx].mn = min(gap[idx].mn, root_arr[i]);
            gap[idx].mx = max(gap[idx].mx, root_arr[i]);
        }
        int pre_gap_mx = root_min, max_gap = 0;
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