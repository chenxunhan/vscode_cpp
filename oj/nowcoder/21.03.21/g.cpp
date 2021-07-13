#include<bits/stdc++.h>
using namespace std;

int num;
// [i][j]:Ç°i¸ö
double dp[102][102]={0};
double P[102]={0},P2[102]={0};

bool cmp(double a, double b){
    return a > b;
}

int main(){
    scanf("%d", &num);
    for (int i = 1; i <= num;++i){
        scanf("%lf", P+i);
    }
    sort(P + 1, P + num + 1, cmp);
    for (int i = 1; i <= num;++i){
        P[i] /= 100.0;
        P2[i] = 1 - P[i];
    }
    double ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= num;++i){
        dp[i][0] = dp[i - 1][0] * (P2[i]);
        for (int j = 1; j <= i;++j){
            dp[i][j] = dp[i - 1][j] * P2[i] + dp[i - 1][j - 1] * P[i];
        }
        double now = 0;
        for(int j = 1; j <= i; ++j){
            now += dp[i][j] * pow(j, 1.0 * j / i);
        }
        ans = max(ans, now);

    }
    printf("%.9lf\n",ans);
        return 0;
}