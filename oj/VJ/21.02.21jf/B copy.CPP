#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr, tp;
int rs[3];
int main() {
    scanf("%d", &t);
    while (t--) {
        rs[0] = rs[1] = rs[2] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            // scanf("%d", arr + i);
            scanf("%d", &tp);
            ++rs[tp % 3];
        }
        int tar = n / 3;
        if (tar == rs[0] && rs[0] == rs[1] && rs[1] == rs[2]) {
            printf("0\n");
            continue;
        }
        // int res = 0;
        int mnidx = 0, mn = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            // mn >= rs[i] &&
            if (rs[i] < tar) {
                mnidx = i;
                mn = rs[i];
                
            }
            // if (rs[i] < tar) {
            //     res += tar - rs[i];
            //     rs[(i - 1 + 3) % 3] -= (tar - rs[i]);
            // }
        }
        int res = tar - mn;
        mnidx = (mnidx + 3 - 1) % 3;
        rs[mnidx] -= res;
        res += tar - rs[mnidx];
        printf("%d\n", res);
    }
    return 0;
}