#include<bits/stdc++.h>
using namespace std;

const int MAXN=100+5;

int n;
int max_depth=0,max_width;
int depth[MAXN],width[MAXN];
int head[MAXN];
int fa[MAXN][MAXN];

int cnt;//边集的大小,动态更新到最后为m
struct Edge{
    int to,next;//终点，边权，同起点的上一条边的编号
}edge[MAXN*2];//边集

void init(){
    for (int i = 1; i <= n; i++) 
        head[i] = -1;//一开始都没边
    cnt = 0;//边集空
}

void add_edge(int u, int v){
    edge[cnt].to = v; //终点
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void bfs(int root){
    // memset(depth,0x3f,sizeof depth);
    queue<int> q;
    q.push(root);
    depth[root]=1;//设置哨兵
    max_depth=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=head[t];~i;i=edge[i].next){
            int j=edge[i].to;
            // if(depth[j]>depth[t]+1){
                depth[j]=depth[t]+1;
                max_depth=max(max_depth,depth[j]);
                fa[j][0]=t;
                q.push(j);
                for(int k=1;k<=max_depth;k++)//倍增里面的常数根据题目节点个数而定
                    fa[j][k]=fa[fa[j][k-1]][k-1];
            // }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);//对深度大的点进行往上跳跃
    for(int k=max_depth;k>=0;k--)
        if(depth[fa[a][k]]>=depth[b]) 
            a=fa[a][k];
    if(a==b) return a;
    for(int k=max_depth;k>=0;k--)//两个点同时跳跃，直到最近公共祖先的下面的节点
    {
        if(fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];//返回a的父亲，也就是最近公共祖先
}

int main(){
    scanf("%d",&n);
    init();
    for(int i=1,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
//        add_edge(y,x);
    }
    bfs(1);
    for(int i=1;i<=n;++i){
        ++width[depth[i]];
    }
    for(int i=1;i<=max_depth;++i){
        max_width=max(max_width,width[i]);
    }
    int a,b;
    scanf("%d%d",&a,&b);
    int cfa=lca(a,b);
    printf("%d\n%d\n%d",max_depth,max_width,(depth[a]-depth[cfa])*2+(depth[b]-depth[cfa]));
    
    return 0;
}