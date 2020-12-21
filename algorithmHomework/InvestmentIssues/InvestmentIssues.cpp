/*写注释写到怀疑人生...*/
#include <bits/stdc++.h>
using namespace std;
const int N = 20; //定义投资项目和投资钱种的最大值

//全局变量money:钱划分种类数,item:投资项目数
//特别说明 money 钱划分种类数:效益函数的行数,不是实际的金额(从0计起)
//例如实例2的钱划分为0 10 20 30 40 50 60,钱划分种类数为6,各划分金额之间相差10万元
int money, item;
//效益函数f[x][i]:将x元投入第i项项目产生的收益
//优化函数F[x][k]:将x元投入前k项项目产生的最大收益
//标记函数x[x][k]:F[x][k]取得最大时应分配给第k个项目的金额
/**f[m][0]=F[m][0]=x[m][0]:代表实际投入的金额,0<=m<=money
如例2实际金额划分: 0       10      20      ...   60
f[m][0]   也就是: f[0][0] f[1][0] f[2][0] ... f[6][0] 
其中有个规律:实际金额/f[1][0] = m,m是数组的行下标
例如 60/f[1][0] = 60/10 = 6 = m,也就是f[6][0]放实际金额60 */
int f[N][N], F[N][N], x[N][N];

//函数返回将 money_ 对应的实际金额投入前 item_ 项项目产生的最大收益,并将结果保存在F[][]中
//同时 保存 F[x][k]取得最大时应分配给第k个项目的钱数 在标记函数x[x][k]中
//当F[][]里的数据是正确的时候,可以理解为F_(i,j)==F[i][j],一个函数返回,一个数组返回
/*理解:  当money_ = 5,对应于放在 f[money_][0]=f[5][0]中的实际金额 
在例1中 F_(5,2)代表用5 万元 投资前2项项目所获得的最大收益
在例2中 F_(5,2)代表用50万元 投资前2项项目所获得的最大收益*/
int F_(int money_, int item_) {
    //若F[][]中保存的不是-1,代表保存着正确结果,直接返回该值
    if (F[money_][item_] != -1) {
        return F[money_][item_];
    }
    //子问题边界:当投资钱数为0,返回效益0
    if (money_ == 0) {
        return F[0][item_] = 0;
    }
    //子问题边界:当所求是前1项项目的收益,记录标记函数,并返回第1项项目的收益
    if (item_ == 1) {
        x[money_][1] = F[money_][0];
        return F[money_][1] = f[money_][1];
    }
    //临时变量保存最大的收益和待保存标记函数值
    int nowF = 0, nowx;
    //分别将i钱投资给第item_项项目
    for (int i = 0, tF; i <= money_; ++i) {
        /*tF:将i元钱投资给第item_项项目的效益和
        将剩余的钱投资给前(item_-1)项项目的 效益和*/
        tF = f[i][item_] + F_(money_ - i, item_ - 1);
        if (tF > nowF) { //如果效益和大于临时效益
                         /*记入临时效益 且 
        记应给第item_项项目投资的钱i对应的实际钱数 入临时标记函数值*/
            nowF = tF, nowx = F[i][0];
        }
    }
    //临时变量保存入全局变量
    x[money_][item_] = nowx;
    return F[money_][item_] = nowF;
}

//输出效益函数
void print_f() {
    printf("f:");
    printf(" m\\i"); //m:钱,i:项目
    //[* i]:第i项投资
    for (int i = 1; i <= item; ++i) {
        printf(" [*%2d]", i);
    }
    putchar('\n');
    for (int i = 0; i <= money; ++i) {
        //[$ i]:投实际i万元钱
        printf("[$%3d]", f[i][0]);
        for (int j = 1; j <= item; ++j) {
            printf("%6d", f[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//输出优化函数
//下方对应位置同上方print_f对应位置的注释
void print_F() {
    printf("F:");
    printf(" m\\i");
    for (int i = 1; i <= item; ++i) {
        printf(" [*%2d]", i);
    }
    putchar('\n');
    for (int i = 0; i <= money; ++i) {
        printf("[$%3d]", F_(i, 0));
        for (int j = 1; j <= item; ++j) {
            printf("%6d", F_(i, j));
        }
        putchar('\n');
    }
    putchar('\n');
}

//输出标记函数
//下方对应位置同上方print_f对应位置的注释
void print_x() {
    printf("x:");
    printf(" m\\i");
    for (int i = 1; i <= item; ++i) {
        printf(" [*%2d]", i);
    }
    putchar('\n');
    for (int i = 0; i <= money; ++i) {
        printf("[$%3d]", x[i][0]);
        for (int j = 1; j <= item; ++j) {
            printf("%6d", x[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//输出投资计划,该函数在main主函数中第一次调用时形参不用赋值,使用默认值
//投资计划最终输出顺序:x1,x2,x3...
void printPlan(int money_ = money, int item_ = item, bool first = 1) {
    if (item_ == 1) { //递归终止条件:到达x1时
        printf("Plan: x1=%d", x[money_][item_], 0);
    } else {
        //先输出前一项x(item_-1)
        //x[money_][item_]/(x[1][0]):利用x[1][0]作除数把x[money_][item_]转化为数组行下标
        printPlan(money_ - x[money_][item_] / (x[1][0]), item_ - 1, 0);
        //再先输出这一项x(item)
        printf("x%d=%d", item_, x[money_][item_]);
    }
    printf(first ? ".\n\n" : ","); //如果第一次调用这个函数输出 .并换行 否则输出 ,
}

//输出实际总钱数投资分配给所有项目可获得最大收益
void printMax() {
    printf("MaxBenefit: F%d(%d)=%d\n\n", item, F[money][0], F_(money, item));
}

//初始化函数(划分钱种类数,项目总数,效益函数)
//将三个参数赋值给全局变量，供上方函数多次调用
void init(int money_, int item_, int f_[N][N]) {
    money = money_, item = item_;
    for (int i = 0; i <= money_; ++i) {
        for (int j = 0; j <= item_; ++j) {
            f[i][j] = f_[i][j];
            F[i][j] = -1;
        }
        F[i][0] = x[i][0] = f[i][0];
    }
}

int main() {
    // 实例1
    // int f_[N][N] = {{0, 0, 0, 0, 0},
    //                 {1, 11, 0, 2, 20},
    //                 {2, 12, 5, 10, 21},
    //                 {3, 13, 10, 30, 22},
    //                 {4, 14, 15, 32, 23},
    //                 {5, 15, 20, 40, 24}};
    // init(5, 4, f_); //初始化函数(划分钱总数,项目总数,效益函数)

    // //实例2
    int f_[N][N] = {{0, 0, 0, 0, 0},
                    {10, 20, 20, 25, 25},
                    {20, 50, 40, 60, 40},
                    {30, 65, 50, 85, 50},
                    {40, 80, 58, 100, 60},
                    {50, 85, 60, 110, 115},
                    {60, 85, 65, 115, 120}};
    init(6, 4, f_); //初始化函数(划分钱总数,项目总数,效益函数)

    //输出说明: 列m:钱,行i:项目  [* i]:第i项投资  [$ m]:投实际m万元钱
    print_f();   //输出效益函数
    print_F();   //输出优化函数,也就是 备忘录 或者叫 答案数组
    print_x();   //输出标记函数
    printPlan(); //输出投资计划
    printMax();  //输出最大效益
    return 0;
}
