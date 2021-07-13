//BingChaJi.cpp
#include<cstdio>
#include<algorithm>

const int MAXN=1e4+5,MAXM=2e5+5;
int fa[MAXN]; //存储每个点的祖宗节点
int n,m;
// 返回x的祖宗节点
int find(int x)    {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

// 初始化，假定节点编号是1~n
bool init_set(){
  for (int i = 1; i <= n; i ++ ) fa[i] = i;
}
// 合并a和b所在的两个集合：
bool union_set(int a,int b){
  fa[find(a)] = find(b);
}

bool print_is_same(int x,int y){
	if(find(x)==find(y)){
		printf("Y\n");
	}else{
		printf("N\n");
	}
}

int main(){
  scanf("%d%d",&n,&m);
  init_set();
  for(int i=1,z,x,y;i<=m;++i){
    scanf("%d%d%d",&z,&x,&y);
    --z;
	z?print_is_same(x, y):union_set(x, y);
  }
  return 0;
}