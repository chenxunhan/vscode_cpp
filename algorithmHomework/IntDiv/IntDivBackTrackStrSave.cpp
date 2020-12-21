#include <bits/stdc++.h>
using namespace std;

//保存当前选择出的整数划分式的各个常数项
// int a = 0, b = 0;
int res[100];
string restr;
//待划分的整数,划分的种类和
int n, sum;
//用于区分是否要格式化输出特殊格式
bool isanother = 1;

//输出res[]中合法的整数划分式,len是式子的长度
void print(int len) {
    if (isanother == 1) { //是否已经准备输出新的一行
        printf("%d=", n);
        isanother = 0;
    }
    for (int i = 0; i < len - 1; ++i) { //依次输出各个常数项
        printf("%d+", res[i]);
    }
    printf("%d", res[len - 1]);
    ++sum;
    if (res[1] == 1 || len == 1) { //若对于应居于一行的答案式子已经全部输出
        if (res[0] == 1)
            printf(".\n");
        else
            printf(";\n");
        isanother = 1;
        return;
    }
    printf(","); //若对于应居于一行的答案式子还未全部输出
}

//整数划分函数
//rest是当前待划分的数
//len是res中所有数字的长度+1
//mindiv是再划分的数字中的最大限制数
void IntDiv(int rest, int len, int mindiv) {
    if (rest == 0) { //如果数字已经划分完毕
        print(len);  //输出式子
        return;
    }
    for (int i = min(rest, mindiv); i >= 1; --i) {   //遍历可划分的数字的所有情况
        res[len] = i;                                //答案数字进栈res
        IntDiv(rest - i, len + 1, min(rest - i, i)); //回溯进入下一层
        //上一行三个参数说明(剩余待划分的数,数字进栈后长度+1,再划分的数字中的最大限制数)
        res[len] = 0; //回溯退出，选择的数字出栈
    }
}

void savestr(int len) {
    if (isanother == 1) { //是否已经准备输出新的一行
        // printf("%d=", n);
        restr += to_string(n) + "=";
        isanother = 0;
    }
    for (int i = 0; i < len - 1; ++i) { //依次输出各个常数项
        // printf("%d+", res[i]);
        restr += to_string(res[i]) + "+";
    }
    // printf("%d", res[len - 1]);
    restr += to_string(res[len - 1]);
    ++sum;
    if (res[1] == 1 || len == 1) { //若对于应居于一行的答案式子已经全部输出
        if (res[0] == 1)
            // printf(".\n");
            restr += ".\n";
        else
            // printf(";\n");
            restr += ";\n";
        isanother = 1;
        return;
    }
    // printf(","); //若对于应居于一行的答案式子还未全部输出
    restr += ",";
}

void IntDiv2(int rest, int len, int mindiv) {
    if (rest == 0) {  //如果数字已经划分完毕
        savestr(len); //输出式子
        return;
    }
    // ++a;
    for (int i = min(rest, mindiv); i >= 1; --i) { //遍历可划分的数字的所有情况
        res[len] = i;                              //答案数字进栈res
        // ++b;
        IntDiv2(rest - i, len + 1, i); //回溯进入下一层
        //上一行三个参数说明(剩余待划分的数,数字进栈后长度+1,再划分的数字中的最大限制数)
        res[len] = 0; //回溯退出，选择的数字出栈
    }
}

int main() {
    while (1) {
        printf("输入待划分数:");
        sum = 0; //划分种类数清零
        // a = b = 0;
        if (!(~scanf("%d", &n)))
            break;
        double time0 = clock();
        IntDiv2(n, 0, n);
        printf("%s", restr.c_str());
        printf("划分数可划分的式子种类个数:%d\n", sum);

        printf("%lf\n", (double) ((clock() - time0) / CLOCKS_PER_SEC));
        // cout << a << "+" << b;
        putchar('\n');
    }

    return 0;
}