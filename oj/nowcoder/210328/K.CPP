#include <bits/stdc++.h>
enum Dir {
    up = 0,
    lf = 1,
    dw = 2,
    rt = 3
};

int x = 0, y = 0;
int up_ = 0, lf_ = 0, dw_ = 0, rt_ = 0;
int n;
Dir d[10000 + 5];

int main() {
    scanf("%d%*d", &n);
    d[0] = rt;
    for (int i = 1, t; i < n; ++i) {
        scanf("%d%*d", &t);
        d[i] = Dir((d[i - 1] + t + 4) % 4);
    }
    scanf("%*d");
    printf("%d ", 1);
    rt_ = 1, x = 1;
    for (int i = 1; i < n; ++i) {
        if (d[i] == rt) {
            ++rt_;
            printf("%d ", abs(rt_ - x));
            x = rt_;
            continue;
        }
        if (d[i] == lf) {
            --lf_;
            printf("%d ", abs(lf_ - x));
            x = lf_;
            continue;
        }
        if (d[i] == up) {
            ++up_;
            printf("%d ", abs(up_ - y));
            y = up_;
            continue;
        }
        if (d[i] == dw) {
            --dw_;
            printf("%d ", abs(dw_ - y));
            y = dw_;
            continue;
        }
    }
    return 0;
}

int 
abcdkefgh 
abcdefgh  
[0~9]

if odd 
    if efgh<dcba 
        abcdkdcba 
    else 
        abc(d+1)0(d=1)cba 
if efgh<dcba 
    abcddcba 
else  
    abc(d+1)(d=1)cba 