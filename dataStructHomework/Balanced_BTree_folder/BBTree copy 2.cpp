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
        bt->bf = 0;
        return true;
    }
    if (k == bt->key)
        return false;
    bool re;
    if (k < bt->key)
        re = InsetBST(bt->lchild, k);
    else
        re = InsetBST(bt->rchild, k);
    bt->bf = BSTNodebf(bt);
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

BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f) {
    if (bt == NULL)
        return f = NULL;
    if (k == bt->key) {
        f = f1;
        return bt;
    }
    if (k < bt->key)
        return SearchBST1(bt->lchild, k, bt, f);
    return SearchBST1(bt->rchild, k, bt, f);
}

/*bool deletep(BSTNode *&p){
    BSTNode *q;
    q = p, p = p->rchild;
    delete q;
}

bool deletek(BSTNode *&bt, KeyType k) {
    if (bt == NULL)
        return false;
    if (k == bt->key) {
        deletep(bt);
        return true;
    }
    if (k < bt->key)
        deletek(bt->lchild, k);
    else
        deletek(bt->rchild, k);
}*/

void Delete1(BSTNode *p, BSTNode *&r) {
    BSTNode *q;
    if (r->rchild != NULL) {
        Delete1(p, r->rchild);
        return;
    }
    p->key = r->key,
    p->data = r->data;
    q = r, r = r->lchild;
    delete q;
}

void Delete(BSTNode *&p) {
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
    Delete1(p, p->lchild);
}

bool DeleteBST(BSTNode *&bt, KeyType k) {
    if (bt == NULL)
        return false;
    if (k < bt->key)
        return DeleteBST(bt->lchild, k);
    if (k > bt->key)
        return DeleteBST(bt->rchild, k);
    Delete(bt);
    return true;
}

BSTNode *NotBalancedNode(BSTNode *bt, BSTNode *last) {
    if (bt == NULL || last == NULL)
        return NULL;
    while (bt != last) {
        if (abs(last->bf) > 1)
            return last;
        last = BSTNodeParent(bt, last);
    };
    if (abs(last->bf) > 1)
        return last;
    return NULL;
}

void LL(BSTNode *&bt) {
    BSTNode *B = bt->lchild;
    BSTNode *A = new BSTNode;
    A->lchild = B->rchild, A->rchild = bt->rchild;
    A->key = bt->key, A->bf = BSTNodebf(A);
    bt->lchild = B->lchild, bt->rchild = A;
    bt->key = B->key, bt->bf = BSTNodebf(bt);
    delete B;
}

void RR(BSTNode *&bt) {
    BSTNode *B = bt->rchild;
    BSTNode *A = new BSTNode;
    A->lchild = bt->lchild, A->rchild = B->lchild;
    A->key = bt->key, A->bf = BSTNodebf(A);
    bt->lchild = A, bt->rchild = B->rchild;
    bt->key = B->key, bt->bf = BSTNodebf(bt);
    delete B;
}

void LR(BSTNode *&bt) {
    BSTNode *C = bt->lchild->rchild, *B = bt->lchild;
    BSTNode *A = new BSTNode;
    A->lchild = C->rchild, A->rchild = bt->rchild;
    A->key = bt->key, A->bf = BSTNodebf(A);
    B->rchild = C->lchild, B->bf = BSTNodebf(B);
    bt->key = C->key, bt->rchild = A, bt->bf = BSTNodebf(bt);
    delete C;
}

void RL(BSTNode *&bt) {
    BSTNode *C = bt->rchild->lchild, *B = bt->rchild;
    BSTNode *A = new BSTNode;
    A->lchild = bt->lchild, A->rchild = C->rchild;
    A->key = bt->key, A->bf = BSTNodebf(A);
    B->lchild = C->rchild, B->bf = BSTNodebf(B);
    bt->key = C->key, bt->lchild = A, bt->bf = BSTNodebf(bt);
    delete C;
}

string BalanceChange(BSTNode *&bt, KeyType ikey) {
    if (bt->bf == 2) {
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

int main() {
    KeyType key[9] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    cout << "创建平衡二叉树...\n\n";
    BSTNode *bt = NULL;
    for (int i = 0; i < 9; ++i) {
        cout << "            插入:" << key[i] << endl;
        InsetBST(bt, key[i]);
        cout << "  输出平衡二叉树:";
        DispBSTree(bt);
        cout << "\n各节点平衡因子为:";
        DispBSTreebf(bt);
        cout << "\n插入节点双亲节点:";
        DispBSTreeParent(bt, SearchBST(bt, key[i]));
        cout << "\n\n";
        if (BSTNode *t = NotBalancedNode(bt, SearchBST(bt, key[i]))) {
            if (key[i] == 9) {
                cout << "-----------------" << t->key << endl;
                printf("节点%2d失衡,进行型调整...\n", t->key);
                //break;
            }
            printf("节点%2d失衡,", t->key);
            printf("进行%s型调整...\n", BalanceChange(t, key[i]).c_str());
            cout << "  输出平衡二叉树:";
            DispBSTree(bt);
            cout << "\n各节点平衡因子为:";
            DispBSTreebf(bt);
            cout << "\n插入节点双亲节点:";
            DispBSTreeParent(bt, SearchBST(bt, key[i]));
            cout << "\n\n";
        }
    }
    return 0;
}