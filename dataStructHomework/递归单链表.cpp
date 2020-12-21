#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

typedef struct LNode /*定义单链表结点类型*/
{
    ElemType data;
    struct LNode *next; /*指向后继结点*/
} LinkList;

///////////////////////////////////////////////////////
//递归尾插法建表
void CreateList(LinkList *&L, ElemType *a, int n) {
    if (n == 0) {
        L = NULL;
        return;
    }
    LinkList *s = new LinkList;
    s->data = *a;
    L = s;
    CreateList(L->next, a + 1, n - 1);
}

/////////////////////////////////////////////////////////
//初始化单链表
void InitList(LinkList *&L) {
    L = NULL;
}

/////////////////////////////////////////////////////////
//递归销毁单链表
void DestroyList(LinkList *&L) {
    if (L == NULL)
        return;
    DestroyList(L->next);
    delete L;
}

////////////////////////////////////////////////////////
//判定是否为空表
int ListEmpty(LinkList *L) {
    return L->next == NULL;
}

///////////////////////////////////////////////////////
//求单链表的长度
int ListLength(LinkList *L) {
    if (L == NULL)
        return 0;
    return ListLength(L->next) + 1;
}

///////////////////////////////////////////////////////
//递归正序输出单链表
void DispList(LinkList *L) {
    if (L == NULL)
        return;
    cout << L->data << " ";
    DispList(L->next);
}

///////////////////////////////////////////////////////
//递归逆序输出单链表
void DispListR(LinkList *L) {
    if (L == NULL)
        return;
    DispListR(L->next);
    cout << L->data << " ";
}

///////////////////////////////////////////////////////
//求单表L中指定位置的某个数据元素GetElem(L,i,&e)
bool GetElem(LinkList *L, int i, ElemType &e) {
    if (i < 1 || L == NULL) { //此处原来差了:i<1
        return false;
    }
    if (i == 1) {
        e = L->data;
        return true;
    }
    return GetElem(L->next, i - 1, e);
}

//////////////////////////////////////////////////////////
//按元素值查找
int LocateElem(LinkList *L, ElemType e) {
    if (L == NULL) {
        return 0;
    }
    if (L->data == e) {
        return 1;
    }
    if (L->next) {
        return 1 + LocateElem(L->next, e);
    }
    return 0;
    /*
    int t = LocateElem(L->next, e); //t保存递归函数值，以免两次调用
    if (t)                          //如果递归没有返回0，说明e存在返回正常值
        return t + 1;
    return 0; //如果递归返回0，说明存在，返回0
*/
}

//////////////////////////////////////////////////////////////
//插入数据元素
bool ListInsert(LinkList *&L, int i, ElemType e) {
    if (i < 1 || (i > 1 && L == NULL)) { //如果越界
        return false;
    }
    if (i == 1) {
        LinkList *s = new LinkList;
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    return ListInsert(L->next, i - 1, e);
}

///////////////////////////////////////////////////////////////
//删除指定位置数据元素
bool ListDelete(LinkList *&L, int i, ElemType &e) {
    if (i <= 0 || L == NULL) { //如果越界
        return false;
    }
    if (i == 1) {
        LinkList *q = L;
        L = L->next;
        delete q;
        return true;
    }
    if (L->next)
        return ListDelete(L->next, i - 1, e);
    return false;
}

///////////////////////////////////////////////////////////////
//删除第一个数据元素
void del(LinkList *&L, ElemType e) {
    if (L == NULL)
        return;
    if (L->data == e) {
        LinkList *t = L;
        L = L->next;
        delete t;
        return;
    } else
        del(L->next, e);
}

///////////////////////////////////////////////////////////////
//删除所有数据元素
void delall(LinkList *&L, ElemType e) {
    if (L == NULL)
        return;
    if (L->data == e) {
        LinkList *t = L;
        L = L->next;
        delete t;
        delall(L, e);
    } else
        delall(L->next, e);
}

///////////////////////////////////////////////////////////////
//返回链表最大值
ElemType maxv(LinkList *L) {
    if (L->next == NULL)
        return L->data;
    ElemType m = maxv(L->next);
    return m > L->data ? m : L->data;
}

///////////////////////////////////////////////////////////////
//返回链表最小值
ElemType minv(LinkList *L) {
    if (L->next == NULL)
        return L->data;
    ElemType m = minv(L->next);
    return m < L->data ? m : L->data;
}

/////////////////////////////////////////
//以下为主函数部分
int main() {
    int k;
    ElemType temp;
    LinkList *L1 = NULL;
    InitList(L1); //初始化单链表
                  /////////////////////////////////////////
    cout << "1.插入数据:" << endl;
    ElemType a[8] = {13, 15, 8, 4, 8, 3, 4, 8};
    //一个一个的尾部插入
    /*for (int i = 0; i < 8; i++)
        if (!ListInsert(L1, i + 1, a[i]))
            cout << "插入失败!";*/
    //递归一次完成
    CreateList(L1, a, 8);
    /////////////////////////////////////////
    cout << "\n2.正向输出所有节点值:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n3.逆向输出所有节点值:";
    DispListR(L1);
    /////////////////////////////////////////
    cout << "\n4.输出单链表中数据结点个数:" << ListLength(L1) << endl;
    /////////////////////////////////////////
    cout << "\n5.输出指定位置元素";
    cout << "请输入取的位置:";
    cin >> k;
    if (GetElem(L1, k, temp))
        cout << "取值成功，该单链表的第" << k << "个元素的值为:" << temp << endl;
    else
        cout << "取值失败，你输入的位置" << k << "越界" << endl;
    /////////////////////////////////////////
    cout << "\n6.在单链表指定位置插入元素 :" << endl;
    cout << "请输入插入的位置:";
    cin >> k;
    cout << "请输入插入元素的值:";
    cin >> temp;
    if (ListInsert(L1, k, temp))
        cout << "插入成功" << endl;
    else
        cout << "插入失败!" << endl;
    /////////////////////////////////////////
    cout << "\n7.正向输出所有节点值:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n8.删除单链表指定位置的元素" << endl
         << "请输入删除的位置:";
    cin >> k;
    if (ListDelete(L1, k, temp))
        cout << "删除成功，删除的元素为:" << temp << endl;
    else
        cout << "删除失败!" << endl;
    /////////////////////////////////////////
    cout << "\n9.正向输出所有节点值:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n10.删除指定值的第一个数据结点" << endl;
    cout << "请输入删除的值:";
    cin >> k;
    del(L1, k);
    cout << "删除成功，删除的元素为:" << k << endl;
    /////////////////////////////////////////
    cout << "\n11.正向输出所有节点值:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n12.删除指定值的所有数据结点" << endl;
    cout << "请输入删除的值:";
    cin >> k;
    delall(L1, k);
    cout << "删除成功，删除的元素为:" << k << endl;
    /////////////////////////////////////////
    cout << "\n13.正向输出所有节点值:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n14.输出该链表的最大值:" << maxv(L1) << endl;
    /////////////////////////////////////////
    cout << "\n15.输出该链表的最大值:" << minv(L1) << endl;
    /////////////////////////////////////////
    cout << "\n16.查找元素:" << endl
         << "请输入查找元素的值:";
    cin >> temp;
    if (LocateElem(L1, temp))
        cout << "输出元素" << temp << "的位置为:" << LocateElem(L1, temp) << endl;
    else
        cout << "元素" << temp << "不存在." << endl;
    /////////////////////////////////////////
    cout << "\n17.释放单链表" << endl;
    DestroyList(L1);
    return 0;
}
