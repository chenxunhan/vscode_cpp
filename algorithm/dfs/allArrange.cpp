#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int mx;
int res[N];
bool used[N];

void printres() {
    for (int i = 0; i < mx; ++i) {
        printf("%d ", res[i]);
    }
    putchar('\n');
}

//level  num
void f(int l) {
    if (l == mx + 1) {
        printres();
    }
    for (int i = 0; i <= mx; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            res[l] = i;
            f(l + 1);
            used[i] = 0;
        }
    }
}

//a from 0
void allArrange(const int a, const int b) {
    memset(used, 0, sizeof(used));
    mx = b;
    f(0);
}

int main() {
    allArrange(0, 3);
    return 0;
}

dfs(){
    if(到底){
        //答案操作
        return;
    }
    if(越界不合法)
        return;
    if(特殊状态)//剪枝
        return;
    for(扩展方式){
        if(扩展方式合法 未被标记){
            标记
            加入答案
            回溯下一层
            撤销标记和答案
        }
    }
}