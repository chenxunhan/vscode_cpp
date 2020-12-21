//cxh
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 200
typedef int ElemType;

/********************************************************/
//���д���
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

/********************************************************/
//˳��ջ����
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
/*��ʼ��ջs*/
void InitStack(SqStack *&s) {
    s = new SqStack;
    s->top = -1;
}
/*����ջs*/
void DestroyStack(SqStack *&s) {
    delete s;
}
/*��ջs�ĳ���*/
int StackLength(SqStack *s) {
    return (s->top + 1);
}
/*�ж�ջs�Ƿ�Ϊ��*/
int StackEmpty(SqStack *s) {
    return (s->top == -1);
}
/*��ջ*/
int Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
/*��ջ*/
int Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
/*ȡջ��Ԫ��*/
int GetTop(SqStack *s, ElemType &e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}
/*��ջ����ջ�����Ԫ��*/
void DispStack(SqStack *s) {
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%c", s->data[i]);
    printf("\n");
}

/*�����������ת���������*/
void PrintNum(int num) {
    if (num > 35) {
        cout << (char) (num - 36 + 'a');
        return;
    }
    if (num > 9) {
        cout << (char) (num - 10 + 'A');
        return;
    }
    cout << num;
}

/********************************************************/
//����ת������
int main() {
    int bool_continue = 1;
    int int_tmp;    //������ʱ�洢���������
    double dbl_tmp; //������ʱ�洢�����С��

    do {            //��û��ָ���˳�����ǰ�����������
        double num; //���н���ת��������
        cout << "������׼�����н���ת��������:" << endl;
        cin >> num;

        int int_part;              //���н���ת�����ֵ���������
        double dbl_part;           //���н���ת�����ֵ�С������
        int_part = (int) num;      //�洢����ת�����ֵ���������
        dbl_part = num - int_part; //�洢����ת�����ֵ�С������

        int sofn; //ת���Ľ���system of numeration
        cout << "��������Ҫ����ת���Ľ���[2,62],����0����:" << endl;
        while (cin >> sofn) {
            if (sofn == 0) //�������0��ת�����ֽ���������
                break;

            if (sofn >= 2 && sofn <= 62) {
                //��������ת����˳��ջʵ��
                SqStack *int_stack;                  //������ջ�����ڴ洢ת�������ֵ���������
                InitStack(int_stack);                //��ʼ��˳��ջ
                int_tmp = int_part;                  //��׼��ת�����ֵ��������ִ洢��ɲ���������
                while (int_tmp) {                    //ֻҪ�ɲ���������Ϊ�㣬����
                    Push(int_stack, int_tmp % sofn); //�ɲ������������ȡ������ջ
                    int_tmp /= sofn;                 //�ɲ����������Խ���
                }
                //�������ֽ�ջ����ʱջΪ�գ�Ӧ��ջ����0
                if (StackEmpty(int_stack)) {
                    Push(int_stack, 0);
                }

                //С������ת��������ʵ��
                SqQueue *dbl_queue;                    //�����¶ӣ����ڴ洢ת�������ֵ�С������
                InitQueue(dbl_queue);                  //��ʼ������
                dbl_tmp = dbl_part;                    //��׼��ת�����ֵ�С�����ִ洢��ɲ���������
                while (dbl_tmp) {                      //ֻҪ�ɲ���������Ϊ0������
                    dbl_tmp *= sofn;                   //�ɲ������ֳ��Խ���
                    enQueue(dbl_queue, (int) dbl_tmp); //�ɲ������ֵ��������ֽ���
                    dbl_tmp -= (int) dbl_tmp;          //�ɲ������ּ�ȥ������������֣���������С������
                }
                //�������ֽ��ӣ���ʱ��Ϊ�գ�Ӧ��������0
                if (QueueEmpty(dbl_queue)) {
                    enQueue(dbl_queue, 0);
                }

                //����������
                cout << num << "��" << sofn << "����Ϊ:";
                //�����������
                while (!StackEmpty(int_stack)) { //�����ջ���У��������֣�
                    Pop(int_stack, int_tmp);
                    PrintNum(int_tmp); //�����������ת���������
                }
                //���С����
                cout << ".";
                //���С������
                while (!QueueEmpty(dbl_queue)) { //����������У�С�����֣�
                    deQueue(dbl_queue, int_tmp);
                    PrintNum(int_tmp); //�����������ת���������
                }
                cout << endl;

                //������������˳��ջ��С�����ֶ���
                DestroyStack(int_stack);
                DestoryQueue(dbl_queue);
                continue;
            }
            //����������ּȲ���0(����),Ҳ����[2,62](�Ϸ�����),��������Ϸ���Ϣ
            cout << "������Ʋ��Ϸ�������������" << endl;
        }
        cout << "�Ƿ��˳�����(�˳�����0,��������1)";
        cin >> bool_continue;
    } while (bool_continue);
    return 0;
}