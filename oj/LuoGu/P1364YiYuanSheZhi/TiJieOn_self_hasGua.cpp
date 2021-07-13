#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100+5;

struct Edge{
	int next, to;
}e[MAXN];//树的边=node_num-1
int head[MAXN],cnt=0;  //head[]这里比较特殊,最终指向0不是-1

int n;
int w[MAXN],//w[i]:i结点的权重(人数)
size[MAXN];//我的所有子节点的权重包括自己权重和
long long ans = INT_MAX, f[MAXN];

inline int read() {
	int x=0;
    char c=getchar();
    while(c<'0'||c>'9')//c<'0'||c>'9'
    	c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=c-48,c=getchar();
    return x;
}

bool add_edge(int from, int to){
	e[++cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;
}

//u的id,u的爸爸,u与根节点1的距离
void dfs(int u, int dep){ //预处理f[1]和size
    size[u] = w[u];//先收成自己的权重 入 总权重和
	for(int i = head[u]; i; i = e[i].next){//对u的所有边遍历
	     dfs(e[i].to,  dep + 1),//进入下一个指向的子树根节点
          size[u] += size[e[i].to];//在上方dfs后,所有子节点的size已经算后,最后收成到自己这里来
	}
	f[1] += w[u] * dep;//main里第一次调用,初始化的是根1的距离和(sum_all_child_node{权值x距离})
}

//动态规划算出树的重心的距离和(sum_all_child_node{权值x距离})
//(传入结点,他的爸爸)
void dp(int u){  //转移
    for(int i = head[u]; i; i = e[i].next)
         f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to);
    if(ans> f[u]){//取最小值
        ans=f[u];
        //ansNodeId=u;//重心的id
    }
}
void otp(long long  k){
	if(!k) return;
    otp(k/10);
    putchar(k%10+'0');
}
int main(){
    n=read();
    // cout<<n<<endl;
    for(int i=1,a,b;i<=n;++i){
        w[i]=read();
        a=read();
        b=read();
        // scanf("%d%d%d",w+i,&a,&b);
       a && add_edge(i, a);
       b && add_edge(i, b);
    }
    dfs(1, 0);//根节点1的爸爸是0
    dp(1);
    otp(ans);
    puts("");
    // cout<<ans;
    // printf("%lld\n", ans);
    return 0;
}