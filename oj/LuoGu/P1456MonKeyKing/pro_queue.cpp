#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>

typedef __gnu_pbds::priority_queue<int,std::less<int>,__gnu_pbds::pairing_heap_tag> heap;

using namespace std;
heap q[100005];//�������cһ�_ʼ���Գ�һ��
int fa[100005];//��픸����c
int n,m;//���c��,������

//���鼯�����ڶ��
inline int fd(int x){
	if(fa[x]!=x) fa[x]=fd(fa[x]);
	return fa[x];
}

int main()
{
    int x,y;//���ϲ�x y
    int fx,fy;//x y�����ڶ��
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