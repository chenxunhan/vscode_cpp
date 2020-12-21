#include <bits/stdc++.h>
#define MAXV 20   //�������20��
#define INF 32767 //���������
using namespace std;

typedef struct {
    int edges[MAXV][MAXV]; //���ͼ�ı���Ϣ
    int n, e;              //������������
    /*���ڴ˴���ҵ�Ķ���ڵ�ֻ�б��û��������Ϣ��
    ��˲����ô��������Ϣ*/
} MatGraph; //����ͼ

typedef struct ANode {
    int adjvex;            //���
    struct ANode *nextarc; //��һ���ڵ�ָ��
    int weight;            //Ȩֵ
} ArcNode;                 //�ڽӱ�ڵ�

typedef struct Vnode {
    /*���ڴ˴���ҵ�Ķ���ڵ�ֻ�б��û��������Ϣ��
    ��˲����ô��������Ϣ*/
    ArcNode *firstarc; //�ڽӱ�����һ���ڵ�ָ��
} VNode;

typedef struct {
    VNode adjlist[MAXV]; //�ڽӱ�ı���
    int n, e;
} AdjGraph; //�ڽӱ�

//����ڽӾ���ͼ
void DispMatGraph(MatGraph G) {
    for (int i = 0; i < G.n; ++i) {
        for (int j = 0; j < G.n; ++j) {
            if (G.edges[i][j] == INF) //������������
                printf("   ��");
            else
                printf("%4d", G.edges[i][j]); //�������
        }
        cout << endl;
    }
}

//����ڽӱ�
void DispAdjGraph(AdjGraph *G) {
    ArcNode *p;
    for (int ni = 0; ni < G->n; ++ni) { //��������
        cout << ni;
        p = G->adjlist[ni].firstarc;                          //ָ���һ���ڵ�
        while (p) {                                           //���սڵ����ֵ
            cout << "---->" << p->adjvex << "," << p->weight; //��������Ȩֵ
            p = p->nextarc;                                   //ָ����һ���ڵ�
        }
        cout << "^" << endl; //��β���
    }
}

//�ڽӱ�ת���ڽӾ���
void ListToMat(AdjGraph *G, MatGraph &g) {
    g.n = G->n, g.e = G->e;
    ArcNode *p;
    for (int i = 0; i < G->n; ++i) {
        for (int j = 0; j < G->n; ++j)
            g.edges[i][j] = (i == j ? 0 : INF); //����λ��ȣ���ֵ0�����������
        p = G->adjlist[i].firstarc;
        while (p) {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
}

//�ڽӾ���ת�ڽӱ�
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

//�����ڽӱ�
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
    //ͼ8.54
    /*int Gn = 6, Ge = 10;
    int Gedges[MAXV][MAXV] = {{0, 5, INF, 7, INF, INF},
                              {INF, 0, 4, INF, INF, INF},
                              {8, INF, 0, INF, INF, 9},
                              {INF, INF, 5, 0, INF, 6},
                              {INF, INF, INF, 5, 0, INF},
                              {3, INF, INF, INF, 1, 0}};
    cout << "ͼ8.54����ͼG���ڽӾ���" << endl;*/

    //ͼ8.55
    int Gn = 6, Ge = 10;
    int Gedges[MAXV][MAXV] = {{0, 5, 8, 7, INF, 3},
                              {5, 0, 4, INF, INF, INF},
                              {8, 4, 0, 5, INF, 9},
                              {7, INF, 5, 0, 5, 6},
                              {INF, INF, INF, 5, 0, 1},
                              {3, INF, 9, 6, 1, 0}};
    cout << "ͼ8.55����ͼG���ڽӾ���" << endl;

    for (int i = 0; i < Gn; ++i) {
        for (int j = 0; j < Gn; ++j) {
            if (Gedges[i][j] == INF)
                printf("   ��");
            else
                printf("%4d", Gedges[i][j]);
        }
        cout << endl;
    }
    AdjGraph *L;
    MatToList(L, Gedges, Gn, Ge);
    cout << "ͼG���ڽӾ���ת�����ڽӱ�" << endl;
    DispAdjGraph(L);
    MatGraph G2;
    ListToMat(L, G2);
    cout << "ͼG���ڽӱ�ת�����ڽӾ���" << endl;
    DispMatGraph(G2);
    cout << "�����ڽӱ�";
    DestoryAdj(L);
    return 0;
}