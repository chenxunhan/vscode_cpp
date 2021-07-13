#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>

typedef __gnu_pbds::priority_queue<int,std::greater<int>,__gnu_pbds::pairing_heap_tag> heap;

using namespace std;

const int MAXN=1e5+5,MAXM=1e5+5;
int n,m;
heap h[MAXN];
int fa[MAXN],ohi[MAXN];
bool over[MAXN];

inline int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,t;i<=n;++i){
        scanf("%d",&t);
        h[i].push(t);
        ohi[t]=fa[i]=i;
    }
    for(int i=1;i<=m;++i){
        static int type;
        scanf("%d",&type);
        static int x,y;
        if(type==1){
            scanf("%d%d",&x,&y);
            if(over[x]||over[y])
                continue;
            static int fx,fy;
            fx=find(x),fy=find(y);
            if(fx==fy)
                continue;
            h[fx].join(h[fy]);
            h[fy].clear();
            fa[fy]=fx;
        }else{
            scanf("%d",&x);
            if(over[x]){
                puts("-1");
                continue;
            }
            static int fx,tp;
            fx=find(x);
            if(h[fx].empty()){
                continue;
                puts("empty");
            }
            tp=h[fx].top();
            over[ohi[tp]]=1;
            printf("%d\n",tp);
            h[fx].pop();
        }
    }
    return 0;
}