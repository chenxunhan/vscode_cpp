#include <bits/stdc++.h>
#define N 50 //定义最大矩阵链长度
using namespace std;

int n; //全局变量保存待计算的矩阵链长度

//m[i][j]作为函数备忘录代表矩阵链 Ai A(i+1)...A(j-1) Aj 的最小运算次数
//s[i][j]作为标记函数代表矩阵链 Ai A(i+1)...A(j-1) Aj 的最后一次分割位置
int m[N][N], s[N][N];

//l[i]代表矩阵链 A1 A2 A3...An 的第i个空格位置应放置l[i]个 左括号(,其中i从0开始计起
//r[i]代表矩阵链 A1 A2 A3...An 的第i个空格位置应放置r[i]个 右括号),其中i从0开始计起
int l[N], r[N];

//P[]代表矩阵链向量,n代表待计算的矩阵链长度
//函数输出函数备忘录、标记函数、答案表达式以及矩阵链计算最少次数
void RecurMatrixChain(int P[]) {
    //函数备忘录和标记函数清空
    memset(m, 0, sizeof(m)), memset(s, 0, sizeof(s));
    //令所有m[i][i]初值为0,s[i][i]为i,1<=i<=n,这也是矩阵链长度为1的情况
    for (int i = 1; i <= n; ++i)
        m[i][i] = 0, s[i][i] = i;
    //len为当前计算的链长(子问题规模)
    for (int len = 2; len <= n; ++len) {
        //n-len+1为最后一个len链的前边界
        for (int idx1 = 1; idx1 <= n - len + 1; ++idx1) {
            //计算前边界为idx1,长为len链的矩阵链后边界idx2
            int idx2 = idx1 + len - 1;
            m[idx1][idx2] = INT_MAX;                 //设置当前计算的链的最小运算次数为无穷大
            for (int k = idx1; k <= idx2 - 1; ++k) { //划分
                int now = m[idx1][k] +
                          m[k + 1][idx2] +
                          P[idx1 - 1] * P[k] * P[idx2]; //划分位置(Aidx1 ... Ak)(Ak+1 ... Aidx2)
                if (m[idx1][idx2] > now) {
                    m[idx1][idx2] = now, s[idx1][idx2] = k; //用更好的值替换
                }
            }
        }
    }
}

//输出函数备忘录m[][]
void printm() {
    printf("函数备忘录:\n  m:");
    for (int i = 1; i <= n; ++i) {
        printf("    [%2d]", i);
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i) {
        printf("[%2d]", i);
        for (int j = 1; j <= n; ++j) {
            printf("%8d", m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//输出标记函数s[][]
void prints() {
    printf("  标记函数:\n  s:");
    for (int i = 1; i <= n; ++i) {
        printf("    [%2d]", i);
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i) {
        printf("[%2d]", i);
        for (int j = 1; j <= n; ++j) {
            printf("%8d", s[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//该函数输出n个字符c
void printChar(char c, int n) {
    while (n--)
        putchar(c);
}

//函数innerlr为矩阵链 Aa A(a+1)...A(b-1) Ab 表达式的前后两端加上括号()
//并利用标记函数在矩阵链的内部分割处继续递归加入括号
//加入的(括号会保存在l[]中,加入的)括号会保存在r[]中
//l[i]代表矩阵链 A1 A2 A3...An 的第i个空格位置应放置l[i]个(,其中i从0开始计起
//r[i]代表矩阵链 A1 A2 A3...An 的第i个空格位置应放置r[i]个),其中i从0开始计起
void innerlr(int a, int b) {
    if (a == b) //递归终止条件:当矩阵链的长度为1时，不加括号并退出函数
        return;
    ++l[a], ++r[b + 1];      //为矩阵链的前后两端加上括号()
    innerlr(a, s[a][b]);     //为矩阵链分割位置前部分两端加上括号()并递归
    innerlr(s[a][b] + 1, b); //为矩阵链分割位置后部分两端加上括号()并递归
}

//输出带有括号的矩阵链答案表达式
void printres() {
    //清空矩阵链各位置所需要的左括号和右括号数目
    memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));

    //第一次使用innerlr函数会给计算的矩阵链两端不必要地加上括号
    //因此需要撤销该次操作,将两端需要输出的左右括号数目设置为-1
    l[1] = r[n + 1] = -1;
    innerlr(1, n);

    printf("矩阵链带括号的表达式答案:");
    for (int i = 1; i <= n; ++i) { //遍历每个位置
        printChar(')', r[i]);      //输出该位置所需要的右括号)数目
        printChar('(', l[i]);      //输出该位置所需要的左括号(数目
        printf("A%d", i);          //输出该位置的矩阵Ai
    }
    printChar(')', r[n + 1]); //输出末端位置所需要的右括号)数目
    printf("\n最少运算次数:%d\n\n", m[1][n]);
}

void printP(int P[]) {
    printf("P<");
    for (int i = 0; i < n; ++i) {
        printf("%d,", P[i]);
    }
    printf("%d>\n\n", P[n]);
}

int main() {
    // int n0 = 2, P[] = {30, 35, 15};
    // int n0 = 5, P[] = {30, 35, 15, 5, 10, 20};
    int n0 = 6, P[] = {20, 70, 25, 30, 5, 35, 10};
    n = n0;              //赋值全局变量保存待计算的矩阵链长度,方便后续函数使用
    printP(P);           //输出待计算矩阵向量P
    RecurMatrixChain(P); //矩阵链计算打表
    printm();            //输出备忘录
    prints();            //输出标记函数
    printres();          //输出答案
    return 0;
}