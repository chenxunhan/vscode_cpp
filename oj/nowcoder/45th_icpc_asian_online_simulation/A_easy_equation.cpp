/*
3 3 3 3
20

300 300 300 300
4590551

0 0 0 0
1

12345 12345 12345 12345
313713415596
*/

#include <bits/stdc++.h>
using namespace std;

int baoli(int a, int b, int c, int d) {
    int ans = 0;
    for (int x = 0; x <= a; ++x)
        for (int y = 0; y <= b; ++y)
            for (int z = 0; z <= c; ++z)
                if (x + y + z <= d)
                    ++ans;
    return ans;
}

//ldd
long long WaysOfPlus(int a, int b, int c, int d) {
    if (c <= a || c <= b) {//a,b最大的放c 位
        // int *p = a > b ? &a : &b;
        // *p = (c ^ *p) ^ (c = *p);
        if (a > b) {
            // a = (c ^ a) ^ (c = a);
            swap(a, c);
        } else {
            // b = (c ^ b) ^ (c = b);
            swap(b, c);
        }
    };
    // int min_ab_d = a + b < d ? a + b : d;
    int min_ab_d = min(a + b, d);//t的最大取值
    long long xyTot[min_ab_d + 1];//丢入t返回x+y==t的所有种类数
    xyTot[0] = 1;//丢入0返回1
    for (int t = 1; t <= min_ab_d; ++t)
        // xyTot[t] = xyTot[t - 1] + (t < b ? t : b) - (t - a > 0 ? t - a - 1 : -1);
        xyTot[t] = xyTot[t - 1] + min(t, b) - max(t - a - 1, -1);

    // d = a + b + c < d ? a + b + c : d;
    d = min(a + b + c, d);

    long long sum(0);
    int k(0);
    for (; k <= min_ab_d; ++k)
        sum += xyTot[k] - (k - c - 1 >= 0 ? xyTot[k - c - 1] : 0);
    for (; k <= d; ++k)
        sum += xyTot[a + b] - (k - c - 1 >= 0 ? xyTot[k - c - 1] : 0);
    return sum;
}

int main() {
    int a, b, c, d;
    while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
        // cout << baoli(a, b, c, d) << endl;
        cout << WaysOfPlus(a, b, c, d) << endl;
    }

    return 0;
}