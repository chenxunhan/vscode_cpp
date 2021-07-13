#include <bits/stdc++.h>
using namespace std;

#define MAXN 150010

/*
左偏樹:

*/

/*左偏樹結構: 
距離,
權值,若=-1,説明節點已刪除
左右兒子的id,
根節點id,用來并查集使用
*/
struct Tree {
    int dis, val, ls,rs, rt;
} S[MAXN];

int n, m;//n初始堆個數,m個操作

//合并x y,x y 要求是堆頂,返回merge后的堆頂
inline int Merge(int x, int y) {
    if(x==0||y==0){
        return x+y;
    }
    //'>/<':'小/大'根堆    '>/<':若兩個節點val==,'先/后'輸入的的所在堆序號較'大/小'的在上方,更加靠近堆頂
    if (S[x].val > S[y].val || (S[x].val == S[y].val && x > y))
        swap(x, y);
    S[x].rs = Merge(S[x].rs, y);
    if (S[S[x].ls].dis < S[S[x].rs].dis) 
        swap(S[x].ls, S[x].rs);
    S[S[x].ls].rt = S[S[x].rs].rt = S[x].rt = x; 
    S[x].dis = S[S[x].rs].dis + 1;
    return x;
}

//并查集找祖宗(堆頂)
inline int Get(int x) {
    return S[x].rt == x ? x : S[x].rt = Get(S[x].rt);
}

//把堆頂x POP掉
inline void Pop(int x) {
    S[x].val = -1;//空節點val=-1
    S[S[x].ls].rt = S[x].ls, S[S[x].rs].rt = S[x].rs;
    S[x].rt = Merge(S[x].ls, S[x].rs);
}


int main() {
    scanf("%d%d",&n,&m);
    S[0].dis = -1;////空節點dis=-1

    for (int i = 1; i <= n; ++i){
        S[i].rt = i; //初始化各節點的根節點爲自己
        scanf("%d", &S[i].val);//掃入個節點的權值
    }

    for (int i = 1,ctp,x,y,f1,f2; i <= m; ++i) {
        scanf("%d", &ctp);
        if (ctp == 1) {
            scanf("%d%d", &x,&y);
            if (S[x].val == -1 || S[y].val == -1) //如果其中一個已刪除
                continue;
            f1 = Get(x), f2 = Get(y);//找到x,y的祖宗f1,f2
            if (f1 != f2) //如果x y祖宗f1 f2不一樣,開始合并
                S[f1].rt = S[f2].rt = Merge(f1, f2);
        } else {
            scanf("%d",&x);
            if (S[x].val == -1)
                printf("-1\n");
            else
                printf("%d\n", S[Get(x)].val), Pop(Get(x));
        }
    }
    return 0;
}