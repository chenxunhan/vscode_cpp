//sqqueue.cpp
//cxh
#include <bits/stdc++.h>
using namespace std;

//�������MAXSIZEΪ5
const int MAXSIZE = 5;

//����charΪ����Ԫ������
typedef char Elemtype;

//��������࣬ʵ�ֶ��нṹ�Ĺ���
class Queue {
  public:
    int data[MAXSIZE]; //����������
    int front, rear;   //���е�ͷβ����Ӧ�����������λ��
};

//������������࣬�����еĳ�ʼ��ָ��q�ͻ��������װ����
class Queue_Class {
  public:
    Queue *q;     //���еĳ�ʼ��ָ��
    void Init() { //��ʼ������
        q = new Queue;
        q->front = q->rear = 0;
    }
    void Destory() { //���ٶ���
        delete q;
    }
    bool isEmpty() { //�ж϶����Ƿ�Ϊ��
        return q->front == q->rear;
    }
    bool Enter(Elemtype e) {                       //��Ԫ��e����
        if ((q->rear + 1) % MAXSIZE == q->front) { //���������ؼ�
            return false;
        }
        q->rear = (q->rear + 1) % MAXSIZE;
        q->data[q->rear] = e;
        return true;
    }
    bool Delete(Elemtype &e) {     //���ӣ��ҽ�����Ԫ�ظ�ֵ��e
        if (q->front == q->rear) { //���ӿշ��ؼ�
            return false;
        }
        q->front = (q->front + 1) % MAXSIZE;
        e = q->data[q->front];
        return true;
    }
};

//ʵ���⣨3��ʵ�ֻ��ζ��еĸ��ֻ���������㷨
int main() {
    //��������Ҫ��Ԫ������
    Elemtype elemarr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    //����δ��ʼ���Ķ���q
    Queue_Class q;

    //�������ڴ洢����Ԫ�ص�e
    Elemtype e;

    //��1����ʼ������q
    cout << "��1����ʼ������q\n\n";
    q.Init();

    //��2���ж϶���q�Ƿ�ǿ�
    cout << "��2���ж϶���q�Ƿ�ǿ�:\n";
    if (q.isEmpty()) {
        cout << "����Ϊ��\n\n";
    } else {
        cout << "���в�Ϊ��\n\n";
    }

    //��3�����ν���Ԫ��a��b��c
    cout << "��3�����ν���Ԫ��a��b��c\n";
    for (int i = 0; i < 3; ++i) {
        if (!q.Enter(elemarr[i])) { //������ʧ�����ʧ����Ϣ���ɹ��������Ϣ
            cout << "��������" << elemarr[i] << " �޷�����\n";
        }
    }
    cout << "\n";

    //��4������һ��Ԫ�أ������Ԫ��
    cout << "��4������һ��Ԫ�أ������Ԫ��\n";
    if (q.Delete(e)) {
        cout << "����Ԫ���ǣ�" << e << endl;
    } else {
        cout << "���пգ��޷�����\n"; //����ʧ����Ϣ
    }
    cout << "\n";

    //��5�����ν���Ԫ��d��e��f
    cout << "��5�����ν���Ԫ��d��e��f\n";
    for (int i = 3; i < 6; ++i) {
        if (!q.Enter(elemarr[i])) { //������ʧ�����ʧ����Ϣ���ɹ��������Ϣ
            cout << "��������" << elemarr[i] << " �޷�����\n";
        }
    }
    cout << "\n";

    //��6�������������
    cout << "��6�������������:\n";
    while (!q.isEmpty()) { //����ֱ������Ϊ��
        q.Delete(e);
        cout << e << " ";
    }
    cout << "\n\n";

    //��7���ͷŶ���
    cout << "��7���ͷŶ���\n";
    q.Destory();
    return 0;
}
