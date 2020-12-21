#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct node {
    KeyType key;
    InfoType data;
    struct node *lchild, *rchild;
} BSTNode;

BSTNode *BSTNodeParent(BSTNode *bt, BSTNode *knode) {
    if (bt == NULL || bt->key == knode->key)
        return NULL;
    if (knode->key < bt->key) {
        if (bt->lchild->key == knode->key) {
            return bt;
        }
        return BSTNodeParent(bt->lchild, knode);
    }
    if (bt->rchild->key == knode->key) {
        return bt;
    }
    return BSTNodeParent(bt->rchild, knode);
}
/*
BSTNode *BSTNodeParent(BSTNode *bt, KeyType key) {
    if (bt == NULL || bt->key == key)
        return NULL;
    if (key < bt->key) {
        if (bt->lchild->key == key) {
            return bt;
        }
        return BSTNodeParent(bt->lchild, key);
    }
    if (bt->rchild->key == key) {
        return bt;
    }
    return BSTNodeParent(bt->rchild, key);
}*/

//返回二叉树高度
int BSTHeight(BSTNode *b) {
    if (b == NULL)
        return 0;
    int lchildh, rchildh;
    lchildh = BSTHeight(b->lchild);
    rchildh = BSTHeight(b->rchild);
    return 1 + (lchildh > rchildh ? lchildh : rchildh);
}

int BSTNodebf(BSTNode *bt) {
    if (bt == NULL)
        return 0;
    return BSTHeight(bt->lchild) - BSTHeight(bt->rchild);
}

//输出二叉树
void DispBSTree(BSTNode *b) {
    if (b) {
        printf("%2d", b->key);
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispBSTree(b->lchild);
            if (b->rchild)
                cout << ",";
            DispBSTree(b->rchild);
            cout << ")";
        }
    }
}

//输出二叉树bf
void DispBSTreebf(BSTNode *b) {
    if (b) {
        //printf("%2d", b->bf);
        printf("%2d", BSTNodebf(b));
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispBSTreebf(b->lchild);
            if (b->rchild)
                cout << ",";
            DispBSTreebf(b->rchild);
            cout << ")";
        }
    }
}

//输出二叉树各节点双亲
void DispBSTreeParent(BSTNode *bt, BSTNode *b) {
    if (b && BSTNodeParent(bt, b)) {
        printf("%2d", BSTNodeParent(bt, b)->key);
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispBSTreeParent(bt, b->lchild);
            if (b->rchild)
                cout << ",";
            DispBSTreeParent(bt, b->rchild);
            cout << ")";
        }
    } else {
        cout << "**";
    }
}

bool InsetBST(BSTNode *&bt, KeyType k) {
    if (bt == NULL) {
        bt = new BSTNode;
        bt->key = k, bt->lchild = bt->rchild = NULL;
        return true;
    }
    if (k == bt->key)
        return false;
    bool re;
    if (k < bt->key)
        re = InsetBST(bt->lchild, k);
    else
        re = InsetBST(bt->rchild, k);
    return re;
}

BSTNode *CreateBST(KeyType A[], int n) {
    BSTNode *bt = NULL;
    for (int i = 0; i < n; ++i) {
        InsetBST(bt, A[i]);
    }
    return bt;
}

BSTNode *SearchBST(BSTNode *bt, KeyType k) {
    if (bt == NULL || bt->key == k)
        return bt;
    if (k < bt->key)
        return SearchBST(bt->lchild, k);
    return SearchBST(bt->rchild, k);
}

BSTNode *NotBalancedNode(BSTNode *bt, BSTNode *last) {
    if (bt == NULL || last == NULL)
        return NULL;
    while (bt != last) {
        if (abs(BSTNodebf(last)) > 1)
            return last;
        last = BSTNodeParent(bt, last);
    };
    if (abs(BSTNodebf(last)) > 1)
        return last;
    return NULL;
}

void LL(BSTNode *&bt) {
    BSTNode *B = bt->lchild;
    BSTNode *A = new BSTNode;
    A->lchild = B->rchild, A->rchild = bt->rchild;
    A->key = bt->key;
    bt->lchild = B->lchild, bt->rchild = A;
    bt->key = B->key;
    delete B;
}

void RR(BSTNode *&bt) {
    BSTNode *B = bt->rchild;
    BSTNode *A = new BSTNode;
    A->lchild = bt->lchild, A->rchild = B->lchild;
    A->key = bt->key;
    bt->lchild = A, bt->rchild = B->rchild;
    bt->key = B->key;
    delete B;
}

