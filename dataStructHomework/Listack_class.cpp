//链栈类实现
//陈逊瀚
#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

class LinkNode {
  public:
    ElemType data;
    LinkNode *next;
};

class Listack_class {
  public:
    LinkNode *TopNode;
    void Init() {
        TopNode = new LinkNode;
        TopNode->next = NULL;
    }
    bool isEmpty() {
        return TopNode->next == NULL;
    }
    void Push(ElemType e) {
        LinkNode *s = new LinkNode;
        s->data = e;
        s->next = TopNode->next;
        TopNode->next = s;
    }
    bool Pop(ElemType &e) {
        if (TopNode->next == NULL) {
            return false;
        }
        e = TopNode->next->data;
        LinkNode *s = TopNode->next;
        TopNode->next = s->next;
        delete s;
        return true;
    }
    void Display() {
        LinkNode *s = TopNode;
        while (s->next != NULL) {
            cout << s->next->data << "\t";
            s = s->next;
        }
    }
    void Destory() {
        LinkNode *pre = TopNode, *p = TopNode->next;
        while (p != NULL) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
};

int main() {
    Listack_class s;
    //（1）初始化栈s
    cout << "（1）初始化栈s..." << endl;
    cout << "\n";
    s.Init();
    //（2）判断栈s是否为空
    cout << "（2）判断栈s是否为空：";
    if (s.isEmpty())
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
    cout << "\n";
    //（3）依次进栈元素a、b、c、d、e
    ElemType a[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << "（3）依次进栈元素a、b、c、d、e" << endl;
    for (int i = 0; i < 5; ++i) {
        s.Push(a[i]);
    }
    cout << "\n";
    //（4）判断栈s是否为空
    cout << "（4）判断栈s是否为空：";
    if (s.isEmpty())
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
    cout << "\n";
    //（5）输出出栈序列
    ElemType tmp;
    cout << "（5）输出出栈序列:" << endl;
    while (s.isEmpty() == false) {
        s.Pop(tmp);
        cout << tmp << "\t";
    }
    cout << endl;
    cout << "\n";
    //（6）判断栈s是否为空
    cout << "（6）判断栈s是否为空：";
    if (s.isEmpty())
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
    cout << "\n";
    //（7）释放栈
    cout << "（7）释放栈...";
    s.Destory();
    return 0;
}