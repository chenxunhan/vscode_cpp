#include <bits/stdc++.h>
using namespace std;

struct {
    int x, y;
    int xlen, ylen;
} diTan[10005];
int n;
int sx, sy;
int recordNo = -1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &diTan[i].x, &diTan[i].y, &diTan[i].xlen, &diTan[i].ylen);
    }
    scanf("%d%d", &sx, &sy);
    for (int i = 1, x, y, xlen, ylen; i <= n; ++i) {
        x = diTan[i].x, y = diTan[i].y;
        xlen = diTan[i].xlen, ylen = diTan[i].ylen;
        if ((x <= sx && sx <= x + xlen) &&
            (y <= sy && sy <= y + ylen)) {
            recordNo = i;
        }
    }
    printf("%d", recordNo);
    return 0;
}