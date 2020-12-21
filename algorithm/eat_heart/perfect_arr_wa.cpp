//完美的数组 第 2773 题
//陈逊瀚
/*
0 1 2 3 4 5 6 7 8
 1 1 1 1 1 1 1 1


0 1 1 2 4 4 5 6 7 8
 0 1 1 2 0 1 1 1 1
增见0，若0前-1正，可

原：0 1 2 4 4 5 6 7 8
差： 1 1 2 0 1 1 1 1
增见0，若0前-1正 且 原数非0，可

0 1 2 2 4 5 6 7 8
 1 1 0 2 1 1 1 1
增见0，若0前-1非正，不可

4 4 5 6 6 10 12 14 16
 0 1 1 0 4  2  2  2
增见0，若00间全部>=1且最大>=2，可(上不可)

9  8 8  7  5 5
 -1 0 -1 -2 0

3 4 4 6 6 10 12 14 16
 1 0 2 0 4  2  2  2
增见0，若00间全部>=1且最大>=2，可

4 5 5 6 6 10 12 14 16
 1 0 1 0 4  2  2  2
增见0，若00间全部>=1，可

bool = false;
<=0 7 8 9 9 
 0 1 2 0 -1 -1 -1 -2 0

int zhuang -1 0 1

完美性是全局变量bool
一开头直接设置此段到后面的完美性为true，
{若差数组进一个0,
若前面的完美性为false,原数组不是完美并输出no，否则完美进入下一步
设置此段到后面的完美性为false，}
若差数组进一个+,进入增部分，
若差数组进一个-,进入减部分，
遇到尾部直接输出yes

增部分：
{}
在遇到下一个0前，一旦遇到>=2的数，设置完美性为true,
遇到负数直接进入减部分判断

减部分：
{}
在遇到下一个0前，一旦遇到<=-2的数，设置完美性为true,
遇到正数直接输出no
*/
#include <bits/stdc++.h>
using namespace std;
//两个循环优化
//不用数组
bool perfect = true;
int up_down; //up=0,down=1
int n;
int arr[100001], diff[100000];

bool diff_fc(int i) {
    if (i == 0) {
        return true;
    }
    if (diff[i] == 0) {
        if (perfect == false) {
            return false;
        }
        perfect = false;
        return true;
    }
    if (diff[i] > 0) {
        if (up_down == 1) {
            return false;
        }
        up_down = 0;
    } else {
        if (up_down == 0) {
            return false;
        }
        up_down = 1;
    }
    if (up_down == 0) {
        if (diff[i] >= 2) {
            perfect = true;
        }
    } else if (up_down == 1) {
        if (diff[i] <= -2) {
            perfect = true;
        }
    }
    return true;
}

int main() {
    int t = 0;
    while (~scanf("%d", &n)) {
        t = 0;
        perfect = true;
        up_down = -1;
        for (int ni = 1; ni <= n; ++ni) {
            scanf("%d", arr + ni);
            diff[ni - 1] = arr[ni] - arr[ni - 1];
            if (diff_fc(ni - 1) == false && t == 0) {
                printf("No\n");
                t = 1;
            } else if (ni >= n && t == 0) {
                printf("Yes\n");
                t = 1;
            }
        }
    }
    return 0;
}
