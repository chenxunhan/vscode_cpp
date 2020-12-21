#include <bits/stdc++.h>
using namespace std;

const double DBL_INF = DBL_MAX / 2;

const int SNOWNUM = 30;
const int NODENUM = 141;
const int LINKNUM = 241;

struct Link {
    double originalDistance = 0; //save dis
    double shorteDistance = 0;
    int importantaceLv = 0;
} link[NODENUM + 1][NODENUM + 1];

// double ShorteDistance[NODENUM + 1][NODENUM + 1];
// int path[NODENUM + 1][NODENUM + 1];

typedef struct {
    int serialNo;
} Node;

// typedef struct     //图的定义
// {
//     int n, e;              //顶点数，边数
//     int edges[NODENUM+1][NODENUM+1]; //邻接矩阵
//     Node vexs[NODENUM+1]; //存放顶点信息
// } CityMatGraph;                //图的邻接矩阵类型

//输出邻接矩阵g
// void fDispMat() {
//     int i, j;
//     for (i = 1; i <= NODENUM; i++) {
//         for (j = 1; j <= NODENUM; j++)
//             if (link[i][j] == DBL_INF)
//                 cout << "∞  ";
//             else
//                 printf("%8.4lf", link[i][j]);
//         cout << endl;
//     }
//     cout << endl;
// }

void fDispMatAndShorteDistance() {
    // int apath[g.n] = {0}, d;
    FILE *fout = fopen("outputg.txt", "w");

    for (int i = 1; i <= NODENUM; i++) {
        for (int j = 1; j <= NODENUM; j++)
            if (link[i][j].originalDistance == DBL_INF)
                fprintf(fout, "   ∞     ,");
            else
                fprintf(fout, "%8.4lf,", link[i][j].shorteDistance);
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");

    for (int i = 1; i <= NODENUM; ++i) {
        for (int j = 1; j <= NODENUM; ++j) {
            if (link[i][j].shorteDistance != DBL_INF) {
                fprintf(fout, "%8.4lf,", link[i][j].shorteDistance);
            }
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

//弗洛伊德算法
void floyd() {
    for (int i = 1; i <= NODENUM; ++i) {
        for (int j = 1; j <= NODENUM; ++j) {
            link[i][j].shorteDistance = link[i][j].originalDistance;
            // if (i != j && g.edges[i][j] != INF) {
            //     path[i][j] = i;
            // } else {
            //     path[i][j] = -1;
            // }
        }
    }
    for (int k = 1; k <= NODENUM; ++k) {
        for (int i = 1; i <= NODENUM; ++i) {
            for (int j = 1; j <= NODENUM; ++j) {
                if (link[i][j].shorteDistance > link[i][k].shorteDistance + link[k][j].shorteDistance) {
                    link[i][j].shorteDistance = link[i][k].shorteDistance + link[k][j].shorteDistance;
                    // path[i][j] = path[k][j];
                }
            }
        }
    }
}

void inputGraph() {
    // memset(link, 0, sizeof(link));
    int na, nb, nplv;
    double odis;
    FILE *fin = fopen("inputg.txt", "r");
    for (int i = 1; i <= NODENUM; ++i) {
        link[i][i].originalDistance = 0;
        for (int j = i + 1; j <= NODENUM; ++j) {
            link[i][j].originalDistance = link[j][i].originalDistance = DBL_INF;
        }
    }
    for (int i = 1; i <= LINKNUM; ++i) {
        fscanf(fin, "%d %d %d %lf", &na, &nb, &nplv, &odis);
        link[na][nb].importantaceLv = nplv;
        link[na][nb].originalDistance = link[nb][na].originalDistance = odis;
    }
    fclose(fin);
}

int main() {
    // int nodeNum, edgeNum;
    // int edges[NODENUM+1][NODENUM+1] = {{0, 1, INF, 4},
    //                          {INF, 0, 9, 2},
    //                          {3, 5, 0, 8},
    //                          {INF, INF, 6, 0}};
    inputGraph();

    // cout << "矩阵图:\n";
    // fDispMat();

    // cout << "弗洛伊德算法:\n";
    floyd();
    fDispMatAndShorteDistance();
    return 0;
}

/*
用C++写出输入边和权值初始化道路的函数 。
测试无向图。
修改结构体合适cleanSnow.cpp
搬入cpp
输出文件diatance表格
*/