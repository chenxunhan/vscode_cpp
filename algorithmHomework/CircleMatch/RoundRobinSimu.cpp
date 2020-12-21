#include <bits/stdc++.h>
#define N 50 //最大的参赛队数
using namespace std;

//a[]放算法循环圈的各个队伍号,res[][]放答案
//res[0][j]放队伍号j
//res[i][j]放第i队第j天对战的队伍号
int a[N], res[N][N];
//n0放输入的队伍数,n放算法循环圈的上的队伍数,day表示当前是第几天对战
int n0, n, day;

//保存当日的对阵的答案
void saveRes() {
    for (int i = 0; i <= n >> 1; ++i) { //n>>1等价于n/2
        res[a[i]][day] = a[n - i];
        res[a[n - i]][day] = a[i];
    }
}

//将算法循环圈上的队伍循环顺时针轮转一遍
void Round() {
    int tail = a[n - 1];
    for (int i = n - 1; i; --i)
        a[i] = a[i - 1];
    a[0] = tail;
}

//输出res答案并格式化输出
void print() {
    if (n0 & 1) //如果队伍数为奇数,输出提示信息“0代表该天该队轮空”
        printf("0 means empty\n");
    printf("Date  :\t");
    for (int i = 1; i <= day; ++i) { //第一行输出天数
        printf("%d\t", i);
    }
    putchar('\n');
    for (int i = 1; i <= n0; ++i) {
        printf("Team%2d:\t", i); //输出第i对的对阵
        for (int j = 1; j <= day; ++j) {
            printf("%d\t", res[i][j]);
        }
        putchar('\n');
    }
}

//输出对阵表函数
void roundRobin() {
    // n = n0 - !(n0 & 1);           //依据参赛队数设置算法循环圈上的队伍数,奇数不变,偶数-1
    n = n0 - 1 | 1;
    a[n] = (n0 & 1) ? 0 : n + 1; //当参赛对数为奇数,算法循环圈a[]的最后位为0(轮空),否则放最后一队
    for (day = n; day; --day)    //给算法循环圈a[]放置队伍
        a[day - 1] = day;
    //上面for循环结束后day==0
    while (++day) {   //day随着对战天数自增,且作为while的循环永真条件
        saveRes();    //保存当天对阵答案
        if (day == n) //如果天数已到达上限退出
            break;
        Round(); //循环圈队伍顺时针循环
    }
    print(); //输出对阵表
}

int main() {
    while (1) {
        printf("input team nums(1<n<%d):", N);
        if (!(~scanf("%d", &n0)))
            break;
        roundRobin();
        putchar('\n');
    }
    return 0;
}

/*鍥犱负寰幆鏁扮粍
#include <bits/stdc++.h>
#define N 20
using namespace std;

bool odd;
int a[N];
int res[N][N];
int n0, n, day;

int *newarptr(int len, int nidx, int idx) {
    return a + (nidx + idx + len) % len;
}

void saveRes() {
    for (int i = 0; i <= n / 2; ++i) {
        int a0 = *newarptr(odd ? n0 : n0 - 1, 1 - day, i),
            a1 = *newarptr(odd ? n0 : n0 - 1, 1 - day, n - i);
        res[a0][day] = a1,
        res[a1][day] = a0;
    }
}
// void saveRes() {
//     for (int i = 0; i <= n / 2; ++i) {
//         res[a[i]][day] = a[n - i];
//         res[a[n - i]][day] = a[i];
//     }
// }

void Round() {
    int len = n;
    int tail = a[len - 1];
    for (int i = len - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = tail;
}
void print() {
    for (int i = 1; i <= n0; ++i) {
        for (int j = 0; j <= day; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void roundRobin() {
    odd = (n0 & 1);
    n = odd ? n0 : n0 - 1, a[n] = odd ? 0 : n + 1;
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    // day = n;
    // while (--day)
    //     a[day - 1] = day;
    // while (++day) {
    day = 1;
    while (1) {
        saveRes();
        if (day == (odd ? n0 : n0 - 1))
            break;
        // Round();
        ++day;
    }
    print();
}

int main() {
    for (int i = 1; i < N; ++i)
        res[i][0] = i;
    n0 = 8;
    roundRobin();
    // while (1) {
    //     printf("please input(1<n<%d):", N);
    //     if (!(~scanf("%d", &n0)))
    //         break;
    //     roundRobin(n0);
    // }
    return 0;
}
*/

/*
#include <bits/stdc++.h>
#define N 20
using namespace std;

int to_n(int n0) {
    if (n0 & 1)
        return n0;
    return --n0;
}

int a[N] = {0};
int res[N][N] = {0};
int n0, n, day = 1;

void saveRes(int a[]) {
    for (int i = 0; i <= n / 2; ++i) {
        res[a[i]][day] = a[n - i];
        res[a[n - i]][day] = a[i];
    }
}

void Round(int a[]) {
    int len = n;
    int tail = a[len - 1];
    for (int i = len - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = tail;
}
void print() {
    for (int i = 1; i <= n0; ++i) {
        res[i][0] = i;
    }
    for (int i = 1; i <= n0; ++i) {
        for (int j = 0; j <= day; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void f() {
    bool odd = n0 & 1;
    n = to_n(n0);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    if (!odd) {
        a[n] = n + 1;
    } else {
        a[n] = 0;
    }
    // for (int i = 0; i < n0; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    while (1) {
        saveRes(a);
        if (a[0] == 2)
            break;
        Round(a);
        // for (int i = 0; i < n0; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        ++day;
    }
}

int main() {
    n0 = 5;
    f();
    print();
    return 0;
}
*/