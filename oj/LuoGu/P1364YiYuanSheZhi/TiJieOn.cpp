#include <cstdio>
#define rep(i, m, n) for(register int i = m; i <= n; ++i)
#define INF 2147483647
#define Open(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define Close fclose(stdin);fclose(stdout);
using namespace std;
inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * w;
}
const int MAXN = 10010;
struct Edge{
	int next, to;
}e[MAXN << 1];
int head[MAXN], num, 
 n, 
w[MAXN],//w[i]:i结点的权重(人数)
size[MAXN];//我的所有子节点的权重包括自己权重和
long long ans = INF, f[MAXN];
inline void Add(int from, int to){
	e[++num].to = to;
	e[num].next = head[from];
	head[from] = num;
}
//u的id,u的爸爸,u与根节点1的距离
void dfs(int u, int fa, int dep){ //预处理f[1]和size
    size[u] = w[u];//先收成自己的权重 入 总权重和
	for(int i = head[u]; i; i = e[i].next){//对u的所有边遍历
	   if(e[i].to != fa)//因为是树,不能向上指
	     dfs(e[i].to, u, dep + 1),//进入下一个指向的子树根节点
          size[u] += size[e[i].to];//在上方dfs后,所有子节点的size已经算后,最后收成到自己这里来
	}
	f[1] += w[u] * dep;//main里第一次调用,初始化的是根1的距离和(sum_all_child_node{权值x距离})
}
//动态规划算出树的重心的距离和(sum_all_child_node{权值x距离})
//(传入结点,他的爸爸)
void dp(int u, int fa){  //转移
    for(int i = head[u]; i; i = e[i].next)
       if(e[i].to != fa)
         f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to, u);
    if(ans> f[u]){//取最小值
        ans=f[u];
        //ansNodeId=u;//重心的id
    }
}
int a, b;
int main(){
    //Open("hospital");
    ans *= ans;
    n = read();
    rep(i, 1, n){
       w[i] = read();
       a = read(); b = read();
       if(a) Add(i, a), Add(a, i);//虽然是树,但是他加了两边
       if(b) Add(i, b), Add(b, i);
    }
    dfs(1, 0, 0);//根节点1的爸爸是0
    dp(1, 0);
    printf("%lld\n", ans);
    //Close;
    return 0;
}