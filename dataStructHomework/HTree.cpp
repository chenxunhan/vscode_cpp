#include <bits/stdc++.h>
#define N 40 //由于树结点比较少，设置40
using namespace std;

typedef struct {
    char data;          //数据域
    double weight;      //权重
    int parent;         //双亲结点
    int lchild, rchild; //左右孩子
} HTNode;               //哈夫曼树结构

typedef struct {
    char cd[N] = {0}; //哈夫曼编码存储数组
    int start;        //读取头
} HCode;              //哈夫曼编码结构

//哈夫曼树初始化(数据域+权重)
void InitHT(HTNode ht[], char dt[], double w[], int n0) {
    for (int i = 0; i < n0; ++i) {
        ht[i].data = dt[i];  //数据域赋值
        ht[i].weight = w[i]; //权重赋值
    }
}

//创建哈夫曼树
void CreateHT(HTNode ht[], int n0) {
    for (int i = 0; i <= 2 * n0 - 2; ++i) { //孩子双亲全-1
        ht[i].lchild = ht[i].rchild = ht[i].parent = -1;
    }
    for (int i = n0; i <= 2 * n0 - 2; ++i) {
        int lnode = -1, rnode = -1;
        //min1<min2,min1最小值,min2次最小
        double min1 = DBL_MAX, min2 = DBL_MAX; //DBL_MAX是double的最大值
        for (int k = 0; k < i; ++k)
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    rnode = lnode;
                    min2 = min1;
                    lnode = k;
                    min1 = ht[k].weight;
                    continue;
                }
                if (ht[k].weight < min2) {
                    rnode = k;
                    min2 = ht[k].weight;
                }
            }
        ht[i].weight = min1 + min2;
        ht[i].lchild = lnode, ht[i].rchild = rnode;
        ht[lnode].parent = ht[rnode].parent = i;
    }
}

//给哈夫曼树的各个节点创建哈夫曼编码
void CreateHCode(HTNode ht[], HCode hcd[], int n0) {
    HCode hc;
    for (int i = 0; i < n0; ++i) {
        hc.start = n0;
        int c = i, f = ht[i].parent;
        while (f != -1) {
            hc.cd[hc.start--] = '0' + (ht[f].lchild != c);
            c = f;
            f = ht[f].parent;
        }
        ++hc.start;
        hcd[i] = hc;
    }
}

//特殊输出哈夫曼树
void DispHCode(HTNode ht[], HCode hcd[], int n0) {
    for (int i = 0; i < n0; ++i) {
        cout << ht[i].data << ":";
        for (int j = 0; j < n0; ++j)
            cout << hcd[i].cd[hcd[i].start + j];
        cout << endl;
    }
}

//直接传入哈夫曼树，计算wpl
double WPL1(HTNode ht[], int n0) {
    double wpl = 0;
    for (int i = 0; i < n0; ++i) {
        int c = ht[i].parent;
        while (c != -1) {
            wpl += ht[i].weight;
            c = ht[c].parent;
        }
    }
    return wpl;
}

//传入哈夫曼树和哈夫曼编码，依据哈夫曼编码返回wpl
double WPL2(HTNode ht[], HCode hcd[], int n0) {
    double wpl = 0;
    for (int i = 0; i < n0; ++i) {
        wpl += (n0 - hcd[i].start + 1) * ht[i].weight;
    }
    return wpl;
}

int main() {
    //例子1
    /*int testn = 5;                             //哈夫曼树结点数
    char testd[5] = {'A', 'B', 'C', 'D', 'E'}; //哈夫曼树数据域
    double testw[5] = {6, 4, 8, 5, 7};         //哈夫曼树权重
    HTNode testht[2 * 5 - 1];                  //哈夫曼树
    HCode testhc[5];                           //哈夫曼编码
    */
    //例子2
    int testn = 8;
    char testd[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    double testw[8] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.10};
    HTNode testht[2 * 8 - 1];
    HCode testhc[8];

    InitHT(testht, testd, testw, testn); //哈夫曼树初始化(数据域+权重)
    CreateHT(testht, testn);             //创建哈夫曼树
    CreateHCode(testht, testhc, testn);  //给哈夫曼树的各个节点创建哈夫曼编码
    cout << "该哈夫曼树各节点数据和哈夫曼编码是:" << endl;
    DispHCode(testht, testhc, testn);
    cout << "WP1=" << WPL1(testht, testn) << endl;         //直接传入哈夫曼树，计算wpl
    cout << "WP2=" << WPL2(testht, testhc, testn) << endl; //传入哈夫曼树和哈夫曼编码，依据哈夫曼编码返回wpl
    return 0;
}