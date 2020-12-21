#include <bits/stdc++.h>
#define MAXV 20     //��󶥵����
#define MaxSize 100 //������
#define INF 32767   //INF��ʾ��
using namespace std;

typedef int InfoType;

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

typedef struct
{
    int u, v, w;
} Edge;

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

//����ķ�㷨
void Prim(MatGraph g, int v) {
    int lowcost[MAXV], closet[MAXV];
    int MIN, k = v; //Ϊ�������һ����㣬�˴�k��Ҫ��ֵ���
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
                cout << "��  ";
            else
                printf("%-3d", lowcost[j]);
        }
        printf("��(%d,%d)ȨΪ:%d\n", closet[k], k, MIN);
        lowcost[k] = 0;
        for (int j = 0; j < g.n; ++j) {
            if (lowcost[j] && g.edges[k][j] < lowcost[j]) { //��(V-U)���Ҿ����¼�������
                lowcost[j] = g.edges[k][j];
                closet[j] = k;
            }
        }
    }
}

//���n���ַ�c
void printc(int n, char c) {
    while (n--) {
        putchar(c);
    }
}

//������ҵҪ���ʽ�������ķ�㷨
void printPrim(MatGraph g, int v) {
    printc(75, '-');
    putchar('\n');
    cout << "���";
    printc(8, ' ');
    cout << "lowcost���鱣��ĺ�ѡ��";
    printc(11, ' ');
    cout << "ѡ��ı�(��Ϊ0��Ȩֵ����С��)\n";
    printc(75, '-');
    putchar('\n');
    Prim(g, v);
    printc(75, '-');
    putchar('\n');
}

//����E�е�wȨֵ���в�������eΪ��Χ
void InsertSort(Edge E[], int e) {
    for (int i = 1; i < e; ++i) {
        for (int j = i; j > 0 && E[j - 1].w > E[j].w; --j) {
            Edge t = E[j];
            E[j] = E[j - 1];
            E[j - 1] = t;
        }
    }
}

//��³˹�����㷨
void Kruskal(MatGraph g) {
    int vest[MAXV];
    Edge E[MaxSize];
    int k = 0, j = 0;
    for (int i = 0; i < g.n; ++i)
        for (int j = 0; j <= i; ++j) //�������½ǵ�����������
            if (g.edges[i][j] && g.edges[i][j] < INF) {
                E[k].u = i, E[k].v = j, E[k].w = g.edges[i][j]; //��һάE��
                ++k;
            }
    InsertSort(E, g.e); //���б�Ȩֵ��С�����ȶ�����
    //******�����ʼ���Ϻ�************//
    cout << "��ʼ���Ϻ�: ";
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
            cout << "��ѡ�ı�:"; //�������ѡ�ı�
            printf("(%d,%d):%d\n", u1, v1, E[j].w);
            ++k;
            for (int i = 0; i < g.n; ++i)
                if (vest[i] == sn2)
                    vest[i] = sn1;
            //*****������Ϻŵı仯���********//
            cout << "���Ϻ�: ";
            for (int i = 0; i < g.n; ++i) {
                printf("%d ", vest[i]);
            }
            cout << endl;
            //*******************************//
        } else { //��������ı�
            cout << "�����ı�:";
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
    cout << "����ͼ:\n";
    DispMat(g);
    cout << "����ķ�㷨:\n";
    for (int i = 0; i < g.n; ++i) {
        printPrim(g, i);
        printf("\n");
    }
    printf("\n");
    cout << "��³˹�����㷨:\n";
    Kruskal(g);
    return 0;
}