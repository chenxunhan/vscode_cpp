//Ԫ�����Ͷ���Ϊchar
typedef char ElemType;
#define MaxSize 100
#define N 30       //�����ʾ�����ڵ�����'='��
#include "btree.h" //�������������ݽṹ�ͻ�������

//���num���ַ�c
void print(int num, char c) {
    while (num--)
        cout << c;
}

//1����������������:
void PreDispBTree(BTNode *b) {
    if (b) {
        cout << b->data;
        PreDispBTree(b->lchild);
        PreDispBTree(b->rchild);
    } else //�սڵ����^
        cout << "^";
}

//5�������������������ʾ��:
void PreDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        print(N - num, ' '); //�����n-num��' '
        cout << b->data;     //����������
        print(num, '=');     //�����n-num��'='
        cout << c << endl;
        PreDispBTree2(b->lchild, num - 3, 'L');
        PreDispBTree2(b->rchild, num - 3, 'R');
    }
}

//2����������������:
void InDispBTree(BTNode *b) {
    if (b) {
        InDispBTree(b->lchild);
        cout << b->data;
        InDispBTree(b->rchild);
    } else //�սڵ����^
        cout << "^";
}

//6�������������������ʾ��:
void InDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        InDispBTree2(b->lchild, num - 3, 'L');
        print(N - num, ' '); //�����n-num��' '
        cout << b->data;     //����������
        print(num, '=');     //�����n-num��'='
        cout << c << endl;
        InDispBTree2(b->rchild, num - 3, 'R');
    }
}

//3����������������:
void PostDispBTree(BTNode *b) {
    if (b) {
        PostDispBTree(b->lchild);
        PostDispBTree(b->rchild);
        cout << b->data;
    } else //�սڵ����^
        cout << "^";
}

//7����������ĺ�������ʾ��:
void PostDispBTree2(BTNode *b, int num, char c) {
    if (b) {
        PostDispBTree2(b->lchild, num - 3, 'L');
        PostDispBTree2(b->rchild, num - 3, 'R');
        print(N - num, ' '); //�����n-num��' '
        cout << b->data;     //����������
        print(num, '=');     //�����n-num��'='
        cout << c << endl;
    }
}

//4����α����������:
void LevelDispBTree(BTNode *b) {
    struct
    {
        BTNode *data[MaxSize];
        int front = -1, rear = -1;
    } Qu; //���нṹ
    ++Qu.rear;
    Qu.data[Qu.rear] = b;
    while (Qu.front != Qu.rear) { //�����в�Ϊ��
        ++Qu.front;               //����
        if (Qu.data[Qu.front]) {
            cout << Qu.data[Qu.front]->data;
            Qu.data[Qu.rear + 1] = Qu.data[Qu.front]->lchild; //���ӽ���
            Qu.data[Qu.rear + 2] = Qu.data[Qu.front]->rchild; //�Һ��ӽ���
            Qu.rear += 2;
        } else {
            cout << "^"; //�սڵ����^
        }
    }
}

//���������
void DispReverseBTree(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << "(";
            DispReverseBTree(b->rchild); //������ҽڵ�
            if (b->lchild)
                cout << ",";
            DispReverseBTree(b->lchild); //�������ڵ�
            cout << ")";
        }
    }
}

//��b�����ҽڵ���ת������t��
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
    //ʵ��1
    char test[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";

    //ʵ��2
    //char test[] = "A(B(D(,G)),C(E,F))";

    char input[MaxSize];
    BTNode *tree;
    char ch;
    cout << "0������:" << endl;
    CreateBTree(tree, test);
    cout << "\n";
    cout << "1����������������:" << endl;
    PreDispBTree(tree);
    cout << "\n\n";
    cout << "2����������������:" << endl;
    InDispBTree(tree);
    cout << "\n\n";
    cout << "3����������������:" << endl;
    PostDispBTree(tree);
    cout << "\n\n";
    cout << "4����α����������:" << endl;
    LevelDispBTree(tree);
    cout << "\n\n";
    cout << "5�������������������ʾ��:" << endl;
    PreDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "6�������������������ʾ��:" << endl;
    InDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "7����������ĺ�������ʾ��:" << endl;
    PostDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "7����������ĺ�������ʾ��:" << endl;
    PostDispBTree2(tree, N, 'B');
    cout << "\n\n";
    cout << "8.1�����ű�ʾ��������������ҽڵ㻥�������:" << endl;
    DispReverseBTree(tree);
    cout << "\n\n";
    BTNode *r;
    CopyReverseBTree(tree, r);
    cout << "8.2�����ű�ʾ�����ԭ�����ҽڵ㻥�������" << endl;
    DispBTree(r);
    cout << "\n\n";
    cout << "10�����ٸö�����" << endl;
    DestroyBTree(tree);

    return 0;
}
