//8
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;
const int MAX = 1005;

//[head][len]
int dp[MAX][MAX] = {0};

int length, nmax;

int jidp(int head, int len) {
    if (dp[head][len]) {
        return dp[head][len];
    }
    if (len == 1) {
        dp[head][1] = 1;
        return 1;
    }
    if (len & 1) { //ji>
        if (head == 2) {
            dp[head][len] = (jidp(head - 1, len - 1)) % MOD;
            return dp[head][len];
        }
        dp[head][len] = (jidp(head - 1, len - 1) + jidp(head - 1, len)) % MOD;
    } else { //ou<
        if (head == nmax - 1) {
            dp[head][len] = (jidp(head + 1, len - 1)) % MOD;
            return dp[head][len];
        }
        dp[head][len] = (jidp(head + 1, len - 1) + jidp(head + 1, len)) % MOD;
    }
    return dp[head][len];
}

int oudp(int head, int len) {
    if (dp[head][len]) {
        return dp[head][len];
    }
    if (len == 1) {
        dp[head][1] = 1;
        return 1;
    }
    if (len & 1) { //ji<
        if (head == nmax - 1) {
            return oudp(head + 1, len - 1);
        }
        dp[head][len] = (oudp(head + 1, len - 1) + oudp(head + 1, len)) % MOD;
    } else { //ou>
        if (head == 2) {
            return oudp(head - 1, len - 1);
        }
        dp[head][len] = (oudp(head - 1, len - 1) + oudp(head - 1, len)) % MOD;
    }
    return dp[head][len];
}

int main() {
    //第一个>...
    //第一个[2,n]
    int sum;
    scanf("%d%d", &length, &nmax);
    sum = 0;
    if (length & 1) { //ji//倒数<尾
        for (int i = 2; i <= nmax; ++i) {
            sum += jidp(i, length);
        }
        cout << sum << endl;
    } else { //ou//倒数>尾
        for (int i = 2; i <= nmax; ++i) {
            sum += oudp(i, length);
        }
        cout << sum << endl;
    }
    return 0;
}