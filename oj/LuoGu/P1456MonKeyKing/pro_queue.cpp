#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>

typedef __gnu_pbds::priority_queue<int,std::less<int>,__gnu_pbds::pairing_heap_tag> heap;

using namespace std;
heap q[100005];//各個節點一開始都自成一堆
int fa[100005];//堆頂根節點
int n,m;//節點數,操作數

//并查集找祖宗堆頂
inline int fd(int x){
	if(fa[x]!=x) fa[x]=fd(fa[x]);
	return fa[x];
}

int main()
{
    int x,y;//待合并x y
    int fx,fy;//x y的祖宗堆頂
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
        	while(!q[i].empty())
                q[i].clear();
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            fa[i]=i,q[i].push(x);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            fx=fd(x),fy=fd(y);
            if(fx==fy)  {
                puts("-1");
                continue;
            }
            q[fx].push(q[fx].top()/2),q[fy].push(q[fy].top()/2);
            q[fx].pop(),q[fy].pop();
            q[fx].join(q[fy]);
            fa[fy]=fx;
            printf("%d\n",q[fx].top());
        }
    }
	return 0;
}