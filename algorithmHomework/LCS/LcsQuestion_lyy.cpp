#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char x[] = "_ABCBDAB", y[] = "_BDCABA";
int max(int a, int b) {
    //标记为1的是取了上面的值，标记为2的是取了左边 。
    //这里a是左面的值，b是上边的值

    return (a > b ? a : b);
}

//判断并得出结果。
void Consequence(int **a, int i, int j) //把mem数组传进去,第一次传进去的参数i，j 分别是xl-1，yl-1.
{
    int m = i, n = j;
    if (a[m][n] == 0) {
        return;
    }

    if (a[m][n] == 1) //向上
    {
        m = m - 1; //行减一，列不变
        n = n;
        Consequence(a, m, n); //递归
    } else if (a[m][n] == 2)  //向左
    {
        m = m;
        n = n - 1;
        Consequence(a, m, n); //递归
    } else if (a[m][n] == 3)  //斜向上
    {
        m = m - 1;
        n = n - 1;
        Consequence(a, m, n); //递归 S
        //遇到斜向上的要标记下来
        printf("%c", x[m - 1]);
    } else {
        Consequence(a, m, n);
    }
}

int main() {
    //方便处理后面的数据，这里的x[0]和y[0]用“_”（下划线）冲掉。

    int x_len = sizeof(x); //取数组长度
    int y_len = sizeof(y);

    int i, j; //定义横纵下标

    int c[x_len][y_len], mem[x_len][y_len];
    for (i = 0; i <= x_len; i++)
        for (j = 0; j <= y_len; j++) {
            c[i][j] = 0;
            mem[i][j] = 0;
        } //初始化数组

    //!!!!!!?为什么直接 int c[x_len][y_len],mem[x_len][y_len]这样定义数组会有问题。

    //直接初始化为0，则方便了不用考虑i=0 or j=0 时候c[i][j]=0的情况了。
    //横向遍历规则输数。

    for (i = 1; i < x_len - 1; i++) {
        for (j = 1; j < y_len - 1; j++) {
            if (x[i] == y[j]) //直接从第二种情况开始考虑。
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                mem[i][j] = 3;
                //记录函数数组，此时记录是3，为取了对角边上的值 。

            } else if (x[i] != y[j]) {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]); //两字母或者数字不相同时候，取该数的左方和上方的最大值，用一个max函数
                if (c[i][j] == c[i][j - 1])              //如果取到左边，标记左
                {
                    mem[i][j] = 1;
                    //记录函数数组，此时记录是2，为取了左边值 。
                } else { //取到上方标记上
                    mem[i][j] = 2;
                    //记录函数数组，此时记录是1，为取了上边值 。
                }
            }
        }
    }
    //		Printfmem();打印标记函数
    printf("\n");
    printf("*************************************************\n");
    printf("\n");
    printf("这是标记函数：\n");
    printf("其中，3代表取对角线的值，2代表取左边的值，1代表取上方的值\n");
    for (i = 0; i < x_len - 1; i++) {
        for (j = 0; j < y_len - 1; j++) {
            printf("%4d", mem[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("*************************************************\n");

    //	PrintfC();打印存储函数
    printf("*************************************************\n");
    printf("\n");
    printf("这是储存函数：\n");

    for (i = 0; i < x_len - 1; i++) {
        for (j = 0; j < y_len - 1; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("*************************************************\n");
    printf("\n");

    //输出结果，对标记函数做出判断。
    printf("输出结果：\n");
    //Consequence(int **a,int i,int j)
    Consequence((int **) mem, x_len, y_len);

    return 0;
}
