//sqqueue.cpp
//cxh
#include <bits/stdc++.h>
using namespace std;

//定义队列MAXSIZE为5
const int MAXSIZE = 5;

//定义char为队列元素类型
typedef char Elemtype;

//定义队列类，实现队列结构的功能
class Queue {
  public:
    int data[MAXSIZE]; //队列数据域
    int front, rear;   //队列的头尾，对应数据域的物理位序
};

//定义队列运算类，将队列的初始化指针q和基本运算封装在内
class Queue_Class {
  public:
    Queue *q;     //队列的初始化指针
    void Init() { //初始化队列
        q = new Queue;
        q->front = q->rear = 0;
    }
    void Destory() { //销毁队列
        delete q;
    }
    bool isEmpty() { //判断队列是否为空
        return q->front == q->rear;
    }
    bool Enter(Elemtype e) {                       //将元素e进队
        if ((q->rear + 1) % MAXSIZE == q->front) { //若队满返回假
            return false;
        }
        q->rear = (q->rear + 1) % MAXSIZE;
        q->data[q->rear] = e;
        return true;
    }
    bool Delete(Elemtype &e) {     //出队，且将出队元素赋值给e
        if (q->front == q->rear) { //若队空返回假
            return false;
        }
        q->front = (q->front + 1) % MAXSIZE;
        e = q->data[q->front];
        return true;
    }
};

//实验题（3）实现环形队列的各种基本运算的算法
int main() {
    //定义题意要求元素数组
    Elemtype elemarr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    //定义未初始化的队列q
    Queue_Class q;

    //定义用于存储出队元素的e
    Elemtype e;

    //（1）初始化队列q
    cout << "（1）初始化队列q\n\n";
    q.Init();

    //（2）判断队列q是否非空
    cout << "（2）判断队列q是否非空:\n";
    if (q.isEmpty()) {
        cout << "队列为空\n\n";
    } else {
        cout << "队列不为空\n\n";
    }

    //（3）依次进队元素a、b、c
    cout << "（3）依次进队元素a、b、c\n";
    for (int i = 0; i < 3; ++i) {
        if (!q.Enter(elemarr[i])) { //若进队失败输出失败信息，成功不输出信息
            cout << "队列满，" << elemarr[i] << " 无法进队\n";
        }
    }
    cout << "\n";

    //（4）出队一个元素，输出该元素
    cout << "（4）出队一个元素，输出该元素\n";
    if (q.Delete(e)) {
        cout << "出队元素是：" << e << endl;
    } else {
        cout << "队列空，无法出队\n"; //出队失败信息
    }
    cout << "\n";

    //（5）依次进队元素d、e、f
    cout << "（5）依次进队元素d、e、f\n";
    for (int i = 3; i < 6; ++i) {
        if (!q.Enter(elemarr[i])) { //若进队失败输出失败信息，成功不输出信息
            cout << "队列满，" << elemarr[i] << " 无法进队\n";
        }
    }
    cout << "\n";

    //（6）输出出队序列
    cout << "（6）输出出队序列:\n";
    while (!q.isEmpty()) { //出队直到队列为空
        q.Delete(e);
        cout << e << " ";
    }
    cout << "\n\n";

    //（7）释放队列
    cout << "（7）释放队列\n";
    q.Destory();
    return 0;
}
