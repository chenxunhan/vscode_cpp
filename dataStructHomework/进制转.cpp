//cxh
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 200
typedef int ElemType;

/********************************************************/
//队列代码
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

/********************************************************/
//顺序栈代码
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
/*初始化栈s*/
void InitStack(SqStack *&s) {
    s = new SqStack;
    s->top = -1;
}
/*销毁栈s*/
void DestroyStack(SqStack *&s) {
    delete s;
}
/*求栈s的长度*/
int StackLength(SqStack *s) {
    return (s->top + 1);
}
/*判断栈s是否为空*/
int StackEmpty(SqStack *s) {
    return (s->top == -1);
}
/*进栈*/
int Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
/*出栈*/
int Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
/*取栈顶元素*/
int GetTop(SqStack *s, ElemType &e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}
/*从栈顶到栈底输出元素*/
void DispStack(SqStack *s) {
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%c", s->data[i]);
    printf("\n");
}

/*输出经过进制转换后的数字*/
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
//进制转换代码
int main() {
    int bool_continue = 1;
    int int_tmp;    //用于临时存储输出的整数
    double dbl_tmp; //用于临时存储输出的小数

    do {            //在没有指定退出程序前程序持续运行
        double num; //进行进制转换的数字
        cout << "请输入准备进行进制转换的数字:" << endl;
        cin >> num;

        int int_part;              //进行进制转换数字的整数部分
        double dbl_part;           //进行进制转换数字的小数部分
        int_part = (int) num;      //存储进制转换数字的整数部分
        dbl_part = num - int_part; //存储进制转换数字的小数部分

        int sofn; //转换的进制system of numeration
        cout << "请输入需要进行转换的进制[2,62],输入0重置:" << endl;
        while (cin >> sofn) {
            if (sofn == 0) //如果输入0，转换数字将进行重置
                break;

            if (sofn >= 2 && sofn <= 62) {
                //整数部分转换，顺序栈实现
                SqStack *int_stack;                  //声明新栈，用于存储转换后数字的整数部分
                InitStack(int_stack);                //初始化顺序栈
                int_tmp = int_part;                  //将准备转换数字的整数部分存储入可操作变量中
                while (int_tmp) {                    //只要可操作变量不为零，继续
                    Push(int_stack, int_tmp % sofn); //可操作变量与进制取余数进栈
                    int_tmp /= sofn;                 //可操作变量除以进制
                }
                //若无数字进栈，此时栈为空，应进栈数字0
                if (StackEmpty(int_stack)) {
                    Push(int_stack, 0);
                }

                //小数部分转换，队列实现
                SqQueue *dbl_queue;                    //声明新队，用于存储转换后数字的小数部分
                InitQueue(dbl_queue);                  //初始化队列
                dbl_tmp = dbl_part;                    //将准备转换数字的小数部分存储入可操作变量中
                while (dbl_tmp) {                      //只要可操作变量不为0，继续
                    dbl_tmp *= sofn;                   //可操作数字乘以进制
                    enQueue(dbl_queue, (int) dbl_tmp); //可操作数字的整数部分进队
                    dbl_tmp -= (int) dbl_tmp;          //可操作数字减去自身的整数部分，仅仅保留小数部分
                }
                //若无数字进队，此时队为空，应进队数字0
                if (QueueEmpty(dbl_queue)) {
                    enQueue(dbl_queue, 0);
                }

                //输出处理程序
                cout << num << "的" << sofn << "进制为:";
                //输出整数部分
                while (!StackEmpty(int_stack)) { //输出出栈序列（整数部分）
                    Pop(int_stack, int_tmp);
                    PrintNum(int_tmp); //输出经过进制转换后的数字
                }
                //输出小数点
                cout << ".";
                //输出小数部分
                while (!QueueEmpty(dbl_queue)) { //输出出队序列（小数部分）
                    deQueue(dbl_queue, int_tmp);
                    PrintNum(int_tmp); //输出经过进制转换后的数字
                }
                cout << endl;

                //销毁整数部分顺序栈、小数部分队列
                DestroyStack(int_stack);
                DestoryQueue(dbl_queue);
                continue;
            }
            //若输入的数字既不是0(重置),也不是[2,62](合法进制),则输出不合法信息
            cout << "输入进制不合法，请重新输入" << endl;
        }
        cout << "是否退出程序？(退出输入0,继续输入1)";
        cin >> bool_continue;
    } while (bool_continue);
    return 0;
}