#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+5,MAXM=1e5+5;
int n, m;//n个点，m条边
int cnt=0;//边集的大小,动态更新到最后为m

struct Edge{
    int to, next;
}edge[MAXM*2];//边集,注意双边需要*2

int head[MAXN];

void add_edge(int u, int v){
    edge[cnt].to = v; //终点
    edge[cnt].next = head[u];
    head[u] = cnt++;//更新以u为起点上一条边的在边集的编号
}

bool coled[MAXN]={0};//是否遍历过,被染过色
bool col[MAXN]={0};//每一个点的染色
int bwnum[2];//黑白两种染色各自的点数,bwnum['0/1']代表'黑/白'染色点数量,也就是二分图的两part各part的点数量

//判断node为id的结点所在的图是否可为二分图,从main里来时，color初始=0
bool dfs(int node,bool color=0){
    if(coled[node])//如果已被染过色
    {
        if(col[node]==color)return true;//如果仍是原来的颜色，即可行
        return false;//非原来的颜色，即产生了冲突，不可行
    }
    coled[node]=true;//记录
    bwnum[col[node]=color]++;//这一种颜色的个数加1，且此点的颜色也记录下来
    bool tf=true;//是否可行
    for(int i=head[node];i&&tf;i=edge[i].next)//遍历边
    {
        tf=tf&&dfs(edge[i].to,!color);//是否可以继续染色
    }
    return tf;//返回是否完成染色
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;++i) {
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);//存的是有向边，所以存两次
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(coled[i]) continue;//如果此点已被包含为一个已经被遍历过的子图，则不需重复遍历
        bwnum[0]=bwnum[1]=0;//初始化
        if(!dfs(i)){//如果不能染色
            printf("Impossible");
            return 0;//直接跳出
        }
        ans+=min(bwnum[0],bwnum[1]);//加上小的一个
    }
    printf("%d",ans);//输出答案
    return 0;
}