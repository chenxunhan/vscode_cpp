#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

ElemType *DataSet;          //数据集
int DataNumber;             //数据量
double *PR;                 //概率
double **SubPRSum;          //i~j的节点+空隙概率和
double **OptimalAvgBSTimes; //i~j的构建最优二分检索树查找次数数学期望
int **OBSTRoot;             //i~j的构建最优二分检索树根节点

//创造int二维数组
int **makeInt2DArray(int width) {
    int **_2DArray = new int *[width];
    for (int i = 0; i < width; ++i)
        _2DArray[i] = new int[width];
    return _2DArray;
}

//创造double二维数组
double **makeDouble2DArray(int width) {
    double **_2DArray = new double *[width];
    for (int i = 0; i < width; ++i)
        _2DArray[i] = new double[width];
    return _2DArray;
}

//销毁二维数组
void Delete2DArray(int **_2DArray, int width) {
    for (int i = 0; i < width; ++i)
        delete _2DArray[i];
    delete _2DArray;
}
void Delete2DArray(double **_2DArray, int width) {
    for (int i = 0; i < width; ++i)
        delete _2DArray[i];
    delete _2DArray;
}

//删除全部全局动态数组
void DeleteAllArray() {
    delete DataSet;
    delete PR;
    Delete2DArray(SubPRSum, DataNumber + 1);
    Delete2DArray(OptimalAvgBSTimes, DataNumber + 1);
    Delete2DArray(OBSTRoot, DataNumber + 1);
}

//初始化数据
void init(ElemType *DataSet_, double *PR_, int DataNumber_) {

    DataNumber = DataNumber_;
    DataSet = DataSet_ - 1; //使DtatSet[1]指向第一个元素，注意不可使用DataSet[0]会报错
    PR = PR_;

    SubPRSum = makeDouble2DArray(DataNumber + 1);
    OptimalAvgBSTimes = makeDouble2DArray(DataNumber + 1);
    OBSTRoot = makeInt2DArray(DataNumber + 1);

    //初始化i~j的节点+空隙概率和
    for (int i = 1; i <= DataNumber; ++i) {
        for (int j = i; j <= DataNumber; ++j) {
            SubPRSum[i][j] = PR[2 * (i - 1)];
            for (int k = i; k <= j; ++k)
                SubPRSum[i][j] += PR[2 * k] + PR[2 * k - 1];
        }
    }
}

//输出初始化信息
void printInitMessage() {
    printf("DataNumber:%d\n\n", DataNumber);
    printf("DataSet[]:%c", DataSet[1]);
    for (int i = 2; i <= DataNumber; ++i)
        printf(",%c", DataSet[i]);

    printf("\n\n");
    printf("PR[]:%.2lf", PR[0]);
    for (int i = 1; i <= 2 * DataNumber; ++i)
        printf(",%.2lf", PR[i]);

    printf("\n\nSubPRSum[][]:\n");
    for (int i = 1; i <= DataNumber; ++i) {
        for (int j = 1; j < i; ++j)
            printf("      ");
        for (int j = i; j <= DataNumber; ++j)
            printf("%6.2lf", SubPRSum[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

//动态规划打表出最优二分检索树的各类信息
void DPOBST() {
    for (int length = 1; length <= DataNumber; ++length) {      //长度从1~数据梁
        for (int i = 1, j; i <= DataNumber - length + 1; ++i) { //起始坐标
            j = i + length - 1;                                 //尾坐标
            double min_times = DBL_MAX;                         //最优检索次数置无穷
            for (int k = i; k <= j; ++k) {                      //根节点从i~j遍历
                double min_times_ = 0;
                ((i < k) && (min_times_ += OptimalAvgBSTimes[i][k - 1])); //如果i<=k-1执行，防止访问数组越界
                ((k < j) && (min_times_ += OptimalAvgBSTimes[k + 1][j])); //如果k+1<=j执行，效果类似上方

                //记录最优检索树的平均查找次数和根节点
                ((min_times_ < min_times) && (min_times = min_times_, OBSTRoot[i][j] = k));
            }
            OptimalAvgBSTimes[i][j] = min_times + SubPRSum[i][j]; //最优检索树的平均查找次数补上没计算的部分
        }
    }
}

//输出i~j的构建最优二分检索树查找次数数学期望
void printOptimalAvgBSTimes() {
    printf("OptimalAvgBSTimes[][]:\n");
    for (int i = 1; i <= DataNumber; ++i) {
        for (int j = 1; j < i; ++j)
            printf("      ");
        for (int j = i; j <= DataNumber; ++j)
            printf("%6.2lf", OptimalAvgBSTimes[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

//输出标记函数树节点
void printOBSTRoot() {
    printf("OBSTRoot[][]:\n");
    for (int i = 1; i <= DataNumber; ++i) {
        for (int j = 1; j < i; ++j)
            printf("   ");
        for (int j = i; j <= DataNumber; ++j)
            printf("%3c", DataSet[OBSTRoot[i][j]]);
        putchar('\n');
    }
    putchar('\n');
}

//括号表示法输出树
void printTree(int i = 1, int j = DataNumber) {
    if (i > j) return;
    putchar(DataSet[OBSTRoot[i][j]]);
    if (i == j) return;
    putchar('(');
    printTree(i, OBSTRoot[i][j] - 1);
    if (OBSTRoot[i][j] < j) {
        putchar(',');
        printTree(OBSTRoot[i][j] + 1, j);
    }
    putchar(')');
}

int main() {
    //example1
    ElemType DataSet_[] = {'A', 'B', 'C', 'D', 'E'};
    double PR_[] = {0.04, 0.1, 0.02, 0.3, 0.02, 0.1, 0.05, 0.2, 0.06, 0.1, 0.01};

    // //example2
    // ElemType DataSet_[] = {'A', 'B', 'C', 'D'};
    // double PR_[] = {1, 3, 3, 3, 2, 1, 1, 1, 1};

    init(DataSet_, PR_, sizeof(DataSet_) / sizeof(ElemType)); //初始化
    printInitMessage();                                       //输出初始化信息
    DPOBST();                                                 //动态规划计算
    printOptimalAvgBSTimes();                                 //输出最优平均查找次数
    printOBSTRoot();                                          //输出树节点标记函数
    printTree();                                              //输出树
    DeleteAllArray();                                         //销毁全部动态数组
    return 0;
}