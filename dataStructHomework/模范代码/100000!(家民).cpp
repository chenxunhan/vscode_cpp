#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode *next;
} LinkList;

//  1. 初始化单链表
void InitList(LinkList *&L) {
    L = new LinkList;
    L->next = NULL;
}

//  2. 通过尾指针，在尾节点后插入元素，用于进位时将进位数字插入到链表后面
//  传入引用型指针，同步修改主函数中的尾指针的值； 将进位的一个数字x插入到链表后面
void InsertRear(LinkList *&R, int x) {
    LinkList *newNode = new LinkList;
    newNode->data = x;
    R->next = newNode;
    newNode->next = NULL;
    R = newNode; // 尾指针指向新建的节点
}

//  3. 将数字乘以节点的每一个数字，得到并处理结果，同时进位
void MultList(LinkList *&L, LinkList *&R, int x) {
    LinkList *p = L->next;      // 从第一个存储数字的节点开始
    int up = 0, sum;            // 存储进位的变量up初始值为0
    while (p) {                 // 遍历当前链表，并相乘改变当前位置的值，并得到进位
        sum = p->data * x + up; // 先得到相乘并加上进位的结果
        p->data = sum % 10;     // 更新当前节点data值
        up = sum / 10;          // 更新进位数字
        p = p->next;            // 移动到下一个节点
    }

    //  只有当数字乘遍所有当前节点后，进位数字仍不为0，才代表结果的位数发生了改变
    //  如果此时进位仍不为0的话，将进位的数字倒序插入链表后面
    while (up) {
        InsertRear(R, up % 10);
        up /= 10;
    }
}

//  4. 反转单链表
void ReveList(LinkList *&L) {
    //  创建并初始化一个新表头
    LinkList *newHead;
    InitList(newHead);

    //  从第一个有值的节点开始操作，依次进行反转。p代表当前正在操作的节点
    LinkList *p = L->next;

    //  当指针未到达链表尾部时，依次得到需要操作的节点地址，并采用类似头插法的方法，将需要操作的节点依次插入到新的表头
    while (p) {
        L->next = p->next;       // 让原链表的头节点的next指针指向下下一个节点，此时p指向跳过的那个节点，即需要操作的节点
        p->next = newHead->next; // 将需要操作的节点的next指针，指向新表头的下一个节点
        newHead->next = p;       // 让表头的next指针指向正在操作的节点
        p = L->next;             // p指向下一个需要操作的节点
    }

    delete L;    // 释放头指针指向的空间
    L = newHead; // 让头指针指向新的头节点
}

//  5. 输出单链表
void DispList(LinkList *L) {
    LinkList *p = L->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
}

//  6. 得到链表长度
int ListLength(LinkList *L) {
    LinkList *p = L->next;
    int i = 0;
    while (p) {
        ++i;
        p = p->next;
    }
    return i;
}

//  7. 销毁单链表
void DestroyList(LinkList *&L) {
    LinkList *p = L->next;
    while (p) {
        L->next = L->next->next;
        delete p;
        p = L->next;
    }
    delete L;
}

int main() {
    //  1. 创建单链表，定义尾指针，让尾指针指向表头；此链表逆序存储结果的数字
    LinkList *L1;
    InitList(L1);
    LinkList *Rear = L1;

    //  2. 将数字1插入到链表后面
    InsertRear(Rear, 1);

    //  3. 输入n
    int n;
    cout << "请输入你要求阶乘的数: ";
    cin >> n;
    cout << endl;

    //  4. 1~n依次与单链表上的节点进行相乘、进位等
    for (int i = 1; i <= n; ++i) {
        MultList(L1, Rear, i);
    }

    //  5. 反转单链表
    ReveList(L1);

    //  6. 输出结果位数，以及输出结果
    cout << "该结果共有" << ListLength(L1) << "位" << endl
         << endl;

    cout << "结果为: " << endl;
    DispList(L1);

    //  7. 释放单链表
    DestroyList(L1);

    return 0;
}
