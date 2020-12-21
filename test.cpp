#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 100;
FILE *fpin;
int dp[MAXNUM][MAXNUM];

void init() {
    fopen("input.txt", "r");
    for(int i=0,dp_; i<MAXNUM; ++i){
        for(int j=0; j<MAXNUM; ++j){
            fscanf(fpin, "%d", &dp_);
            dp[i][j] = dp_;
        }
    }
}
int main(int argc, char **argv) {
}