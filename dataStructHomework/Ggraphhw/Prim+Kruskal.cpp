#include <bits/stdc++.h>
#define MAXV 20     //最大顶点个数
#define MaxSize 100 //最大边数
#define INF 32767   //INF表示∞
using namespace std;

typedef int InfoType;

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
} MatGraph;                //图的邻接矩阵类型

typedef struct
{
    int u, v, w;
} Edge;

//创建图邻接矩阵
//传入参数说明，待创建的链接矩阵引用传入，矩阵边二维数组，顶点数，边数
void CreateMatGraph(MatGraph &g, int edges[MAXV][MAXV], int n, int e) {
    g.n = n, g.e = e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = edges[i][j];
        }
}

//输出邻接矩阵g
void DispMat(MatGraph g) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] == INF)
                cout << "∞  ";
            else
                printf("%-3d", g.edges[i][j]);
        cout << endl;
    }
    cout << endl;
}

//普利姆算法
void Prim(MatGraph g, int v) {
    int lowcost[MAXV], closet[MAXV];
    int MIN, k = v; //为了输出第一个起点，此处k需要赋值起点
    for (int i = 0; i < g.n; ++i) {
        lowcost[i] = g.edges[v][i], closet[i] = v;
    }
    for (int i = 1; i < g.n; ++i) {
        printf("%-4d", k);
        MIN = INF;
        for (int j = 0; j < g.n; ++j) {
            if (lowcost[j] && lowcost[j] < MIN) {
                MIN = lowcost[j], k = j;
            }
            printf("(%d,%d):", closet[j], j);
            if (lowcost[j] == INF)
                cout << "∞  ";
            else
                printf("%-3d", lowcost[j]);
        }
        printf("边(%d,%d)权为:%d\n", closet[k], k, MIN);
        lowcost[k] = 0;
        for (int j = 0; j < g.n; ++j) {
            if (lowcost[j] && g.edges[k][j] < lowcost[j]) { //在(V-U)中且距离新加入点更近
                lowcost[j] = g.edges[k][j];
                closet[j] = k;
            }
        }
    }
}

//输出n个字符c
void printc(int n, char c) {
    while (n--) {
        putchar(c);
    }
}

//按照作业要求格式输出普利姆算法
void printPrim(MatGraph g, int v) {
    printc(75, '-');
    putchar('\n');
    cout << "起点";
    printc(8, ' ');
    cout << "lowcost数组保存的侯选边";
    printc(11, ' ');
    cout << "选择的边(不为0的权值中最小者)\n";
    printc(75, '-');
    putchar('\n');
    Prim(g, v);
    printc(75, '-');
    putchar('\n');
}

//根据E中的w权值进行插入排序，e为范围
void InsertSort(Edge E[], int e) {
    for (int i = 1; i < e; ++i) {
        for (int j = i; j > 0 && E[j - 1].w > E[j].w; --j) {
            Edge t = E[j];
            E[j] = E[j - 1];
            E[j - 1] = t;
        }
    }
}

//克鲁斯卡尔算法
void Kruskal(MatGraph g) {
    int vest[MAXV];
    Edge E[MaxSize];
    int k = 0, j = 0;
    for (int i = 0; i < g.n; ++i)
        for (int j = 0; j <= i; ++j) //遍历左下角的三角形区域
            if (g.edges[i][j] && g.edges[i][j] < INF) {
                E[k].u = i, E[k].v = j, E[k].w = g.edges[i][j]; //放一维E里
                ++k;
            }
    InsertSort(E, g.e); //所有边权值从小到大稳定排序
    //******输出初始集合号************//
    cout << "初始集合号: ";
    for (int i = 0; i < g.n; ++i) {
        vest[i] = i;
        printf("%d ", vest[i]);
    }
    cout << endl;
    //*******************************//
    k = 1;
    while (k < g.n) {
        int u1 = E[j].u, v1 = E[j].v;
        int sn1 = vest[u1], sn2 = vest[v1];
        if (sn1 != sn2) {
            cout << "挑选的边:"; //输出被挑选的边
            printf("(%d,%d):%d\n", u1, v1, E[j].w);
            ++k;
            for (int i = 0; i < g.n; ++i)
                if (vest[i] == sn2)
                    vest[i] = sn1;
            //*****输出集合号的变化情况********//
            cout << "集合号: ";
            for (int i = 0; i < g.n; ++i) {
                printf("%d ", vest[i]);
            }
            cout << endl;
            //*******************************//
        } else { //输出舍弃的边
            cout << "舍弃的边:";
            printf("(%d,%d):%d\n", u1, v1, E[j].w);
        }
        ++j;
    }
}

int main() {
    int edges[MAXV][MAXV] = {{0, 6, 1, 5, INF, INF},
                             {6, 0, 5, INF, 3, INF},
                             {1, 5, 0, 5, 6, 4},
                             {5, INF, 5, 0, INF, 2},
                             {INF, 3, 6, INF, 0, 6},
                             {INF, INF, 4, 2, 6, 0}};

    MatGraph g;
    CreateMatGraph(g, edges, 6, 10);
    cout << "矩阵图:\n";
    DispMat(g);
    cout << "普里姆算法:\n";
    for (int i = 0; i < g.n; ++i) {
        printPrim(g, i);
        printf("\n");
    }
    printf("\n");
    cout << "克鲁斯卡尔算法:\n";
    Kruskal(g);
    return 0;
}