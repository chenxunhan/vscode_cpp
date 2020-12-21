#include <bits/stdc++.h>
#define MAXV 20     //��󶥵����
#define MaxSize 100 //������
#define INF 32767   //INF��ʾ��
using namespace std;

typedef string InfoType; //��������ϢΪ�ַ�����

//���¶����ڽӾ�������
typedef struct
{
    int no;        //������
    InfoType info; //����������Ϣ
} VertexType;      //��������
typedef struct     //ͼ�Ķ���
{
    int edges[MAXV][MAXV]; //�ڽӾ���
    int n, e;              //������������
    VertexType vexs[MAXV]; //��Ŷ�����Ϣ
} AOEMatGraph;             //ͼ���ڽӾ�������

//����ͼ�ڽӾ���
//�������˵���������������Ӿ������ô��룬����߶�ά���飬��������������������Ϣ
void CreateAOEMat(AOEMatGraph &g, int edges[MAXV][MAXV], int n, int e, InfoType info[]) {
    g.n = n, g.e = e;
    for (int i = 0; i < n; ++i) {
        g.vexs[i].info = info[i]; //���붥����Ϣ
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = edges[i][j];
        }
    }
}

//����ʽ����ڽӾ���g
void DispAOEMat(AOEMatGraph g) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        cout << "| ";
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] == INF)
                cout << "-  ";
            else
                printf("%-3d", g.edges[i][j]);
        cout << "|" << endl;
    }
}

//��AOE�ĸ��¼������翪ʼʱ�丳ֵ��ve,��ٿ�ʼʱ�丳ֵ��vl��
//������������翪ʼʱ�丳ֵ��e,��ٿ�ʼʱ�丳ֵ��l��ʱ��������ֵ��d
void Create_AOE_vevl_eld(AOEMatGraph AOE, int ve[], int vl[], int e[], int l[], int d[]) {
    for (int i = 0; i < AOE.n; ++i) { //���翪ʼʱ������
        ve[i] = 0;
    }
    for (int i = 0, k = 0; i < AOE.n; ++i) {
        for (int j = 0; j < AOE.n; ++j) {
            if (AOE.edges[i][j] != 0 && AOE.edges[i][j] != INF) {
                if (ve[i] + AOE.edges[i][j] > ve[j]) {
                    ve[j] = ve[i] + AOE.edges[i][j];
                }
                e[k++] = ve[i]; //��ֵ������翪ʼʱ��
            }
        }
    }
    for (int i = 0; i < AOE.n; ++i) { //��ٿ�ʼʱ������
        vl[i] = ve[AOE.n - 1];
    }
    for (int i = AOE.n - 1, k = AOE.e - 1; i >= 0; --i) {
        for (int j = AOE.n - 1; j >= 0; --j) {
            if (AOE.edges[i][j] != 0 && AOE.edges[i][j] != INF) {
                if (vl[j] - AOE.edges[i][j] < vl[i]) {
                    vl[i] = vl[j] - AOE.edges[i][j];
                }
                l[k] = vl[j] - AOE.edges[i][j]; //��ֵ�����ٿ�ʼʱ��
                d[k--] = l[k] - e[k];           //��ֵ���ʱ������
            }
        }
    }
}

//��ҵ��ʽ���AOE�ĸ��¼����������ٿ�ʼʱ��
void DispAOEvevl(AOEMatGraph AOE, int ve[], int vl[]) {
    for (int i = 0; i < AOE.n; ++i) {
        printf("ve(%s)=%2d\tvl(%s)=%2d\n", AOE.vexs[i].info.c_str(), ve[i], AOE.vexs[i].info.c_str(), vl[i]);
    }
}

//��ҵ��ʽ���AOE�ĸ�����������ٿ�ʼʱ���ʱ������
void DispAOEeld(AOEMatGraph AOE, int e[], int l[], int d[]) {
    for (int i = 0; i < AOE.e; ++i) {
        printf("e(a%2d)=%2d\tl(a%2d)=%2d\td(a%2d)=%2d\n", i + 1, e[i], i + 1, l[i], i + 1, d[i]);
    }
}

int main() {
    AOEMatGraph AOE;
    //**ʾ��1*******************************************************************//
    int AOE_edges[MAXV][MAXV] = {{0, 6, 4, 5, INF, INF, INF, INF, INF},
                                 {INF, 0, INF, INF, 1, INF, INF, INF, INF},
                                 {INF, INF, 0, INF, 1, INF, INF, INF, INF},
                                 {INF, INF, INF, 0, INF, INF, INF, 2, INF},
                                 {INF, INF, INF, INF, 0, 9, 7, INF, INF},
                                 {INF, INF, INF, INF, INF, 0, INF, INF, 2},
                                 {INF, INF, INF, INF, INF, INF, 0, INF, 4},
                                 {INF, INF, INF, INF, INF, INF, INF, 0, 4},
                                 {INF, INF, INF, INF, INF, INF, INF, INF, 0}};
    InfoType AOE_info[MAXV] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    CreateAOEMat(AOE, AOE_edges, 9, 11, AOE_info);
    cout << "ʾ��1 ";
    //**ʾ��1*******************************************************************/

    //**ʾ��2*******************************************************************//
    /*int AOE_edges[MAXV][MAXV] = {{0, 3, 2, INF, INF, INF},
                                 {INF, 0, INF, 2, 3, INF},
                                 {INF, INF, 0, 4, INF, 3},
                                 {INF, INF, INF, 0, INF, 2},
                                 {INF, INF, INF, INF, 0, 1},
                                 {INF, INF, INF, INF, INF, 0}};
    InfoType AOE_info[MAXV] = {"v1", "v2", "v3", "v4", "v5", "v6"};
    CreateAOEMat(AOE, AOE_edges, 6, 8, AOE_info);
    cout << "ʾ��2 ";
    //**ʾ��2*******************************************************************/
    cout << "AOE�ľ���ͼ:" << endl;
    DispAOEMat(AOE);
    cout << endl;
    int ve[MAXV], vl[MAXV];
    int e[MAXV], l[MAXV], d[MAXV];
    Create_AOE_vevl_eld(AOE, ve, vl, e, l, d);
    cout << "AOE���¼����������ٿ�ʼʱ��:" << endl;
    DispAOEvevl(AOE, ve, vl);
    cout << endl;
    cout << "AOE��������硢��ٿ�ʼʱ���ʱ������:" << endl;
    DispAOEeld(AOE, e, l, d);
    return 0;
}