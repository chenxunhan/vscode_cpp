//��ջ��ʵ��
//��ѷ�
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
    //��1����ʼ��ջs
    cout << "��1����ʼ��ջs..." << endl;
    cout << "\n";
    s.Init();
    //��2���ж�ջs�Ƿ�Ϊ��
    cout << "��2���ж�ջs�Ƿ�Ϊ�գ�";
    if (s.isEmpty())
        cout << "ջΪ��" << endl;
    else
        cout << "ջ��Ϊ��" << endl;
    cout << "\n";
    //��3�����ν�ջԪ��a��b��c��d��e
    ElemType a[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << "��3�����ν�ջԪ��a��b��c��d��e" << endl;
    for (int i = 0; i < 5; ++i) {
        s.Push(a[i]);
    }
    cout << "\n";
    //��4���ж�ջs�Ƿ�Ϊ��
    cout << "��4���ж�ջs�Ƿ�Ϊ�գ�";
    if (s.isEmpty())
        cout << "ջΪ��" << endl;
    else
        cout << "ջ��Ϊ��" << endl;
    cout << "\n";
    //��5�������ջ����
    ElemType tmp;
    cout << "��5�������ջ����:" << endl;
    while (s.isEmpty() == false) {
        s.Pop(tmp);
        cout << tmp << "\t";
    }
    cout << endl;
    cout << "\n";
    //��6���ж�ջs�Ƿ�Ϊ��
    cout << "��6���ж�ջs�Ƿ�Ϊ�գ�";
    if (s.isEmpty())
        cout << "ջΪ��" << endl;
    else
        cout << "ջ��Ϊ��" << endl;
    cout << "\n";
    //��7���ͷ�ջ
    cout << "��7���ͷ�ջ...";
    s.Destory();
    return 0;
}