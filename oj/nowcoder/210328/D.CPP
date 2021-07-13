#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1e9+5;

int n,nt;
bool b[MAXSIZE];

int f(int x){
    int t,sum=0;
    while(x){
        t = x % 10;
        
    sum += t * t;
        x /= 10;
    }
    return sum;
}
bool res=1;
int main() {
    scanf("%d", &n);
    b[n] = 1;
    while(b[1]==0){
        nt = f(n);
        if(b[nt]==0){
            b[nt] = 1;
        }else{
            printf("UNHAPPY");
            res = 0;
            break;
        }
        n = nt;
    }
    if(res==1)
    printf("HAPPY");
    return 0;
}