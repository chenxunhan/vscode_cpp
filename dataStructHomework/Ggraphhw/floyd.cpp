#include <bits/stdc++.h>
#define MAXV 40     //��󶥵����
#define MaxSize 200 //������
#define INF INT_MAX   //INF��ʾ��
using namespace std;

typedef int InfoType;
typedef double edgeType;

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
} MatGraph;                //ͼ���ڽӾ�������

//����ͼ�ڽӾ���
//�������˵���������������Ӿ������ô��룬����߶�ά���飬������������
void CreateMatGraph(MatGraph &g, int edges[MAXV][MAXV], int n, int e) {
    g.n = n, g.e = e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = edges[i][j];
        }
}

//����ڽӾ���g
void DispMat(MatGraph g) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] == INF)
                cout << "��  ";
            else
                printf("%-3d", g.edges[i][j]);
        cout << endl;
    }
    cout << endl;
}

//������ҵ��ʽ���·�����Ⱥ�·������
void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
    int apath[g.n] = {0}, d;
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            if (A[i][j] != INF) {
                printf("��%d��%d��·������Ϊ:%d\t", i, j, A[i][j]);
                int k = path[i][j];
                apath[d = 0] = j;
                while (k != -1 && k != i) {
                    apath[++d] = k;
                    k = path[i][k];
                }
                apath[++d] = i;
                cout << apath[d];
                for (int s = d - 1; s >= 0; --s) {
                    cout << "��" << apath[s];
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}

//���n���ַ�c
void printc(int n, char c) {
    while (n--) {
        putchar(c);
    }
}
//���n���ַ�c��������з�
void printcln(int n, char c) {
    while (n--) {
        putchar(c);
    }
    putchar('\n');
}

//������ҵ��ʽͬʱ���path��A
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
                cout << "    ��";
            else
                printf("%5d", A[i][j]);
        }
        cout << "  |\n";
    }
    if (k == n - 1)
        printcln(68, '-');
}

//���������㷨
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

    cout << "����ͼ:\n";
    DispMat(g);

    cout << "���������㷨:\n";
    floyd(g);
    return 0;
}