#include<bits/stdc++.h>
using namespace std;

    int n;
int usednum[10]={0};
int res[10];

void printres(){
    for(int i=0;i<n;++i){
        printf("%5d",res[i]);
    }
    putchar('\n');
}

void dfs(int nowlv){
    if(nowlv==n+1){
        printres();
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}