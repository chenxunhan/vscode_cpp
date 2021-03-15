#include<cstdio>
#include<algorithm>

using namespace std;
int n, a, b;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        scanf("%d%d", &a, &b);
        printf("Circus Act %d:\n",i);
        if(2*b>5*a){
            printf("Chester can do it!\n");
        }else{
            printf("Chester will fail!\n");
        }
        putchar('\n');
    }
        return 0;
}