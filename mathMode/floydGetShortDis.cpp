#include <bits/stdc++.h>
using namespace std;

const double DBL_INF = DBL_MAX / 2;

const int SNOWNUM = 3;
const int NODENUM = 9;
const int LINKNUM = 12;

struct Link {
    double originalDistance = 0; //save dis
    double shorteDistance = 0;
    int width = 0;
    int importantaceLv = 0;
} link[NODENUM + 1][NODENUM + 1];

typedef struct {
    int serialNo;
} Node;

void fDispMatAndShorteDistance() {
    FILE *fout = fopen("outputg.txt", "w");

    for (int i = 1; i <= NODENUM; i++) {
        for (int j = 1; j <= NODENUM; j++)
            if (link[i][j].originalDistance == DBL_INF)
                fprintf(fout, "   ��     ,");
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

//���������㷨
void floyd() {
    for (int i = 1; i <= NODENUM; ++i) {
        for (int j = 1; j <= NODENUM; ++j) {
            link[i][j].shorteDistance = link[i][j].originalDistance;
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
    int na, nb, wid, nplv;
    double odis;
    FILE *fin = fopen("inputg.txt", "r");
    for (int i = 1; i <= NODENUM; ++i) {
        link[i][i].originalDistance = 0;
        for (int j = i + 1; j <= NODENUM; ++j) {
            link[i][j].originalDistance = link[j][i].originalDistance = DBL_INF;
        }
    }
    for (int i = 1; i <= LINKNUM; ++i) {
        fscanf(fin, "%d %d %d %d %lf", &na, &nb, &wid, &nplv, &odis);
        link[na][nb].width = link[nb][na].width = wid;
        link[na][nb].importantaceLv = link[nb][na].importantaceLv = nplv;
        link[na][nb].originalDistance = link[nb][na].originalDistance = odis;
    }
    fclose(fin);
}

int main() {
    inputGraph();
    floyd();
    fDispMatAndShorteDistance();
    return 0;
}

/*
��C++д������ߺ�Ȩֵ��ʼ����·�ĺ��� ��
��������ͼ��
�޸Ľṹ�����cleanSnow.cpp
����cpp
����ļ�diatance���
*/