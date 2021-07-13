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
w[MAXN],//w[i]:i����Ȩ��(����)
size[MAXN];//�ҵ������ӽڵ��Ȩ�ذ����Լ�Ȩ�غ�
long long ans = INF, f[MAXN];
inline void Add(int from, int to){
	e[++num].to = to;
	e[num].next = head[from];
	head[from] = num;
}
//u��id,u�İְ�,u����ڵ�1�ľ���
void dfs(int u, int fa, int dep){ //Ԥ����f[1]��size
    size[u] = w[u];//���ճ��Լ���Ȩ�� �� ��Ȩ�غ�
	for(int i = head[u]; i; i = e[i].next){//��u�����б߱���
	   if(e[i].to != fa)//��Ϊ����,��������ָ
	     dfs(e[i].to, u, dep + 1),//������һ��ָ����������ڵ�
          size[u] += size[e[i].to];//���Ϸ�dfs��,�����ӽڵ��size�Ѿ����,����ճɵ��Լ�������
	}
	f[1] += w[u] * dep;//main���һ�ε���,��ʼ�����Ǹ�1�ľ����(sum_all_child_node{Ȩֵx����})
}
//��̬�滮����������ĵľ����(sum_all_child_node{Ȩֵx����})
//(������,���İְ�)
void dp(int u, int fa){  //ת��
    for(int i = head[u]; i; i = e[i].next)
       if(e[i].to != fa)
         f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to, u);
    if(ans> f[u]){//ȡ��Сֵ
        ans=f[u];
        //ansNodeId=u;//���ĵ�id
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
       if(a) Add(i, a), Add(a, i);//��Ȼ����,��������������
       if(b) Add(i, b), Add(b, i);
    }
    dfs(1, 0, 0);//���ڵ�1�İְ���0
    dp(1, 0);
    printf("%lld\n", ans);
    //Close;
    return 0;
}