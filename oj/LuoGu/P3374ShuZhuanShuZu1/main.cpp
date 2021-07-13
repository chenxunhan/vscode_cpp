#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int arr[MAXN], tr[MAXN]; //原数组和树状数组, 大小一样+5
int n, m;
int lowbit(int x) {
    return x & -x;
}
void updata(int i, int c) //修改树状数组i位置的值+c
{
    for (; i <= n; i += lowbit(i))
        tr[i] += c;
}
void build() {
    for (int i = 1; i <= n; i++) {
        //cin>>arr[i];
        updata(i, arr[i]); //注意不是arr[i]
    }                      //一开始先赋初值
}
int query(int i) //查询区间[1~i]的区间和；
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main() {
    //build
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
    }
    build();
    int tp, x, y;
    while (m--) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 2) { //tp==2
            printf("%d\n", query(y) - query(x - 1));
            continue;
        }
        updata(x, y);
    }

    return 0;
}