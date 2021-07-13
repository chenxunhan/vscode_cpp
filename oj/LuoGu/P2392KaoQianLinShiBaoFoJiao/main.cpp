#include <bits/stdc++.h>
using namespace std;

int len[4];
int sub[30];
int f[21][1201];

int main() {
    for (int i = 0; i < 4; ++i) {
        scanf("%d", len + i);
    }
    int tot = 0;
    for (int i = 0; i < 4;++i){
        int v = 0;
        for (int j = 1;j<=len[i];++j){
            scanf("%d", sub + j);
            v+=sub[j];
        }
        int t1 = 0;
        for (int j = 1; j <= len[i];++j){//前j个作业
            for (int k = 0; k <= v / 2;++k){//剩余时
                f[j][k] = f[j - 1][k];
                if(k>=sub[j]){
                    f[j][k]=max(f[j][k],f[j-1][k-sub[j]]+sub[j]);
                }
                t1 = max(f[j][k], t1);
            }
        }
        tot += v - t1;
    }
    printf("%d", tot);
    return 0;
}