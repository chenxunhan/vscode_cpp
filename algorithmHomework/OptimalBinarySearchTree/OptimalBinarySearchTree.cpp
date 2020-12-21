#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

ElemType *DataSet;          //���ݼ�
int DataNumber;             //������
double *PR;                 //����
double **SubPRSum;          //i~j�Ľڵ�+��϶���ʺ�
double **OptimalAvgBSTimes; //i~j�Ĺ������Ŷ��ּ��������Ҵ�����ѧ����
int **OBSTRoot;             //i~j�Ĺ������Ŷ��ּ��������ڵ�

//����int��ά����
int **makeInt2DArray(int width) {
    int **_2DArray = new int *[width];
    for (int i = 0; i < width; ++i)
        _2DArray[i] = new int[width];
    return _2DArray;
}

//����double��ά����
double **makeDouble2DArray(int width) {
    double **_2DArray = new double *[width];
    for (int i = 0; i < width; ++i)
        _2DArray[i] = new double[width];
    return _2DArray;
}

//���ٶ�ά����
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

//ɾ��ȫ��ȫ�ֶ�̬����
void DeleteAllArray() {
    delete DataSet;
    delete PR;
    Delete2DArray(SubPRSum, DataNumber + 1);
    Delete2DArray(OptimalAvgBSTimes, DataNumber + 1);
    Delete2DArray(OBSTRoot, DataNumber + 1);
}

//��ʼ������
void init(ElemType *DataSet_, double *PR_, int DataNumber_) {

    DataNumber = DataNumber_;
    DataSet = DataSet_ - 1; //ʹDtatSet[1]ָ���һ��Ԫ�أ�ע�ⲻ��ʹ��DataSet[0]�ᱨ��
    PR = PR_;

    SubPRSum = makeDouble2DArray(DataNumber + 1);
    OptimalAvgBSTimes = makeDouble2DArray(DataNumber + 1);
    OBSTRoot = makeInt2DArray(DataNumber + 1);

    //��ʼ��i~j�Ľڵ�+��϶���ʺ�
    for (int i = 1; i <= DataNumber; ++i) {
        for (int j = i; j <= DataNumber; ++j) {
            SubPRSum[i][j] = PR[2 * (i - 1)];
            for (int k = i; k <= j; ++k)
                SubPRSum[i][j] += PR[2 * k] + PR[2 * k - 1];
        }
    }
}

//�����ʼ����Ϣ
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

//��̬�滮�������Ŷ��ּ������ĸ�����Ϣ
void DPOBST() {
    for (int length = 1; length <= DataNumber; ++length) {      //���ȴ�1~������
        for (int i = 1, j; i <= DataNumber - length + 1; ++i) { //��ʼ����
            j = i + length - 1;                                 //β����
            double min_times = DBL_MAX;                         //���ż�������������
            for (int k = i; k <= j; ++k) {                      //���ڵ��i~j����
                double min_times_ = 0;
                ((i < k) && (min_times_ += OptimalAvgBSTimes[i][k - 1])); //���i<=k-1ִ�У���ֹ��������Խ��
                ((k < j) && (min_times_ += OptimalAvgBSTimes[k + 1][j])); //���k+1<=jִ�У�Ч�������Ϸ�

                //��¼���ż�������ƽ�����Ҵ����͸��ڵ�
                ((min_times_ < min_times) && (min_times = min_times_, OBSTRoot[i][j] = k));
            }
            OptimalAvgBSTimes[i][j] = min_times + SubPRSum[i][j]; //���ż�������ƽ�����Ҵ�������û����Ĳ���
        }
    }
}

//���i~j�Ĺ������Ŷ��ּ��������Ҵ�����ѧ����
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

//�����Ǻ������ڵ�
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

//���ű�ʾ�������
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

    init(DataSet_, PR_, sizeof(DataSet_) / sizeof(ElemType)); //��ʼ��
    printInitMessage();                                       //�����ʼ����Ϣ
    DPOBST();                                                 //��̬�滮����
    printOptimalAvgBSTimes();                                 //�������ƽ�����Ҵ���
    printOBSTRoot();                                          //������ڵ��Ǻ���
    printTree();                                              //�����
    DeleteAllArray();                                         //����ȫ����̬����
    return 0;
}