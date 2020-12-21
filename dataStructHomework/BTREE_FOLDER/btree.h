#include <bits/stdc++.h>
using namespace std;

//����������ڵ����ݽṹ
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

//����������
void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch) {
        switch (ch) {
        case '(':
            ++top;
            St[top] = p;
            k = 1;
            break;
        case ')':
            --top;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new BTNode;
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) {
                b = p;
            } else {
                switch (k) {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                default:
                    break;
                }
            }
            break;
        }
        ++j;
        ch = str[j];
    }
}

//��b���������ҵ�������ֵΪx�����ڵ�ָ��
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == NULL || b->data == x)
        return b;
    p = FindNode(b->lchild, x);
    if (p != NULL)
        return p;
    return FindNode(b->rchild, x);
}

//���ٶ�����
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        delete b;
    }
}

//���������
void DispBTree(BTNode *b) {
    if (b) {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispBTree(b->lchild);
            if (b->rchild)
                cout << ",";
            DispBTree(b->rchild);
            cout << ")";
        }
    }
}

//�������������ȷ�������
void BTwidthSave(BTNode *b, int w[], int i) {
    if (b != NULL) {
        ++w[i];
        BTwidthSave(b->lchild, w, i + 1);
        BTwidthSave(b->rchild, w, i + 1);
    }
}

//���ؿ�����������Ŀ��
int BTwidth1(int w[], int h) {
    int max = w[1];
    for (int i = 2; i <= h; ++i)
        if (w[i] > max)
            max = w[i];
    return max;
}

//���з�������������
int BTwidth2(BTNode *b) {
    struct
    {
        BTNode *p;
        int level;
    } Qu[MaxSize];
    int front = -1, rear = -1;
    if (b) {
        ++rear;
        Qu[rear].p = b;
        Qu[rear].level = 1;
        while (front != rear) {
            ++front;
            b = Qu[front].p;
            if (b->lchild) {
                ++rear;
                Qu[rear].p = b->lchild;
                Qu[rear].level = Qu[front].level + 1;
            }
            if (b->rchild) {
                ++rear;
                Qu[rear].p = b->lchild;
                Qu[rear].level = Qu[front].level + 1;
            }
        }
        int lnum = 1, max = 1, i = 0;
        while (i <= rear) {
            int j = i;
            while (Qu[i].level == lnum && i <= rear)
                ++i;
            ++lnum;
            max = max > (i - j) ? max : (i - j);
        }
        return max;
    }
    return 0;
}

//���ض������߶�
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == NULL)
        return 0;
    lchildh = BTHeight(b->lchild);
    rchildh = BTHeight(b->rchild);
    return 1 + (lchildh > rchildh ? lchildh : rchildh);
}

//���ض��������ӵ�ָ��
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

//���ض������Һ��ӵ�ָ��
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

//���ض��������н�����
int Nodes(BTNode *b) {
    if (b == NULL)
        return 0;
    return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}

//���ض���������Ҷ�ӽ�����
int LeafNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    return LeafNodes(b->lchild) + LeafNodes(b->rchild);
}

//���ض��������е���֧������
int SingleBranchNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    int n = ((b->lchild == NULL || b->rchild == NULL) && b->lchild != b->rchild); //�������(����֧:��������һ��һ��)���ϣ������ýڵ㣬n=1
    return SingleBranchNodes(b->lchild) + SingleBranchNodes(b->rchild) + n;       //��n�������������ݹ�������Һ��ӵĵ���֧�����
}

//���ض���������˫��֧������
int DoubleBranchNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    int n = (b->lchild != NULL && b->rchild != NULL);                       //�������(˫��֧:��������ȫ��)���ϣ������ýڵ㣬n=1
    return DoubleBranchNodes(b->lchild) + DoubleBranchNodes(b->rchild) + n; //��n�������������ݹ�������Һ��ӵ�˫��֧�����
}

//���������Ͳ���nΪ��k������нڵ���
void Lnodenum(BTNode *b, int h, int k, int &n) { //h��b��ָ����Σ�k����Ҫ����Ľ����
    if (b == NULL)
        return;
    if (h == k) {
        ++n;
        return;
    }
    Lnodenum(b->lchild, h + 1, k, n);
    Lnodenum(b->rchild, h + 1, k, n);
}

//����������Ľ�������
bool DispNode(BTNode *b) { //��㲻Ϊ�����������true�������������0
    if (b == NULL) {
        return 0;
    }
    cout << b->data << endl;
    return 1;
}
