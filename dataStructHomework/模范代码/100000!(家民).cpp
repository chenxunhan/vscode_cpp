#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode *next;
} LinkList;

//  1. ��ʼ��������
void InitList(LinkList *&L) {
    L = new LinkList;
    L->next = NULL;
}

//  2. ͨ��βָ�룬��β�ڵ�����Ԫ�أ����ڽ�λʱ����λ���ֲ��뵽�������
//  ����������ָ�룬ͬ���޸��������е�βָ���ֵ�� ����λ��һ������x���뵽�������
void InsertRear(LinkList *&R, int x) {
    LinkList *newNode = new LinkList;
    newNode->data = x;
    R->next = newNode;
    newNode->next = NULL;
    R = newNode; // βָ��ָ���½��Ľڵ�
}

//  3. �����ֳ��Խڵ��ÿһ�����֣��õ�����������ͬʱ��λ
void MultList(LinkList *&L, LinkList *&R, int x) {
    LinkList *p = L->next;      // �ӵ�һ���洢���ֵĽڵ㿪ʼ
    int up = 0, sum;            // �洢��λ�ı���up��ʼֵΪ0
    while (p) {                 // ������ǰ��������˸ı䵱ǰλ�õ�ֵ�����õ���λ
        sum = p->data * x + up; // �ȵõ���˲����Ͻ�λ�Ľ��
        p->data = sum % 10;     // ���µ�ǰ�ڵ�dataֵ
        up = sum / 10;          // ���½�λ����
        p = p->next;            // �ƶ�����һ���ڵ�
    }

    //  ֻ�е����ֳ˱����е�ǰ�ڵ�󣬽�λ�����Բ�Ϊ0���Ŵ�������λ�������˸ı�
    //  �����ʱ��λ�Բ�Ϊ0�Ļ�������λ�����ֵ�������������
    while (up) {
        InsertRear(R, up % 10);
        up /= 10;
    }
}

//  4. ��ת������
void ReveList(LinkList *&L) {
    //  ��������ʼ��һ���±�ͷ
    LinkList *newHead;
    InitList(newHead);

    //  �ӵ�һ����ֵ�Ľڵ㿪ʼ���������ν��з�ת��p����ǰ���ڲ����Ľڵ�
    LinkList *p = L->next;

    //  ��ָ��δ��������β��ʱ�����εõ���Ҫ�����Ľڵ��ַ������������ͷ�巨�ķ���������Ҫ�����Ľڵ����β��뵽�µı�ͷ
    while (p) {
        L->next = p->next;       // ��ԭ�����ͷ�ڵ��nextָ��ָ������һ���ڵ㣬��ʱpָ���������Ǹ��ڵ㣬����Ҫ�����Ľڵ�
        p->next = newHead->next; // ����Ҫ�����Ľڵ��nextָ�룬ָ���±�ͷ����һ���ڵ�
        newHead->next = p;       // �ñ�ͷ��nextָ��ָ�����ڲ����Ľڵ�
        p = L->next;             // pָ����һ����Ҫ�����Ľڵ�
    }

    delete L;    // �ͷ�ͷָ��ָ��Ŀռ�
    L = newHead; // ��ͷָ��ָ���µ�ͷ�ڵ�
}

//  5. ���������
void DispList(LinkList *L) {
    LinkList *p = L->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
}

//  6. �õ�������
int ListLength(LinkList *L) {
    LinkList *p = L->next;
    int i = 0;
    while (p) {
        ++i;
        p = p->next;
    }
    return i;
}

//  7. ���ٵ�����
void DestroyList(LinkList *&L) {
    LinkList *p = L->next;
    while (p) {
        L->next = L->next->next;
        delete p;
        p = L->next;
    }
    delete L;
}

int main() {
    //  1. ��������������βָ�룬��βָ��ָ���ͷ������������洢���������
    LinkList *L1;
    InitList(L1);
    LinkList *Rear = L1;

    //  2. ������1���뵽�������
    InsertRear(Rear, 1);

    //  3. ����n
    int n;
    cout << "��������Ҫ��׳˵���: ";
    cin >> n;
    cout << endl;

    //  4. 1~n�����뵥�����ϵĽڵ������ˡ���λ��
    for (int i = 1; i <= n; ++i) {
        MultList(L1, Rear, i);
    }

    //  5. ��ת������
    ReveList(L1);

    //  6. ������λ�����Լ�������
    cout << "�ý������" << ListLength(L1) << "λ" << endl
         << endl;

    cout << "���Ϊ: " << endl;
    DispList(L1);

    //  7. �ͷŵ�����
    DestroyList(L1);

    return 0;
}
