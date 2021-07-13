#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100+5;

struct Edge{
	int next, to;
}e[MAXN];//���ı�=node_num-1
int head[MAXN],cnt=0;  //head[]����Ƚ�����,����ָ��0����-1

int n;
int w[MAXN],//w[i]:i����Ȩ��(����)
size[MAXN];//�ҵ������ӽڵ��Ȩ�ذ����Լ�Ȩ�غ�
long long ans = INT_MAX, f[MAXN];

bool add_edge(int from, int to){
	e[++cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;
}

//u��id,u�İְ�,u����ڵ�1�ľ���
void dfs(int u, int dep){ //Ԥ����f[1]��size
    size[u] = w[u];//���ճ��Լ���Ȩ�� �� ��Ȩ�غ�
	for(int i = head[u]; i; i = e[i].next){//��u�����б߱���
	     dfs(e[i].to,  dep + 1),//������һ��ָ����������ڵ�
          size[u] += size[e[i].to];//���Ϸ�dfs��,�����ӽڵ��size�Ѿ����,����ճɵ��Լ�������
	}
	f[1] += w[u] * dep;//main���һ�ε���,��ʼ�����Ǹ�1�ľ����(sum_all_child_node{Ȩֵx����})
}

//��̬�滮����������ĵľ����(sum_all_child_node{Ȩֵx����})
//(������,���İְ�)
void dp(int u){  //ת��
    for(int i = head[u]; i; i = e[i].next)
         f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to);
    if(ans> f[u]){//ȡ��Сֵ
        ans=f[u];
        //ansNodeId=u;//���ĵ�id
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,a,b;i<=n;++i){
        scanf("%d%d%d",w+i,&a,&b);
       a && add_edge(i, a);
       b && add_edge(i, b);
    }
    dfs(1, 0);//���ڵ�1�İְ���0
    dp(1);
    printf("%lld\n", ans);
    return 0;
}