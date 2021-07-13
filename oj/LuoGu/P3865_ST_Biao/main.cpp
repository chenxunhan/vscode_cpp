#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5,MAXM=20;
int n,m;
int dpmx[MAXN][MAXM];
int a[MAXN];//存放每个点的值

void get_dp(){
    for(int i=1;i<=n;i++) dpmx[i][0]=a[i];
    for(int j=1;j<=MAXM;j++)
        for(int i=1;i+(1<<j)-1<=n;i++) 
             dpmx[i][j]=max(dpmx[i][j-1],dpmx[i+(1<<(j-1))][j-1]);
}

int rmq(int a,int b){
    int k=log(b-a+1)/log(2);
    return max(dpmx[a][k],dpmx[b-(1<<k)+1][k]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    get_dp();
    int a,b;
    while(m--){
        scanf("%d%d",&a,&b);
        printf("%d\n",rmq(a,b));
    }

    return 0;
}
