#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr, tp;
int tar;
int rs[3], res = 0;

int main() {
    scanf("%d", &t);
    while (t--) {
        rs[0] = rs[1] = rs[2] = res = 0;
        scanf("%d", &n);
        tar = n / 3;
        for (int i = 0; i < n; ++i) {
            // scanf("%d", arr + i);
            scanf("%d", &tp);
            ++rs[tp % 3];
        }
        while (!(tar == rs[0] && rs[0] == rs[1] && rs[1] == rs[2])) {
            ++res;
            if (rs[0] >= rs[1] && rs[0] >= rs[2])
                --rs[0], ++rs[1];
            else if (rs[1] >= rs[0] && rs[1] >= rs[2])
                --rs[1], ++rs[2];
            else if (rs[2] >= rs[0] && rs[2] >= rs[1])
                --rs[2], ++rs[0];
        }
        printf("%d\n", res);
    }
    return 0;
}