void LR(BSTNode *&bt) {
    BSTNode *C = bt->lchild->rchild, *B = bt->lchild;
    BSTNode *A = new BSTNode;
    A->lchild = C->rchild, A->rchild = bt->rchild;
    A->key = bt->key;
    B->rchild = C->lchild;
    bt->key = C->key, bt->rchild = A;
    delete C;
}

void RL(BSTNode *&bt) {
    BSTNode *C = bt->rchild->lchild, *B = bt->rchild;
    BSTNode *A = new BSTNode;
    A->lchild = bt->lchild, A->rchild = C->rchild;
    A->key = bt->key;
    B->lchild = C->rchild;
    bt->key = C->key, bt->lchild = A;
    delete C;
}

string BalanceChange(BSTNode *&bt, KeyType ikey) {
    if (BSTNodebf(bt) == 2) {
        if (ikey < bt->lchild->key) {
            LL(bt);
            return "LL";
        }
        LR(bt);
        return "LR";
    }
    //bt->bf==-2
    if (ikey > bt->rchild->key) {
        RR(bt);
        return "RR";
    }
    RL(bt);
    return "RL";
}

string BalanceChange2(BSTNode *&bt, BSTNode *knode) {
    if (BSTNodebf(bt) == -2) {
        if (BSTNodebf(bt->rchild) == -1) {
            RR(bt);
            return "RR";
        }
        RL(bt);
        return "RL";
    }
    if (BSTNodebf(bt->lchild) == -1) {
        LR(bt);
        return "LR";
    }
    LL(bt);
    return "LL";
}

void Delete1(BSTNode *p, BSTNode *&r, BSTNode *&knode) {
    BSTNode *q;
    if (r->rchild != NULL) {
        Delete1(p, r->rchild, knode);
        return;
    }
    p->key = r->key, p->data = r->data;
    q = r;
    r = r->lchild;
    delete q;
    knode = r;
}

void Delete(BSTNode *&p, BSTNode *&knode) {
    BSTNode *q;
    if (p->rchild == NULL) {
        q = p, p = p->lchild;
        delete q;
        return;
    }
    if (p->lchild == NULL) {
        q = p, p = p->rchild;
        delete q;
        return;
    }
    Delete1(p, p->lchild, knode);
}

bool DeleteBST(BSTNode *&bt, KeyType k, BSTNode *&knode) {
    knode = NULL;
    if (bt == NULL)
        return false;
    if (k < bt->key)
        return DeleteBST(bt->lchild, k, knode);
    if (k > bt->key)
        return DeleteBST(bt->rchild, k, knode);
    Delete(bt, knode);
    return true;
}

void print(BSTNode *bt) {
    cout << "  输出平衡二叉树:";
    DispBSTree(bt);
    cout << "\n各节点平衡因子为:";
    DispBSTreebf(bt);
    cout << "\n";
}

//销毁二叉树
void DestroyBSTree(BSTNode *&b) {
    if (b != NULL) {
        DestroyBSTree(b->lchild);
        DestroyBSTree(b->rchild);
        delete b;
    }
}

int main() {
    /*
    int n = 9;
    KeyType key[9] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    cout << "示例1";
    */
    int n = 10;
    KeyType key[10] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
    cout << "示例2";

    cout << "创建平衡二叉树...\n\n";
    BSTNode *bt = NULL;
    for (int i = 0; i < n; ++i) {
        cout << "            插入:" << key[i] << endl;
        InsetBST(bt, key[i]);
        print(bt);
        cout << "\n\n";
        if (BSTNode *t = NotBalancedNode(bt, SearchBST(bt, key[i]))) {
            printf("节点%2d失衡,", t->key);
            printf("进行%s型调整...\n", BalanceChange(t, key[i]).c_str());
            print(bt);
        }
    }
    KeyType deletekey;
    while (1) {
        cout << "\n请输入要删除的节点(按Ctrl+Z退出):";
        if (cin >> deletekey) {
            BSTNode *knode;
            DeleteBST(bt, deletekey, knode);
            if (knode != NULL) {
                print(bt);
                BSTNode *t = NotBalancedNode(bt, knode);
                printf("节点%2d失衡,", t->key);
                printf("进行%s型调整...\n", BalanceChange2(bt, SearchBST(t, knode->key)).c_str());
            }
            cout << "删除成功!\n";
            print(bt);
        } else
            break;
    };
    if (bt == NULL) {
        cout << "BST二叉平衡树已空\n";
    }
    DestroyBSTree(bt);

    return 0;
}