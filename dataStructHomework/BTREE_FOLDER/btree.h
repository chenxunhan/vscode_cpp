#include <bits/stdc++.h>
using namespace std;

//定义二叉树节点数据结构
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

//创建二叉树
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

//在b二叉树中找到并返回值为x的树节点指针
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == NULL || b->data == x)
        return b;
    p = FindNode(b->lchild, x);
    if (p != NULL)
        return p;
    return FindNode(b->rchild, x);
}

//销毁二叉树
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        delete b;
    }
}

//输出二叉树
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

//将二叉树各层宽度放入数组
void BTwidthSave(BTNode *b, int w[], int i) {
    if (b != NULL) {
        ++w[i];
        BTwidthSave(b->lchild, w, i + 1);
        BTwidthSave(b->rchild, w, i + 1);
    }
}

//返回宽度数组中最大的宽度
int BTwidth1(int w[], int h) {
    int max = w[1];
    for (int i = 2; i <= h; ++i)
        if (w[i] > max)
            max = w[i];
    return max;
}

//队列法求出二叉树宽度
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

//返回二叉树高度
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == NULL)
        return 0;
    lchildh = BTHeight(b->lchild);
    rchildh = BTHeight(b->rchild);
    return 1 + (lchildh > rchildh ? lchildh : rchildh);
}

//返回二叉树左孩子的指针
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

//返回二叉树右孩子的指针
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

//返回二叉树所有结点个数
int Nodes(BTNode *b) {
    if (b == NULL)
        return 0;
    return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}

//返回二叉树所有叶子结点个数
int LeafNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    return LeafNodes(b->lchild) + LeafNodes(b->rchild);
}

//返回二叉树所有单分支结点个数
int SingleBranchNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    int n = ((b->lchild == NULL || b->rchild == NULL) && b->lchild != b->rchild); //如果条件(单分支:两个孩子一空一有)符合，计数该节点，n=1
    return SingleBranchNodes(b->lchild) + SingleBranchNodes(b->rchild) + n;       //将n计入结果，继续递归计算左右孩子的单分支结点数
}

//返回二叉树所有双分支结点个数
int DoubleBranchNodes(BTNode *b) {
    if (b == NULL)
        return 0;
    int n = (b->lchild != NULL && b->rchild != NULL);                       //如果条件(双分支:两个孩子全有)符合，计数该节点，n=1
    return DoubleBranchNodes(b->lchild) + DoubleBranchNodes(b->rchild) + n; //将n计入结果，继续递归计算左右孩子的双分支结点数
}

//设置引用型参数n为第k层的所有节点数
void Lnodenum(BTNode *b, int h, int k, int &n) { //h是b所指结点层次，k是所要计算的结点层次
    if (b == NULL)
        return;
    if (h == k) {
        ++n;
        return;
    }
    Lnodenum(b->lchild, h + 1, k, n);
    Lnodenum(b->rchild, h + 1, k, n);
}

//输出二叉树的结点的数据
bool DispNode(BTNode *b) { //结点不为空输出并返回true，否则不输出返回0
    if (b == NULL) {
        return 0;
    }
    cout << b->data << endl;
    return 1;
}
