#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 5;
int arr[MAXN], tr[MAXN]; //原数组和树状数组, 大小一样+5
//树状数组存放的是arr[]的差分，tr[1]=arr[1]
int n;
int lowbit(int x) {
    return x & -x;
}
void updata(int i, int c) //修改树状数组i位置的值+c
{
    for (; i <= n; i += lowbit(i))
        tr[i] += c;
}
//区间修改
//将原数组arr[a~b]之间都+c，相当于在tr[]维护的差分数组arr[a]+=c,arr[b+1]-=c
void uprange(int a, int b, int c) {
    updata(a, c);
    updata(b + 1, -c);
}

int query(int i) //查询差分数组区间[1~i]的区间和；就相当于修改后的arr[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}
// usage:
//     用之前先 build();
//     //单点arr[i]查询就是tr[]维护的差分数组的[1~i]的总和=query(i)
int main() {
    int m;
    scanf("%d%d", &n, &m);
    //建立差分树状数组
    arr[0] = 0; //注意
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);           //要求arr[i]正确 可以合并在main中
        updata(i, arr[i] - arr[i - 1]); //使用updata建树
    }                                   //一开始先赋初值
    int tp;
    int x, y, k;
    while (m--) {
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d%d", &x, &y, &k);
            uprange(x, y, k);
            continue;
        }
        //tp==2
        scanf("%d", &x);
        printf("%d\n", query(x));
    }
    return 0;
}