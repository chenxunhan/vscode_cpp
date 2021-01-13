#include <bits/stdc++.h>
using namespace std;

// enum dig {
//     g,
//     s,
//     b,
//     q,
//     w,
//     sw,
//     bw,
//     qw,
//     y
// };
//6781  0  2
int digNum(int num, int ctNum, int dg) {
    int dge = (int) (pow(10, (int) dg));
    int head = num / 10 / dge;
    int tail = num % dge;
    num /= dge;
    int res(0);
    if (num % 10 < ctNum) {
        res += head * dge;
    } else if (num % 10 == ctNum) {
        res += (head - (ctNum == 0)) * dge + tail + 1;
    } else if (num % 10 > ctNum) {
        res += (head + (ctNum != 0)) * dge;
    }
    return res;
}

int main() {
    int a = 11, b = 1, aw;
    int res(0);
    cin >> a >> b;
    {
        int at = a;
        while (at) {
            ++aw;
            at /= 10;
        }
    }
    for (int i(0); i < aw; ++i) {
        res += digNum(a, b, i);
    }
    cout << res;
    return 0;
}

/**
 * 位数  数字出现几次后消失  位数的数字个数
 * 个    1                 1
 * 十    10                2
 * 百    100               3
 * 千    1000              4
 * 
 * 
 */