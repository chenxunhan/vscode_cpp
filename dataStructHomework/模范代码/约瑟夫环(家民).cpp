#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    LNode *next;
} LinkNode;

// 1. 初始化头节点
void InitNode(LinkNode *&L) {
    L = new LinkNode;
    L->next = L;
}

// 2. 用尾插法创建循环单链表 同时改变实参中的尾指针
void CreateListByRear(LinkNode *&L, LinkNode *&r, ElemType arr[], int n) {
    r = L;            // 尾指针并指向头节点
    L->data = arr[0]; // 头节点的data赋值

    for (int i = 1; i < n; ++i) { // 新建节点并插入数据
        LinkNode *s = new LinkNode;
        s->data = arr[i];
        r->next = s;
        r = s;
    }
    r->next = L; // 闭圈
}

// 3.输出出圈顺序
// count -> 数到几就出圈      move ->从第i个开始, 就移动i-1个节点
// 使用引用型指针实时改变实参中的头尾指针, 使之符合逻辑
void out(LinkNode *&p, LinkNode *&pre, int count, int move) {
    int i = 1;

    //  移动节点，到开始的那个数
    while (--move) {
        p = p->next;
        pre = pre->next;
    }

    //  当圈不为1个人时，循环出圈
    while (p->next != p) {

        if (i == count) { // 数到某个数，就出圈
            i = 1;
            cout << p->data << " ";

            pre->next = p->next; // 删除出圈节点
            delete p;
            p = pre->next;

        } else {
            pre = pre->next; // 如果没数到指定的数，就继续移动，并统计
            p = p->next;
            ++i;
        }
    }
    cout << p->data << endl; // 输出圈的最后一个数
}

int main() {
    // 1. 定义头尾节点指针, 初始化头节点指针
    LinkNode *head;
    InitNode(head);
    LinkNode *rear;

    // 2.定义, 输入需要的参数; 初始化数组并赋值
    int n, m, from;
    cout << "请输入元素个数: ";
    cin >> n;
    cout << "从第几个人开始? ";
    cin >> from;
    cout << "第几个人出圈? ";
    cin >> m;
    int *a = new int[n]; // 创建动态数组

    for (int i = 0; i < n; ++i) { // 把元素插入到数组中
        a[i] = i + 1;
    }

    //  3. 尾插法创建循环单链表并得到尾指针
    CreateListByRear(head, rear, a, n);

    //  4. 出圈并输出
    cout << "出圈顺序为: ";
    out(head, rear, m, from);

    //  5. 出圈后仅剩头节点，释放头节点指针所指空间即可
    delete head;

    return 0;
}