#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

/*
左偏樹:
合并堆,
取大小根堆顶,
pop堆顶,
修改第i个结点权值
*/

/*左偏樹結構: 
距離,
權值,若=-1,説明節點已刪除
左右兒子的id,
根節點id,用來并查集使用
*/
struct Tree {
    bool ext = 1;
    int dis = 0, val = 0, ls = 0, rs = 0, rt = 0;
} tr[MAXN];

void reset(int i, int val_) {
    tr[i].dis = tr[i].ls = tr[i].rs = 0;
    tr[i].val = val_, tr[i].rt = i;
}
int n, m; //n初始堆個數,m個操作

//合并x y,x y 要求是堆頂,返回merge后的堆頂
//合并两个左偏树，并返回新树的根节点
int merge(int x, int y) {
    if (!x || !y) { //如果有一棵待合并的树为空树，则合并结果为另一棵树
        return x | y;
    }
    //'>/<':'小/大'根堆    '>/<':若兩個節點val==,'先/后'輸入的的所在堆序號較'大/小'的在上方,更加靠近堆頂
    if (tr[x].val < tr[y].val)
        swap(x, y);
    tr[x].rs = merge(tr[x].rs, y);
    if (tr[tr[x].ls].dis < tr[tr[x].rs].dis)
        swap(tr[x].ls, tr[x].rs);
    tr[tr[x].ls].rt = tr[tr[x].rs].rt = tr[x].rt = x;//顺便并根
    tr[x].dis = tr[tr[x].rs].dis + 1;
    return x;
}

//并查集找祖宗(堆頂)
int get(int x) {
    return tr[x].rt == x ? x : tr[x].rt = get(tr[x].rt);
}

//把堆頂x POP掉
void pop(int x) {
    tr[x].ext = 0;
    tr[x].val = -1; //空節點val=-1
    tr[tr[x].ls].rt = tr[x].ls, tr[tr[x].rs].rt = tr[x].rs;
}

int modify(int i, int v) {
     int nrt = merge(tr[i].ls, tr[i].rs);
    reset(i, v);
    return tr[nrt].rt = tr[i].rt = merge(nrt, i);
}

int main() {
    while (~scanf("%d", &n)) {
        tr[0].dis = -1;
        for (int i = 1, v; i <= n; ++i) {
            scanf("%d", &v);
            reset(i, v);
        }
        scanf("%d", &m);
        for (int i = 1, x, y; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            x = get(x), y = get(y);
            if (x == y) {
                puts("-1");
                continue;
            }

            int xrt, yrt;
            xrt = modify(x, tr[x].val / 2);
            yrt = modify(y, tr[y].val / 2);

            printf("%d\n", tr[merge(xrt, yrt)].val);
        }
    }
    return 0;
}