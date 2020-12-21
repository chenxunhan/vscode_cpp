#include <bits/stdc++.h>
#define MAXV 20   //顶点最多20个
#define INF 32767 //设置无穷大
using namespace std;

typedef struct {
    int edges[MAXV][MAXV]; //存放图的边信息
    int n, e;              //顶点数、边数
    /*由于此次作业的顶点节点只有编号没有其他信息，
    因此不设置存放其他信息*/
} MatGraph; //矩阵图

typedef struct ANode {
    int adjvex;            //编号
    struct ANode *nextarc; //下一个节点指针
    int weight;            //权值
} ArcNode;                 //邻接表节点

typedef struct Vnode {
    /*由于此次作业的顶点节点只有编号没有其他信息，
    因此不设置存放其他信息*/
    ArcNode *firstarc; //邻接表编码第一个节点指针
} VNode;

typedef struct {
    VNode adjlist[MAXV]; //邻接表的编码
    int n, e;
} AdjGraph; //邻接表

//输出邻接矩阵图
void DispMatGraph(MatGraph G) {
    for (int i = 0; i < G.n; ++i) {
        for (int j = 0; j < G.n; ++j) {
            if (G.edges[i][j] == INF) //无穷大输出处理
                printf("   ∞");
            else
                printf("%4d", G.edges[i][j]); //对齐输出
        }
        cout << endl;
    }
}

//输出邻接表
void DispAdjGraph(AdjGraph *G) {
    ArcNode *p;
    for (int ni = 0; ni < G->n; ++ni) { //遍历编码
        cout << ni;
        p = G->adjlist[ni].firstarc;                          //指向第一个节点
        while (p) {                                           //不空节点输出值
            cout << "---->" << p->adjvex << "," << p->weight; //输出编码和权值
            p = p->nextarc;                                   //指向下一个节点
        }
        cout << "^" << endl; //结尾输出
    }
}

//邻接表转换邻接矩阵
void ListToMat(AdjGraph *G, MatGraph &g) {
    g.n = G->n, g.e = G->e;
    ArcNode *p;
    for (int i = 0; i < G->n; ++i) {
        for (int j = 0; j < G->n; ++j)
            g.edges[i][j] = (i == j ? 0 : INF); //若首位相等，赋值0，否则无穷大
        p = G->adjlist[i].firstarc;
        while (p) {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
}

//邻接矩阵转邻接表
void MatToList(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    G = new AdjGraph;
    G->n = n, G->e = e;
    ArcNode *p;
    for (int i = 0; i < n; ++i)
        G->adjlist[i].firstarc = NULL;
    for (int i = 0; i < n; ++i)
        for (int j = n - 1; j >= 0; --j) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = new ArcNode;
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
}

//销毁邻接表
void DestoryAdj(AdjGraph *&G) {
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; ++i) {
        pre = G->adjlist[i].firstarc;
        if (pre) {
            p = pre->nextarc;
            while (p) {
                delete pre;
                pre = p;
                p = p->nextarc;
            }
            delete pre;
        }
    }
    delete G;
}

int main() {
    //图8.54
    /*int Gn = 6, Ge = 10;
    int Gedges[MAXV][MAXV] = {{0, 5, INF, 7, INF, INF},
                              {INF, 0, 4, INF, INF, INF},
                              {8, INF, 0, INF, INF, 9},
                              {INF, INF, 5, 0, INF, 6},
                              {INF, INF, INF, 5, 0, INF},
                              {3, INF, INF, INF, 1, 0}};
    cout << "图8.54有向图G的邻接矩阵：" << endl;*/

    //图8.55
    int Gn = 6, Ge = 10;
    int Gedges[MAXV][MAXV] = {{0, 5, 8, 7, INF, 3},
                              {5, 0, 4, INF, INF, INF},
                              {8, 4, 0, 5, INF, 9},
                              {7, INF, 5, 0, 5, 6},
                              {INF, INF, INF, 5, 0, 1},
                              {3, INF, 9, 6, 1, 0}};
    cout << "图8.55无向图G的邻接矩阵：" << endl;

    for (int i = 0; i < Gn; ++i) {
        for (int j = 0; j < Gn; ++j) {
            if (Gedges[i][j] == INF)
                printf("   ∞");
            else
                printf("%4d", Gedges[i][j]);
        }
        cout << endl;
    }
    AdjGraph *L;
    MatToList(L, Gedges, Gn, Ge);
    cout << "图G的邻接矩阵转换成邻接表：" << endl;
    DispAdjGraph(L);
    MatGraph G2;
    ListToMat(L, G2);
    cout << "图G的邻接表转换成邻接矩阵：" << endl;
    DispMatGraph(G2);
    cout << "销毁邻接表";
    DestoryAdj(L);
    return 0;
}