//约瑟夫环
//陈逊瀚
#include <iostream>
using namespace std;

typedef int ElemType;

class LinkNode {
  public:
    ElemType data;
    LinkNode *next;
};

class LinkList_class {
  public:
    LinkNode *HeadNode;
    int length_1;
    void Init() {
        HeadNode = new LinkNode;
        HeadNode->next = HeadNode;
        length_1 = 0;
    }
    void CreatR(ElemType a[], int n) {
        Init();
        LinkNode *s, *r;
        r = HeadNode;
        for (int i = 0; i < n; ++i) {
            s = new LinkNode;
            s->data = a[i];
            r->next = s;
            r = s;
        }
        r->next = HeadNode;
        length_1 = n;
    }
    void Disply() {
        LinkNode *p = HeadNode->next;
        while (p != HeadNode) {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }
    int Length_n() {
        LinkNode *p = HeadNode;
        int n = 0;
        while (p->next != HeadNode) {
            ++n;
            p = p->next;
        }
        return n;
    }
    bool isEmpty() {
        return HeadNode->next == HeadNode;
    }
    bool GetElem_i(int i, ElemType &e) { //跳过头结点，再循环
        if (i <= 0)
            return false;
        LinkNode *p = HeadNode;
        int j = 0;
        while (j < i) {
            ++j;
            p = p->next;
            if (p == HeadNode) //跳过头结点
                p = p->next;
        }
        if (p == HeadNode) //链表只有一个头结点
            return false;
        e = p->data;
        ++length_1;
        return true;
    }
    bool GetElem_p(LinkNode *p, ElemType &e) { //指针法取元素
        if (p == HeadNode)
            return false;
        e = p->data;
        return true;
    }
    int LocateElem(ElemType e) {
        int i = 1;
        LinkNode *p = HeadNode->next;
        while (p != HeadNode && p->data != e) {
            ++i;
            p = p->next;
        }
        if (p == HeadNode)
            return 0;
        return i;
    }
    bool Insert_i(int i, ElemType e) {
        if (i <= 0)
            return false;
        LinkNode *p = HeadNode;
        int j = 0;
        while (j < i - 1) {
            ++j;
            p = p->next;
            if (p == HeadNode) //跳过头结点
                p = p->next;
        }
        LinkNode *s;
        s = new LinkNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
        ++length_1;
        return true;
    }
    bool Insert_pre(LinkNode *pre, ElemType e) { //指针法插入元素，插入元素在pre指针指向节点的下个节点
        LinkNode *p = pre->next;
        if (p == HeadNode)
            return false;
        LinkNode *s;
        s = new LinkNode;
        s->data = e;
        s->next = p;
        pre->next = s;
        ++length_1;
        return true;
    }

    bool DeleteElem_pre(LinkNode *pre, ElemType e) { //指针法删除元素，删除元素在pre指针指向节点的下个节点
        LinkNode *p = pre->next;
        if (p == HeadNode)
            return false;
        e = p->data;
        pre->next = p->next;
        delete p;
        --length_1;
        return true;
    }
    void Destroy() {
        LinkNode *pre = HeadNode->next;
        HeadNode->next = NULL; //把循环链表变成单链表
        LinkNode *p = pre->next;
        while (p != NULL) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
        length_1 = 0;
    }
};

int main() {
    int n, m; //n人数，m间隔号
    LinkList_class H;
    ElemType e;
    while (cin >> n >> m) {
        H.Init();
        for (int i = 1; i <= n; ++i) {
            H.Insert_i(i, i);
        }
        while (H.isEmpty() == false) {
            LinkNode *out = H.HeadNode;
            int i = 1;
            while (1) {
                if (i == m - 1) {
                }
            }
            for (int i = 1; i <= m; ++i) {
                out = out->next;
                if (out = H.HeadNode) {
                    out = out->next;
                }
            }
        }
        H.Destroy();
    }
    return 0;
}