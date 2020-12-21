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
//初始化队列
void InitQueue(SqQueue *&p) {
    p = new SqQueue;
    p->front = p->rear = 0;
}

/*************************************/
//判断队列是否为空
int QueueEmpty(SqQueue *p) {
    return (p->front == p->rear);
}

/************************************/
//进队
int enQueue(SqQueue *&p, ElemType e) {
    if ((p->rear + 1) % MaxSize == p->front)
        return 0;
    p->rear = (p->rear + 1) % MaxSize;
    p->data[p->rear] = e;
    return 1;
}

/***********************************/
//出队一个元素，并输出该元素
int deQueue(SqQueue *&p, ElemType &e) {
    if (p->rear == p->front)
        return 0;
    p->front = (p->front + 1) % MaxSize;
    e = p->data[p->front];
    return 1;
}

/***********************************/
//输出队列的元素个数
int countQueue(SqQueue *p) {
    return ((p->rear - p->front + MaxSize) % MaxSize);
}

/***********************************/
//输出出列序列
void DispQueue(SqQueue *&p) {
    if (p->rear == p->front)
        cout << "队列为空!" << endl;
    while (p->rear != p->front) {
        p->front = (p->front + 1) % MaxSize;
        cout << p->data[p->front] << "  ";
    }
    cout << endl;
}

/***********************************/
//释放序列
void DestoryQueue(SqQueue *&p) {
    delete p;
}

/***********************************/
//主函数
void main() {
    SqQueue *p;
    cout << "1.初始化队列" << endl;
    InitQueue(p);

    cout << "2.队列：";
    if (QueueEmpty(p))
        cout << "为空!" << endl;
    else
        cout << "不为空!" << endl;

    char a[3] = {'a', 'b', 'c'};
    cout << "3.依次进队元素a,b,c" << endl;
    for (int i = 0; i < 3; i++) {
        if (enQueue(p, a[i]))
            cout << "  元素" << a[i] << "进队成功!" << endl;
        else
            cout << "  元素" << a[i] << "进队失败!" << endl;
    }

    ElemType e;
    cout << "4.出队一个元素，该元素为：";
    if (!deQueue(p, e))
        cout << "队列为空，出队失败!" << endl;
    else
        cout << e << endl;

    cout << "5.队列的元素个数：" << countQueue(p) << endl;

    char b[3] = {'d', 'e', 'f'};
    cout << "6.依次进队:" << endl;
    for (int j = 0; j < 3; j++) {
        if (enQueue(p, b[j]) == 1)
            cout << "  元素" << b[j] << "进队成功!" << endl;
        else
            cout << "  元素" << b[j] << "进队失败!" << endl;
    }

    cout << "7.队列的元素个数：" << countQueue(p) << endl;

    cout << "8.出队序列为：" << endl;
    while (!QueueEmpty(p))
        if (deQueue(p, e))
            cout << "出队的元素为:" << e << endl;

    cout << "9.释放队列" << endl;
    DestoryQueue(p);
}