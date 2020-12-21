#include <bits/stdc++.h>
#define N 40 //���������Ƚ��٣�����40
using namespace std;

typedef struct {
    char data;          //������
    double weight;      //Ȩ��
    int parent;         //˫�׽��
    int lchild, rchild; //���Һ���
} HTNode;               //���������ṹ

typedef struct {
    char cd[N] = {0}; //����������洢����
    int start;        //��ȡͷ
} HCode;              //����������ṹ

//����������ʼ��(������+Ȩ��)
void InitHT(HTNode ht[], char dt[], double w[], int n0) {
    for (int i = 0; i < n0; ++i) {
        ht[i].data = dt[i];  //������ֵ
        ht[i].weight = w[i]; //Ȩ�ظ�ֵ
    }
}

//������������
void CreateHT(HTNode ht[], int n0) {
    for (int i = 0; i <= 2 * n0 - 2; ++i) { //����˫��ȫ-1
        ht[i].lchild = ht[i].rchild = ht[i].parent = -1;
    }
    for (int i = n0; i <= 2 * n0 - 2; ++i) {
        int lnode = -1, rnode = -1;
        //min1<min2,min1��Сֵ,min2����С
        double min1 = DBL_MAX, min2 = DBL_MAX; //DBL_MAX��double�����ֵ
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

//�����������ĸ����ڵ㴴������������
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

//���������������
void DispHCode(HTNode ht[], HCode hcd[], int n0) {
    for (int i = 0; i < n0; ++i) {
        cout << ht[i].data << ":";
        for (int j = 0; j < n0; ++j)
            cout << hcd[i].cd[hcd[i].start + j];
        cout << endl;
    }
}

//ֱ�Ӵ����������������wpl
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

//������������͹��������룬���ݹ��������뷵��wpl
double WPL2(HTNode ht[], HCode hcd[], int n0) {
    double wpl = 0;
    for (int i = 0; i < n0; ++i) {
        wpl += (n0 - hcd[i].start + 1) * ht[i].weight;
    }
    return wpl;
}

int main() {
    //����1
    /*int testn = 5;                             //�������������
    char testd[5] = {'A', 'B', 'C', 'D', 'E'}; //��������������
    double testw[5] = {6, 4, 8, 5, 7};         //��������Ȩ��
    HTNode testht[2 * 5 - 1];                  //��������
    HCode testhc[5];                           //����������
    */
    //����2
    int testn = 8;
    char testd[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    double testw[8] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.10};
    HTNode testht[2 * 8 - 1];
    HCode testhc[8];

    InitHT(testht, testd, testw, testn); //����������ʼ��(������+Ȩ��)
    CreateHT(testht, testn);             //������������
    CreateHCode(testht, testhc, testn);  //�����������ĸ����ڵ㴴������������
    cout << "�ù����������ڵ����ݺ͹�����������:" << endl;
    DispHCode(testht, testhc, testn);
    cout << "WP1=" << WPL1(testht, testn) << endl;         //ֱ�Ӵ����������������wpl
    cout << "WP2=" << WPL2(testht, testhc, testn) << endl; //������������͹��������룬���ݹ��������뷵��wpl
    return 0;
}