

#include <bits/stdc++.h>
/*宏定义for 为 loop,减少打字数  
register将int放入寄存器，提高变量操作速度*/
#define loop(i, x, y) for (register int i = x; i <= y; ++i)
using namespace std;
const int N = 100; //序列分最大长度为100

//m:X序列的长度  n:Y序列的长度
int m, n;
//X: X序列字符存放数组，Y: Y序列字符存放数组
char X[N], Y[N];
//优化函数C[i][j]: Xi与Yj的最长公共子序列长度,C[m][n]就是最终答案 X序列和 Y序列的最长公共子序列的长度
int C[N][N];
/*标记函数B[i][j]: Xi与Yj的最长公共子序列元素选取信息,
用于下方函数 StructureSequence() 从 B[m][n]向 B[0][0]回溯时找到最长公共子序列的各位字符
放置的字符只有三种('z','s','x'),
衍生信息(放置字符——回溯方向——回溯方向符号)'z'——左——'←','s'——上——'↑','x'——斜——'↖'  */
char B[N][N];

/* 初始化函数，赋值序列长度到全局变量m n，把字符串X_和Y_放到全局字符数组X[1~m],Y[1~n]中，方便后方函数使用
使得X[i]放的是X序列的第i个字符，因为现实序列没有第0个字符，因此X[0]存放的信息无效，Y[]同理*/
void init(const string &X_, const string &Y_) {
    m = X_.size(), n = Y_.size(); //XY序列长度赋值
    loop(i, 1, m)                 //X序列字符赋值
        X[i] = X_[i - 1];
    loop(i, 1, n) //Y序列字符赋值
        Y[i] = Y_[i - 1];
}

// 输出XY序列初始信息
void print_mes() {
    printf("X_length:%2d, X: %s\n", m, X + 1),
        printf("Y_length:%2d, Y: %s\n\n", n, Y + 1);
}

//打出优化函数C[][]表
void LCS() {
    C[0][0] = 0; //第0行第0列为0，即X Y序列长度都为0时最长公共子序列长度为0
    /*下方2层loop本质:从 X1-Y1 按右到下顺序遍历到 Xm-Yn ,
	Xi-Yj代表当前准备计算 长度为i的X序列[X0~Xi]和 长度为j的Y序列[Y0~Yj] 的最长公共子序列的长度,
	遍历不从0开始从1开始解释:因为X0-Y? 或 X?-Y0(?是任意合法取值)是计算长度为0的序列,都是0不用遍历计算*/
    loop(i, 1, m) {             //i是X序列的字符遍历变量,到X长度m结束
        C[i][0] = 0;            //初始化C[][]第0列为0，即Y序列长度为0时最长公共子序列长度为0
        loop(j, 1, n) {         //j是Y序列的字符遍历变量,到Y长度n结束
            C[0][i] = 0;        //初始化C[][]第0行为0，即X序列长度为0时最长公共子序列长度为0
            if (X[i] == Y[j]) { //若X第i个字符与Y第j个字符相等,该字符要加入LCS
                //LCS长度+1
                C[i][j] = C[i - 1][j - 1] + 1,
                B[i][j] = 'x'; //记录回溯的时候往 左上方向回溯
                continue;
            } //上方continue代替此处else ,即是X[i] != Y[j]
            // 第一种做法
            if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j],
                B[i][j] = 's'; //记录回溯的时候往 上方向回溯
                continue;
            } //此处条件省略，原条件: (X[i] != Y[j]) && (C[i - 1][j] < C[i][j - 1])
            C[i][j] = C[i][j - 1],
            B[i][j] = 'z'; //记录回溯的时候往 左方向回溯

            //第二种做法
            // if (C[i][j - 1] >= C[i - 1][j]) {

            //     C[i][j] = C[i][j - 1],
            //     B[i][j] = 'z';
            //     continue;
            // }
            // C[i][j] = C[i - 1][j],
            // B[i][j] = 's';
        }
    }
}

//递归输出LCS序列和长度
//一开始主函数调用使用的是赋初值，递归调用将给予具体值
//@param m_ 好
void StructureSequence(const int &m_ = m, const int &n_ = n, const bool &first = 1) {
    if (!m_ || !n_) {    //m_==0 || n_==0即X或Y序列到底了
        printf("LCS: "); //输出LCS
        return;
    }
    switch (B[m_][n_]) {
    case 'z': //向B[][]左回溯
        StructureSequence(m_, n_ - 1, 0);
        break;
    case 's': //向B[][]上回溯
        StructureSequence(m_ - 1, n_, 0);
        break;
    default: //case 'x' 向B[][]左上回溯
        StructureSequence(m_ - 1, n_ - 1, 0);
        printf("%c", X[m_]);
        break;
    }
    //如果第一次输出，格式化输出
    first &&printf("\nlength of LCS: %d\n\n", C[m][n]);
}

//输出C[][]
void print_C() {
    printf("C:X\\Y");
    loop(i, 0, n)
        printf("[%2d]", i);
    putchar('\n');
    loop(i, 0, m) {
        printf(" [%2d]", i);
        loop(j, 0, n)
            printf("%3d ", C[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

//输出B[][]
void print_B() {
    printf("B:X\\Y");
    loop(i, 1, n)
        printf("[%2d]", i);
    putchar('\n');
    loop(i, 1, m) {
        printf(" [%2d]", i);
        loop(j, 1, n) //格式化输出，即是'z'——'←','s'——'↑','x'——'↖'
            printf(B[i][j] == 'x'
                       ? "  ↖ "
                       : (B[i][j] == 'z'
                              ? "  ← "
                              : "  ↑ "));
    }
    putchar('\n');
}

int main() {
    //1组
    string X_ = "ABCBDAB",
           Y_ = "BDCABA";
    // //2组
    // string X_ = "13456778",
    //        Y_ = "357486782";

    init(X_, Y_);        //初始化
    print_mes();         //输出初始化信息
    LCS();               //LCS计算C[][]  B[][]
    StructureSequence(); //回溯输出LCS信息
    print_C();           //输出C[][]
    print_B();           //输出B[][]
    return 0;
}