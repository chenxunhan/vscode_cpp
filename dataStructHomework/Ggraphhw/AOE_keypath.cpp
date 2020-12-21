#include <bits/stdc++.h>
#define MAXV 20     //最大顶点个数
#define MaxSize 100 //最大边数
#define INF 32767   //INF表示∞
using namespace std;

typedef string InfoType; //顶点编号信息为字符串类

//以下定义邻接矩阵类型
typedef struct
{
    int no;        //顶点编号
    InfoType info; //顶点其他信息
} VertexType;      //顶点类型
typedef struct     //图的定义
{
    int edges[MAXV][MAXV]; //邻接矩阵
    int n, e;              //顶点数，边数
    VertexType vexs[MAXV]; //存放顶点信息
} AOEMatGraph;             //图的邻接矩阵类型

//创建图邻接矩阵
//传入参数说明，待创建的链接矩阵引用传入，矩阵边二维数组，顶点数，边数，顶点信息
void CreateAOEMat(AOEMatGraph &g, int edges[MAXV][MAXV], int n, int e, InfoType info[]) {
    g.n = n, g.e = e;
    for (int i = 0; i < n; ++i) {
        g.vexs[i].info = info[i]; //传入顶点信息
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = edges[i][j];
        }
    }
}

//按格式输出邻接矩阵g
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

//将AOE的各事件的最早开始时间赋值给ve,最迟开始时间赋值给vl，
//并将各活动的最早开始时间赋值给e,最迟开始时间赋值给l，时间余量赋值给d
void Create_AOE_vevl_eld(AOEMatGraph AOE, int ve[], int vl[], int e[], int l[], int d[]) {
    for (int i = 0; i < AOE.n; ++i) { //最早开始时间重置
        ve[i] = 0;
    }
    for (int i = 0, k = 0; i < AOE.n; ++i) {
        for (int j = 0; j < AOE.n; ++j) {
            if (AOE.edges[i][j] != 0 && AOE.edges[i][j] != INF) {
                if (ve[i] + AOE.edges[i][j] > ve[j]) {
                    ve[j] = ve[i] + AOE.edges[i][j];
                }
                e[k++] = ve[i]; //赋值活动的最早开始时间
            }
        }
    }
    for (int i = 0; i < AOE.n; ++i) { //最迟开始时间重置
        vl[i] = ve[AOE.n - 1];
    }
    for (int i = AOE.n - 1, k = AOE.e - 1; i >= 0; --i) {
        for (int j = AOE.n - 1; j >= 0; --j) {
            if (AOE.edges[i][j] != 0 && AOE.edges[i][j] != INF) {
                if (vl[j] - AOE.edges[i][j] < vl[i]) {
                    vl[i] = vl[j] - AOE.edges[i][j];
                }
                l[k] = vl[j] - AOE.edges[i][j]; //赋值活动的最迟开始时间
                d[k--] = l[k] - e[k];           //赋值活动的时间余量
            }
        }
    }
}

//作业格式输出AOE的各事件的最早和最迟开始时间
void DispAOEvevl(AOEMatGraph AOE, int ve[], int vl[]) {
    for (int i = 0; i < AOE.n; ++i) {
        printf("ve(%s)=%2d\tvl(%s)=%2d\n", AOE.vexs[i].info.c_str(), ve[i], AOE.vexs[i].info.c_str(), vl[i]);
    }
}

//作业格式输出AOE的各活动的最早和最迟开始时间和时间余量
void DispAOEeld(AOEMatGraph AOE, int e[], int l[], int d[]) {
    for (int i = 0; i < AOE.e; ++i) {
        printf("e(a%2d)=%2d\tl(a%2d)=%2d\td(a%2d)=%2d\n", i + 1, e[i], i + 1, l[i], i + 1, d[i]);
    }
}

int main() {
    AOEMatGraph AOE;
    //**示例1*******************************************************************//
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
    cout << "示例1 ";
    //**示例1*******************************************************************/

    //**示例2*******************************************************************//
    /*int AOE_edges[MAXV][MAXV] = {{0, 3, 2, INF, INF, INF},
                                 {INF, 0, INF, 2, 3, INF},
                                 {INF, INF, 0, 4, INF, 3},
                                 {INF, INF, INF, 0, INF, 2},
                                 {INF, INF, INF, INF, 0, 1},
                                 {INF, INF, INF, INF, INF, 0}};
    InfoType AOE_info[MAXV] = {"v1", "v2", "v3", "v4", "v5", "v6"};
    CreateAOEMat(AOE, AOE_edges, 6, 8, AOE_info);
    cout << "示例2 ";
    //**示例2*******************************************************************/
    cout << "AOE的矩阵图:" << endl;
    DispAOEMat(AOE);
    cout << endl;
    int ve[MAXV], vl[MAXV];
    int e[MAXV], l[MAXV], d[MAXV];
    Create_AOE_vevl_eld(AOE, ve, vl, e, l, d);
    cout << "AOE各事件的最早和最迟开始时间:" << endl;
    DispAOEvevl(AOE, ve, vl);
    cout << endl;
    cout << "AOE各活动的最早、最迟开始时间和时间余量:" << endl;
    DispAOEeld(AOE, e, l, d);
    return 0;
}