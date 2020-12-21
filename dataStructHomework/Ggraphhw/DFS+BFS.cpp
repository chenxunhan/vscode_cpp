#include <bits/stdc++.h>
#define MAXV 20 //顶点最多20个
using namespace std;

typedef struct {
    int edges[MAXV][MAXV]; //存放无向不带权图的边信息
    int n, e;              //顶点数、边数
    /*由于此次作业的顶点节点只有编号没有其他信息，
    因此不设置存放其他信息*/
} MatGraph; //无向不带权图

typedef struct ANode {
    int adjvex;            //编号
    struct ANode *nextarc; //下一个节点指针
    /*作业的无向不带权图编无权值，因此不设置存放权值信息*/
} ArcNode;

typedef struct Vnode {
    /*由于此次作业的顶点节点只有编号没有其他信息，
    因此不设置存放其他信息*/
    ArcNode *firstarc; //第一个节点指针
} VNode;

typedef struct {
    VNode adjlist[MAXV]; //顶点
    int n, e;            //顶点数、边数
} AdjGraph;              //邻接表

//输出邻接表
void DispAdjGraph(AdjGraph *G) {
    ArcNode *p;
    for (int ni = 0; ni < G->n; ++ni) { //遍历编码
        cout << ni;
        p = G->adjlist[ni].firstarc; //指向第一个节点
        while (p) {                  //不空节点输出值
            cout << "--->" << p->adjvex;
            p = p->nextarc; //指向下一个节点
        }
        cout << "^" << endl; //结尾输出
    }
}

//邻接矩阵转邻接表
void MatToList(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    G = new AdjGraph;
    G->n = n, G->e = e;
    ArcNode *p;
    for (int i = 0; i < n; ++i) //编码指向的第一个节点置空
        G->adjlist[i].firstarc = NULL;
    for (int i = 0; i < n; ++i)            //遍历矩阵行
        for (int j = n - 1; j >= 0; --j) { //遍历矩阵列
            if (A[i][j] != 0) {            //邻接表建立
                p = new ArcNode;
                p->adjvex = j;
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

//深度优先遍历
void DFS(AdjGraph *G, int v, bool *visited) { //从主函数传入的visited为NULL
    if (visited == NULL) {                    //visited若为空
        bool newvisited[MAXV] = {0};          //新建编码记录数组并重置
        visited = newvisited;                 //编码记录数组头指针复制
    }
    int w;
    visited[v] = 1;
    cout << setw(4) << v;
    ArcNode *p = G->adjlist[v].firstarc;
    while (p) {
        w = p->adjvex;
        if (!visited[w]) //当记录数组中未记录该编码
            DFS(G, w, visited);
        p = p->nextarc;
    }
}

//广度优先遍历
void BFS(AdjGraph *G, int v) {
    int w;
    ArcNode *p;
    struct {
        int data[MAXV];
        int front = -1, rear = -1;
    } qu;                     //队列结构
    bool visited[MAXV] = {0}; //新建编码记录数组并重置
    cout << setw(4) << v;     //输出起点
    visited[v] = 1;           //记录起点
    ++qu.front;               //进队
    qu.data[qu.front] = v;    //进队
    while (qu.front != qu.rear) {
        ++qu.rear;            //出队
        w = qu.data[qu.rear]; //出队
        p = G->adjlist[w].firstarc;
        while (p) {                            //只要顶点不为空
            if (visited[p->adjvex] == 0) {     //且未记录
                cout << setw(4) << p->adjvex;  //输出
                visited[p->adjvex] = 1;        //记录
                ++qu.front;                    //进队
                qu.data[qu.front] = p->adjvex; //进队
            }
            p = p->nextarc;
        }
    }
    cout << endl;
}

int main() {
    //图8.24
    int t;
    int Gn = 11, Ge = 13; //图的顶点数、边数
    //图的邻接矩阵
    int Gedges[MAXV][MAXV] = {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                              {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}};
    cout << "图8.24无向不带权图G的邻接矩阵如下：" << endl;
    for (int i = 0; i < Gn; ++i) {
        for (int j = 0; j < Gn; ++j) {
            cout << setw(4) << Gedges[i][j];
        }
        cout << endl;
    }
    AdjGraph *L;
    cout << "图G的邻接矩阵转换成邻接表：" << endl;
    MatToList(L, Gedges, Gn, Ge);
    DispAdjGraph(L);
    cout << "以下进行深度优先遍历，请输入起点：";
    cin >> t;
    cout << "以" << t << "为起点的深度优先遍历访问序列是：";
    DFS(L, t, NULL);
    cout << "\n\n";
    cout << "以下进行广度优先遍历，请输入起点：";
    cin >> t;
    cout << "以" << t << "为起点的广度优先遍历访问序列是：";
    BFS(L, t);
    cout << "\n";
    cout << "销毁邻接表";
    DestoryAdj(L);
    return 0;
}