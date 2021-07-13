#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int w[N];    //区间里的数
int n, m, p; //

struct node {
    ll l, r; //当前结点所处区间
    ll sum;  //当前区间的权值和
    ll add;  //当前区间所具有加权值的懒标记
    ll mul;  //当前区间所具有倍数权值的懒标记
} tr[N * 4]; //注意对题中所给操作数量或者数据要开4倍大

void eval(node &root, int add, int mul) {
    //更新公式： （root.mul * root.sum + root.add）*mul+add
    root.sum = (root.sum * mul + (root.r - root.l + 1) * add) % p;
    root.mul = root.mul * mul % p;
    root.add = (root.add * mul + add) % p;
}
void pushup(int u) // 由子节点更新父节点
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}
void pushdown(int u) {
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1; //恢复懒标记
}
void build(int u = 1, int l = 1, int r = n) {
    if (l == r)
        tr[u] = {l, r, w[r], 0, 1}; //如果处理到叶结点了，就保存叶结点的信息
    else {
        tr[u] = {l, r, 0, 0, 1}; //保存当前节点的信息
        int mid = l + r >> 1;
        build(u << 1, l, mid);         //递归左节点
        build(u << 1 | 1, mid + 1, r); //	递归右节点
        pushup(u);                     //每次根据子节点更新父节点
    }
}

void modify(int u, int l, int r, int add, int mul) {
    if (tr[u].l >= l && tr[u].r <= r) {
        eval(tr[u], add, mul); //当前树中区间被包含在修改区间时，直接修改即可；
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;                //当前节点区间的中点
        if (l <= mid) modify(u << 1, l, r, add, mul);    //如果要修改的地方处于中点的左端，则递归其左儿子
        if (r > mid) modify(u << 1 | 1, l, r, add, mul); // 如果要修改的地方处于中点的右端，则递归其右儿子
        pushup(u);                                       //修改完之后由子节点更新父节点的信息
    }
}

node query(int u, int l, int r) //在区间l，r里面查询
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u]; // 如果当前区间在l~r里面，则直接返回想要的信息
    else {
        pushdown(u);
        node res;
        res.sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;                                   //取当前节点的区间中点
        if (l <= mid) res.sum += query(u << 1, l, r).sum % p, res.sum %= p; //查询区间的和等于左右两个子树区间的和
        if (r > mid) res.sum += query(u << 1 | 1, l, r).sum % p, res.sum %= p;
        pushup(u);
        return res;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    build();
    node res;
    for (int i = 0, t, x, y, k; i < m; ++i) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &x, &y, &k);
            modify(1, x, y, 0, k);
            continue;
        }
        if (t == 2) {
            scanf("%d%d%d", &x, &y, &k);
            modify(1, x, y, k, 1);
            continue;
        }
        if (t == 3) {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, x, y).sum % p);
        }
    }
    return 0;
}