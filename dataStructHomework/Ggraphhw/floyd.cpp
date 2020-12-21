#include <bits/stdc++.h>
#define MAXV 40     //最大顶点个数
#define MaxSize 200 //最大边数
#define INF INT_MAX   //INF表示∞
using namespace std;

typedef int InfoType;
typedef double edgeType;

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

//按照作业格式输出路径长度和路径过程
void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
    int apath[g.n] = {0}, d;
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            if (A[i][j] != INF) {
                printf("从%d到%d的路径长度为:%d\t", i, j, A[i][j]);
                int k = path[i][j];
                apath[d = 0] = j;
                while (k != -1 && k != i) {
                    apath[++d] = k;
                    k = path[i][k];
                }
                apath[++d] = i;
                cout << apath[d];
                for (int s = d - 1; s >= 0; --s) {
                    cout << "→" << apath[s];
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}

//输出n个字符c
void printc(int n, char c) {
    while (n--) {
        putchar(c);
    }
}
//输出n个字符c并输出换行符
void printcln(int n, char c) {
    while (n--) {
        putchar(c);
    }
    putchar('\n');
}

//按照作业格式同时输出path和A
void Disp_path_A(int A[][MAXV], int path[][MAXV], int n, int k) {
    printcln(68, '-');
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            printf("path(%2d)=", k);
        } else {
            printc(9, ' ');
        }
        cout << "|";
        for (int j = 0; j < n; ++j) {
            int k = path[i][j], d = 0;
            int apath[n] = {j};
            while (k != -1 && k != i) {
                apath[++d] = k;
                k = path[i][k];
            }
            apath[++d] = i;
            printc(n - d, ' ');
            cout << apath[d];
            for (int s = d - 1; s >= 0; --s) {
                cout << apath[s];
            }
        }
        cout << "  |";
        if (i == 0) {
            printf("   A(%2d)=", k);
        } else {
            printc(9, ' ');
        }
        cout << "|";
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INF)
                cout << "    ∞";
            else
                printf("%5d", A[i][j]);
        }
        cout << "  |\n";
    }
    if (k == n - 1)
        printcln(68, '-');
}

//弗洛伊德算法
void floyd(MatGraph g) {
    int A[MAXV][MAXV], path[MAXV][MAXV];
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] != INF) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    Disp_path_A(A, path, g.n, -1);
    for (int k = 0; k < g.n; ++k) {
        for (int i = 0; i < g.n; ++i) {
            for (int j = 0; j < g.n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
        Disp_path_A(A, path, g.n, k);
    }
    Dispath(g, A, path);
}

int main() {
    int edges[MAXV][MAXV] = {{0, 1, INF, 4},
                             {INF, 0, 9, 2},
                             {3, 5, 0, 8},
                             {INF, INF, 6, 0}};
    MatGraph g;
    CreateMatGraph(g, edges, 141, 241);

    cout << "矩阵图:\n";
    DispMat(g);

    cout << "弗洛伊德算法:\n";
    floyd(g);
    return 0;
}