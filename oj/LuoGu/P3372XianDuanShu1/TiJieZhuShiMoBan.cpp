//区间修改查询
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

const int MAXN= 1e5+5;
int n, m;
ll  a[MAXN], ans_sum[4 * MAXN], tag[MAXN << 2];

//左儿子
inline int ls(int p) { return p << 1; }     
//右儿子
inline int rs(int p) { return p << 1 | 1; } 

 //	向上不断维护区间操作
void push_up_sum(int p) {
    ans_sum[p] = ans_sum[ls(p)] + ans_sum[rs(p)];
}
void push_up_min(int p) { //max
    // ans_min[p] = min(ans_min[ls(p)], ans_min[rs(p)]);
}

void push_up_max(int p) { //max
    // ans_max[p] = max(ans_max[ls(p)], ans_max[rs(p)]);
}

// 对 [l,r] 区间建立线段树,当前根的编号为 p
void build(int p=1, int l=1, int r=n) {
    //如果左右区间相同，那么必然是叶子节点啦，只有叶子节点是被真实赋值的
    if (l == r) {
        ans_sum[p] = a[l];
        return;
    }
    // 递归对左右区间建树
    int mid = l + (r-l >> 1);
    //此处由于我们采用的是二叉树，所以对于整个结构来说，可以用二分来降低复杂度，否则树形结构则没有什么明显的优化
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    //此处由于我们是要通过子节点来维护父亲节点，所以pushup的位置应当是在回溯时
    push_up_sum(p);
}

inline void f(int p, int l, int r, ll k) {
    tag[p] = tag[p] + k;
    //由于是这个区间统一改变，所以ans_sum数组要加元素个数次啦
    ans_sum[p] = ans_sum[p] + k * (r - l + 1);
}

//我们可以认识到，f函数的唯一目的，就是记录当前节点所代表的区间
inline void push_down(int p, int l, int r) {
    //每次更新两个儿子节点。以此不断向下传递
    int mid = l + (r-l >> 1);
    f(ls(p), l, mid, tag[p]);
    f(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}
//nl,nr为要修改的区间
//l,r,p为当前节点所存储的区间以及节点的编号
inline void update(int nl, int nr, ll k, int p=1, int l=1, int r=n) {
    if (nl <= l && r <= nr) {
        ans_sum[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    //回溯之前（也可以说是下一次递归之前，因为没有递归就没有回溯）
    //由于是在回溯之前不断向下传递，所以自然每个节点都可以更新到
    push_down(p, l, r);
    int mid = l+( r-l >> 1);
    if (nl <= mid) update(nl, nr, k, ls(p), l, mid);
    if (nr > mid) update(nl, nr, k, rs(p), mid + 1, r);
    //回溯之后
    push_up_sum(p);
}

// [q_x,q_x] 为查询区间, [l,r] 为当前节点包含的区间, p为当前节点的编号
ll query_sum(int q_x, int q_y, int p=1, int l=1, int r=n) {
    ll res = 0;
    if (q_x <= l && r <= q_y) return ans_sum[p];
    int mid = l+( r-l >> 1);
    push_down(p, l, r);
    if (q_x <= mid) res += query_sum(q_x, q_y, ls(p), l, mid);
    if (q_y > mid) res += query_sum(q_x, q_y, rs(p), mid + 1, r);
    return res;
}

int main() {
    int x, y;
    ll k;//注意k是ll 

    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);

    //一开始建树,1为根节点,建立[1~n]
    build();
    while (m--) {
        scanf("%d", &tp);
        switch (tp) {
        case 1: {
            scanf("%d%d%lld", &x, &y, &k);
            update(x, y, k);
            break;
        }
        case 2: {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query_sum(x, y));
            break;
        }
        }
    }
    return 0;
}