#include<bits/stdc++.h>
using namespace std;

int N,n,t;
unordered_map<int,bool> m; 
int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        while(n--){
            scanf("%d",&t);
            if(!m[t]){
                m[t]=1;
                printf("%d ",t);
            }
        }
        puts("");
        m.clear();
    }
    return 0;
}