#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct node {
    KeyType key;
    InfoType data;
    node *parent;
    struct node *lchild, *rchild;
} BSTNode;

//返回二叉树高度
int BSTHeight(BSTNode *b) {
    int lchildh, rchildh;
    if (b == NULL)
        return 0;
    lchildh = BSTHeight(b->lchild);
    rchildh = BSTHeight(b->rchild);
    return 1 + (lchildh > rchildh ? lchildh : rchildh);
}

//输出二叉树
void DispBSTree(BSTNode *b) {
    if (b) {
        cout << b->data;
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

bool InsetBST(BSTNode *&bt, KeyType k) {
    if (bt == NULL) {
        bt = new BSTNode;
        bt->key = k, bt->lchild = bt->rchild = NULL;
        return true;
    }
    if (k == bt->key)
        return false;
    if (k < bt->key)
        return InsetBST(bt->lchild, k);
    return InsetBST(bt->rchild, k);
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

void Delete1(BSTNode*p,BSTNode*&r){
    BSTNode *q;
    if(r->rchild!=NULL){
        Delete1(p, r->rchild);
        return;}
    p->key = r->key,
    p->data = r->data;
    q = r, r = r->lchild;
    delete q;
}

void Delete(BSTNode*&p){
    BSTNode *q;
    if(p->rchild==NULL){
        q = p, p = p->lchild;
        delete q;
        return;
    }
    if(p->lchild==NULL){
        q = p, p = p->rchild;
        delete q;
        return;
    }
    Delete1(p, p->lchild);
}

bool DeleteBST(BSTNode*&bt,KeyType k){
    if(bt==NULL)
        return false;
    if(k<bt->key)
        return DeleteBST(bt->lchild, k);
    if(k>bt->key)
        return DeleteBST(bt->rchild, k);
    Delete(bt);
    return true;
}

int main() {

    return 0;
}