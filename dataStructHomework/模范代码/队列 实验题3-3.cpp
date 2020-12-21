#include <iostream>
using namespace std;
#define MaxSize 5
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

/*************************************/
//��ʼ������
void InitQueue(SqQueue *&p) {
    p = new SqQueue;
    p->front = p->rear = 0;
}

/*************************************/
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(SqQueue *p) {
    return (p->front == p->rear);
}

/************************************/
//����
int enQueue(SqQueue *&p, ElemType e) {
    if ((p->rear + 1) % MaxSize == p->front)
        return 0;
    p->rear = (p->rear + 1) % MaxSize;
    p->data[p->rear] = e;
    return 1;
}

/***********************************/
//����һ��Ԫ�أ��������Ԫ��
int deQueue(SqQueue *&p, ElemType &e) {
    if (p->rear == p->front)
        return 0;
    p->front = (p->front + 1) % MaxSize;
    e = p->data[p->front];
    return 1;
}

/***********************************/
//������е�Ԫ�ظ���
int countQueue(SqQueue *p) {
    return ((p->rear - p->front + MaxSize) % MaxSize);
}

/***********************************/
//�����������
void DispQueue(SqQueue *&p) {
    if (p->rear == p->front)
        cout << "����Ϊ��!" << endl;
    while (p->rear != p->front) {
        p->front = (p->front + 1) % MaxSize;
        cout << p->data[p->front] << "  ";
    }
    cout << endl;
}

/***********************************/
//�ͷ�����
void DestoryQueue(SqQueue *&p) {
    delete p;
}

/***********************************/
//������
void main() {
    SqQueue *p;
    cout << "1.��ʼ������" << endl;
    InitQueue(p);

    cout << "2.���У�";
    if (QueueEmpty(p))
        cout << "Ϊ��!" << endl;
    else
        cout << "��Ϊ��!" << endl;

    char a[3] = {'a', 'b', 'c'};
    cout << "3.���ν���Ԫ��a,b,c" << endl;
    for (int i = 0; i < 3; i++) {
        if (enQueue(p, a[i]))
            cout << "  Ԫ��" << a[i] << "���ӳɹ�!" << endl;
        else
            cout << "  Ԫ��" << a[i] << "����ʧ��!" << endl;
    }

    ElemType e;
    cout << "4.����һ��Ԫ�أ���Ԫ��Ϊ��";
    if (!deQueue(p, e))
        cout << "����Ϊ�գ�����ʧ��!" << endl;
    else
        cout << e << endl;

    cout << "5.���е�Ԫ�ظ�����" << countQueue(p) << endl;

    char b[3] = {'d', 'e', 'f'};
    cout << "6.���ν���:" << endl;
    for (int j = 0; j < 3; j++) {
        if (enQueue(p, b[j]) == 1)
            cout << "  Ԫ��" << b[j] << "���ӳɹ�!" << endl;
        else
            cout << "  Ԫ��" << b[j] << "����ʧ��!" << endl;
    }

    cout << "7.���е�Ԫ�ظ�����" << countQueue(p) << endl;

    cout << "8.��������Ϊ��" << endl;
    while (!QueueEmpty(p))
        if (deQueue(p, e))
            cout << "���ӵ�Ԫ��Ϊ:" << e << endl;

    cout << "9.�ͷŶ���" << endl;
    DestoryQueue(p);
}