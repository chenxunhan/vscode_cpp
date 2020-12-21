#include <bits/stdc++.h>
#define MAX_N 10
using namespace std;

int N, day;
int tiedp[MAX_N][MAX_N];
int res[MAX_N][MAX_N];

void reset(int t[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            t[i][j] = 0;
        }
    }
}

void tieInRes() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (tiedp[i][j]) {
                res[i][day] = j;
                continue;
            }
        }
    }
}
void tie(int i, int j) {
    tiedp[i][j] = 1;
}

bool isTied(int i,int j){
    for (int di = 1; di <= day;++di){
        if(res[i][di]==j){
            return 1;
        }
    }
    return 0;
}

void f(int n) {
    for (int i = N; i >= 1;--i){
        if(!isTied(n,i)){
            
        }
    }
}
void f0(int n) {
    reset(tiedp);
    reset(res);
    day = 1;
    tie(1, n);
    for (int i = 2; i <= n - 1; ++i) {
        f(i);
    }
    tieInRes();
    reset(tiedp);
    int dtp = n - 1;
    for (++day; day <= n - 1; ++day) {
        tie(n, dtp--);
        for (int i = 2; i <= n - 1; ++i) {
            f(i);
        }
        tieInRes();
        reset(tiedp);
    }
}

int main() {
    while (1) {
        printf("please input:");
        if (~scanf("%d", &N)) {
            break;
        }
    }

    return 0;
}