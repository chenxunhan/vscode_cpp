//元素类型定义为char
typedef char ElemType;
#define MaxSize 100
#define N 30       //凹入表示法根节点的输出'='数
#include "btree.h" //包含二叉树数据结构和基本运算

//输出num个字符c
void print(int num, char c) {
    while (num--)
        cout << c;
}

//1，先序遍历输出该树:
void PreDispBTree(BTNode *b) {
    if (b) {
        cout << b->data;
        PreDispBTree(b->lchild);
        PreDispBTree(b->rchild);
    } else //空节点输出^
        cout << "^";
}

//5，输出该树的先序凹入表表示法:
void PreDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        print(N - num, ' '); //先输出n-num个' '
        cout << b->data;     //输出结点数据
        print(num, '=');     //后输出n-num个'='
        cout << c << endl;
        PreDispBTree2(b->lchild, num - 3, 'L');
        PreDispBTree2(b->rchild, num - 3, 'R');
    }
}

//2，中序遍历输出该树:
void InDispBTree(BTNode *b) {
    if (b) {
        InDispBTree(b->lchild);
        cout << b->data;
        InDispBTree(b->rchild);
    } else //空节点输出^
        cout << "^";
}

//6，输出该树的中序凹入表表示法:
void InDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        InDispBTree2(b->lchild, num - 3, 'L');
        print(N - num, ' '); //先输出n-num个' '
        cout << b->data;     //输出结点数据
        print(num, '=');     //后输出n-num个'='
        cout << c << endl;
        InDispBTree2(b->rchild, num - 3, 'R');
    }
}

//3，后序遍历输出该树:
void PostDispBTree(BTNode *b) {
    if (b) {
        PostDispBTree(b->lchild);
        PostDispBTree(b->rchild);
        cout << b->data;
    } else //空节点输出^
        cout << "^";
}

//7，输出该树的后序凹入表表示法:
void PostDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        PostDispBTree2(b->lchild, num - 3, 'L');
        PostDispBTree2(b->rchild, num - 3, 'R');
        print(N - num, ' '); //先输出n-num个' '
        cout << b->data;     //输出结点数据
        print(num, '=');     //后输出n-num个'='
        cout << c << endl;
    }
}

//4，层次遍历输出该树:
void LevelDispBTree(BTNode *b) {
    struct
    {
        BTNode *data[MaxSize];
        int front = -1, rear = -1;
    } Qu; //队列结构
    ++Qu.rear;
    Qu.data[Qu.rear] = b;
    while (Qu.front != Qu.rear) { //当队列不为空
        ++Qu.front;               //出队
        if (Qu.data[Qu.front]) {
            cout << Qu.data[Qu.front]->data;
            Qu.data[Qu.rear + 1] = Qu.data[Qu.front]->lchild; //左孩子进队
            Qu.data[Qu.rear + 2] = Qu.data[Qu.front]->rchild; //右孩子进队
            Qu.rear += 2;
        } else {
            cout << "^"; //空节点输出^
        }
    }
}

//输出二叉树
void DispReverseBTree(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispReverseBTree(b->rchild); //先输出右节点
            if (b->lchild)
                cout << ",";
            DispReverseBTree(b->lchild); //再输出左节点
            cout << ")";
        }
    }
}

//将b树左右节点逆转复制入t树
void CopyReverseBTree(BTNode *b, BTNode *&t) {
    if (b) {
        t = new BTNode;
        t->data = b->data;
        CopyReverseBTree(b->lchild, t->rchild);
        CopyReverseBTree(b->rchild, t->lchild);
        return;
    }
    t = NULL;
}

int main() {
    //实例1
    char test[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";

    //实例2
    //char test[] = "A(B(D(,G)),C(E,F))";

    char input[MaxSize];
    BTNode *tree;
    char ch;
    cout << "0，建树:" << endl;
    CreateBTree(tree, test);
    cout << "\n";
    cout << "1，先序遍历输出该树:" << endl;
    PreDispBTree(tree);
    cout << "\n\n";
    cout << "2，中序遍历输出该树:" << endl;
    InDispBTree(tree);
    cout << "\n\n";
    cout << "3，后序遍历输出该树:" << endl;
    PostDispBTree(tree);
    cout << "\n\n";
    cout << "4，层次遍历输出该树:" << endl;
    LevelDispBTree(tree);
    cout << "\n\n";
    cout << "5，输出该树的先序凹入表表示法:" << endl;
    PreDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "6，输出该树的中序凹入表表示法:" << endl;
    InDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "7，输出该树的后序凹入表表示法:" << endl;
    PostDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "7，输出该树的后序凹入表表示法:" << endl;
    PostDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "8.1，括号表示法输出该树的左右节点互换后的树:" << endl;
    DispReverseBTree(tree);
    cout << "\n\n";
    BTNode *r;
    CopyReverseBTree(tree, r);
    cout << "8.2，括号表示法输出原树左右节点互换后的树" << endl;
    DispBTree(r);
    cout << "\n\n";
    cout << "10，销毁该二叉树" << endl;
    DestroyBTree(tree);

    return 0;
}
