#include <bits/stdc++.h>

using namespace std;

const int MAX = 21;
int peanut[MAX][MAX] = {0};
struct Pos {
    int x, y;
    int v;
}pos[MAX*MAX];

int M, N, K;
int maxGetNum = 0;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
 
int movNeedTime(Pos a,Pos b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
 
bool getNextCanRet(Pos nowPos,int nextGetMaxIdx,int restime){
    if(restime-movNeedTime(nowPos,pos[nextGetMaxIdx])-1-movNeedTime(pos[nextGetMaxIdx],{0,pos[nextGetMaxIdx].y,0})>=0){
        return 1;
    }
    return 0;
}

bool cmp(Pos a,Pos b){
    return a.v > b.v;
}

int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 1,posidx=0; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &peanut[i][j]);
            pos[posidx].x = i, pos[posidx].y = j;
            pos[posidx].v = peanut[i][j];
        }
    }
    sort(pos, pos + M * N, cmp);
    while(1){
        if(getNextCanRet( )){

        }
    }
    printf("%d", maxGetNum);
    return 0;
}