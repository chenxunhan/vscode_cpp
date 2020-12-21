#include <bits/stdc++.h>
#define MAXV 20 //�������20��
using namespace std;

typedef struct {
    int edges[MAXV][MAXV]; //������򲻴�Ȩͼ�ı���Ϣ
    int n, e;              //������������
    /*���ڴ˴���ҵ�Ķ���ڵ�ֻ�б��û��������Ϣ��
    ��˲����ô��������Ϣ*/
} MatGraph; //���򲻴�Ȩͼ

typedef struct ANode {
    int adjvex;            //���
    struct ANode *nextarc; //��һ���ڵ�ָ��
    /*��ҵ�����򲻴�Ȩͼ����Ȩֵ����˲����ô��Ȩֵ��Ϣ*/
} ArcNode;

typedef struct Vnode {
    /*���ڴ˴���ҵ�Ķ���ڵ�ֻ�б��û��������Ϣ��
    ��˲����ô��������Ϣ*/
    ArcNode *firstarc; //��һ���ڵ�ָ��
} VNode;

typedef struct {
    VNode adjlist[MAXV]; //����
    int n, e;            //������������
} AdjGraph;              //�ڽӱ�

//����ڽӱ�
void DispAdjGraph(AdjGraph *G) {
    ArcNode *p;
    for (int ni = 0; ni < G->n; ++ni) { //��������
        cout << ni;
        p = G->adjlist[ni].firstarc; //ָ���һ���ڵ�
        while (p) {                  //���սڵ����ֵ
            cout << "--->" << p->adjvex;
            p = p->nextarc; //ָ����һ���ڵ�
        }
        cout << "^" << endl; //��β���
    }
}

//�ڽӾ���ת�ڽӱ�
void MatToList(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    G = new AdjGraph;
    G->n = n, G->e = e;
    ArcNode *p;
    for (int i = 0; i < n; ++i) //����ָ��ĵ�һ���ڵ��ÿ�
        G->adjlist[i].firstarc = NULL;
    for (int i = 0; i < n; ++i)            //����������
        for (int j = n - 1; j >= 0; --j) { //����������
            if (A[i][j] != 0) {            //�ڽӱ���
                p = new ArcNode;
                p->adjvex = j;
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

//������ȱ���
void DFS(AdjGraph *G, int v, bool *visited) { //�������������visitedΪNULL
    if (visited == NULL) {                    //visited��Ϊ��
        bool newvisited[MAXV] = {0};          //�½������¼���鲢����
        visited = newvisited;                 //�����¼����ͷָ�븴��
    }
    int w;
    visited[v] = 1;
    cout << setw(4) << v;
    ArcNode *p = G->adjlist[v].firstarc;
    while (p) {
        w = p->adjvex;
        if (!visited[w]) //����¼������δ��¼�ñ���
            DFS(G, w, visited);
        p = p->nextarc;
    }
}

//������ȱ���
void BFS(AdjGraph *G, int v) {
    int w;
    ArcNode *p;
    struct {
        int data[MAXV];
        int front = -1, rear = -1;
    } qu;                     //���нṹ
    bool visited[MAXV] = {0}; //�½������¼���鲢����
    cout << setw(4) << v;     //������
    visited[v] = 1;           //��¼���
    ++qu.front;               //����
    qu.data[qu.front] = v;    //����
    while (qu.front != qu.rear) {
        ++qu.rear;            //����
        w = qu.data[qu.rear]; //����
        p = G->adjlist[w].firstarc;
        while (p) {                            //ֻҪ���㲻Ϊ��
            if (visited[p->adjvex] == 0) {     //��δ��¼
                cout << setw(4) << p->adjvex;  //���
                visited[p->adjvex] = 1;        //��¼
                ++qu.front;                    //����
                qu.data[qu.front] = p->adjvex; //����
            }
            p = p->nextarc;
        }
    }
    cout << endl;
}

int main() {
    //ͼ8.24
    int t;
    int Gn = 11, Ge = 13; //ͼ�Ķ�����������
    //ͼ���ڽӾ���
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
    cout << "ͼ8.24���򲻴�ȨͼG���ڽӾ������£�" << endl;
    for (int i = 0; i < Gn; ++i) {
        for (int j = 0; j < Gn; ++j) {
            cout << setw(4) << Gedges[i][j];
        }
        cout << endl;
    }
    AdjGraph *L;
    cout << "ͼG���ڽӾ���ת�����ڽӱ�" << endl;
    MatToList(L, Gedges, Gn, Ge);
    DispAdjGraph(L);
    cout << "���½���������ȱ�������������㣺";
    cin >> t;
    cout << "��" << t << "Ϊ����������ȱ������������ǣ�";
    DFS(L, t, NULL);
    cout << "\n\n";
    cout << "���½��й�����ȱ�������������㣺";
    cin >> t;
    cout << "��" << t << "Ϊ���Ĺ�����ȱ������������ǣ�";
    BFS(L, t);
    cout << "\n";
    cout << "�����ڽӱ�";
    DestoryAdj(L);
    return 0;
}