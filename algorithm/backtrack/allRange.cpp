// 20.9.13
// 在了解完回溯算法之后
// 自己解决了全排列问题
// 目标是为了解决整数划分问题

/*1
#include <bits/stdc++.h>
#define N 5
using namespace std;

int a[N] = {1, 2, 3, 4, 5};
bool dp[N] = {0};
int res[N];
int sumdp() {
    int sum = 0;
    for (bool i : dp) {
        sum += i;
    }
    return sum;
}

void print() {
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    cout << endl;
}

void f(int n) {
    if (sumdp() == N) {
        print();
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (dp[i] == 0) {
            dp[i] = 1;
            res[sumdp() - 1] = a[i];
            f(i);
            dp[i] = 0;
            res[sumdp()] = 0;
        }
    }
}*/

#include <bits/stdc++.h>
#define N 4
using namespace std;

int a[N] = {1, 2, 3, 4}; //准备排列的数字
bool dp[N] = {0};        //记录数字是否被用过
int res[N];              //记录当前选择的数组排列序列
int sumdp = 0;           //记录当前选择用过的数字有多少个

void print() { //输出答案res
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    cout << endl;
}

void f(int n) {       //n是指a[]中的指向数字的下标，就是当前选择数字的下标
    if (sumdp == N) { //如果已经选择了全部的数字，输出答案
        print();
        return;
    }
    for (int i = 0; i < N; ++i) { //一个一个选下去，看图理解会好点https://www.cnblogs.com/blogtech/p/12295551.html
        if (!dp[i]) {             //没被选过的话，开始选
            dp[i] = 1;
            res[sumdp] = a[i];
            ++sumdp;
            f(i);      //进入回溯
            dp[i] = 0; //退出回溯时撤销选择
            --sumdp;
            res[sumdp] = 0;
        }
    }
}

int main() {
    f(0);
    return 0;
}