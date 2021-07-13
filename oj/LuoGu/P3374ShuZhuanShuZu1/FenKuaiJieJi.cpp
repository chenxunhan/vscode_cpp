#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, a[MAXN], belong[MAXN];
int S, C = 0, st[MAXN], ed[MAXN];
int sum[MAXN], ma_x[MAXN], mi_n[MAXN];
/*
n:元素个数，a[]：元素，belong[]:每个元素所属的块的编号 
S:每个块有多少元素 C:分块个数 st/ed:每个块的左边界、右边界 
sum[MAXN]/ma_x[MAXN]/mi_n[MAXN]用于记录区间信息 
*/
void pretreat() {
    S = int(sqrt(double(n)));
    for (int i = 1; i <= n; i += S) {
        st[++C] = i;
        ed[C] = min(i + S - 1, n); //有可能会越界（sqrt必然有精度误差）
    }
    for (int i = 1; i <= C; i++)
        for (int j = st[i]; j <= ed[i]; j++) {
            belong[j] = i; //初始化belong
            //区间操作
            sum[i] += a[j];
            ma_x[i] = max(ma_x[i], j);
        }
}

//区间单点修改 ，此处以求区间和为例
inline void updata_single(int x, int k) {
    a[x] += k;
    sum[belong[x]] += k;
}

//区间修改，同上
int delta[MAXN]; //用于记录一个！完整！区间的修改
void updata_range(int x, int y, int k) {
    int l = belong[x], r = belong[y];
    if (l == r && st[l] == x && st[r] == y) {
        delta[l] = k;
        return;
    } //ma_x[]
    //这个if纯粹是为了减少底下的运算，毕竟判断只有O(1) qwq
    else {
        for (int i = x; i <= ed[l]; i++)
            updata_single(i, k); //如果不是完整区间，就单点修改
        if (st[l] > x && st[r] < y) return;
        //如果查询区间被某个块完全包含且不相等，
        //不需要进行以下操作
        for (int i = st[r]; i <= y; i++)
            updata_single(i, k);
        //如果所查询区间与块有交集且不想等
        //不需进行以下操作
        for (int i = l + 1; i < r; i++)
            delta[i] += k;
        ;
    }
}

int query(int x, int y) //依然为区间和
{
    int l = belong[x], r = belong[y], ans = 0;
    if (l == r) {
        for (int i = x; i <= y; i++)
            ans += a[i] + delta[belong[i]];
    } else {
        for (int i = x; i <= ed[l]; i++)
            ans += a[i] + delta[belong[i]];
        for (int i = l + 1; i < r; i++)
            ans += sum[i] + delta[i] * (ed[i] - st[i] + 1);
        //对于每个区间的O(1)运算
        for (int i = st[r]; i <= y; i++)
            ans += a[i] + delta[belong[i]];
    }
    return ans;
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    pretreat();
    for (int i = 1, tp, x, y; i <= m; ++i) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 1) {
            updata_single(x, y);
        } else { //tp==2
            printf("%d\n", query(x, y));
        }
    }
    return 0;
}