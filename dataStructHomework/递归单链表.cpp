#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

typedef struct LNode /*���嵥����������*/
{
    ElemType data;
    struct LNode *next; /*ָ���̽��*/
} LinkList;

///////////////////////////////////////////////////////
//�ݹ�β�巨����
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
//��ʼ��������
void InitList(LinkList *&L) {
    L = NULL;
}

/////////////////////////////////////////////////////////
//�ݹ����ٵ�����
void DestroyList(LinkList *&L) {
    if (L == NULL)
        return;
    DestroyList(L->next);
    delete L;
}

////////////////////////////////////////////////////////
//�ж��Ƿ�Ϊ�ձ�
int ListEmpty(LinkList *L) {
    return L->next == NULL;
}

///////////////////////////////////////////////////////
//������ĳ���
int ListLength(LinkList *L) {
    if (L == NULL)
        return 0;
    return ListLength(L->next) + 1;
}

///////////////////////////////////////////////////////
//�ݹ��������������
void DispList(LinkList *L) {
    if (L == NULL)
        return;
    cout << L->data << " ";
    DispList(L->next);
}

///////////////////////////////////////////////////////
//�ݹ��������������
void DispListR(LinkList *L) {
    if (L == NULL)
        return;
    DispListR(L->next);
    cout << L->data << " ";
}

///////////////////////////////////////////////////////
//�󵥱�L��ָ��λ�õ�ĳ������Ԫ��GetElem(L,i,&e)
bool GetElem(LinkList *L, int i, ElemType &e) {
    if (i < 1 || L == NULL) { //�˴�ԭ������:i<1
        return false;
    }
    if (i == 1) {
        e = L->data;
        return true;
    }
    return GetElem(L->next, i - 1, e);
}

//////////////////////////////////////////////////////////
//��Ԫ��ֵ����
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
    int t = LocateElem(L->next, e); //t����ݹ麯��ֵ���������ε���
    if (t)                          //����ݹ�û�з���0��˵��e���ڷ�������ֵ
        return t + 1;
    return 0; //����ݹ鷵��0��˵�����ڣ�����0
*/
}

//////////////////////////////////////////////////////////////
//��������Ԫ��
bool ListInsert(LinkList *&L, int i, ElemType e) {
    if (i < 1 || (i > 1 && L == NULL)) { //���Խ��
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
//ɾ��ָ��λ������Ԫ��
bool ListDelete(LinkList *&L, int i, ElemType &e) {
    if (i <= 0 || L == NULL) { //���Խ��
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
//ɾ����һ������Ԫ��
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
//ɾ����������Ԫ��
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
//�����������ֵ
ElemType maxv(LinkList *L) {
    if (L->next == NULL)
        return L->data;
    ElemType m = maxv(L->next);
    return m > L->data ? m : L->data;
}

///////////////////////////////////////////////////////////////
//����������Сֵ
ElemType minv(LinkList *L) {
    if (L->next == NULL)
        return L->data;
    ElemType m = minv(L->next);
    return m < L->data ? m : L->data;
}

/////////////////////////////////////////
//����Ϊ����������
int main() {
    int k;
    ElemType temp;
    LinkList *L1 = NULL;
    InitList(L1); //��ʼ��������
                  /////////////////////////////////////////
    cout << "1.��������:" << endl;
    ElemType a[8] = {13, 15, 8, 4, 8, 3, 4, 8};
    //һ��һ����β������
    /*for (int i = 0; i < 8; i++)
        if (!ListInsert(L1, i + 1, a[i]))
            cout << "����ʧ��!";*/
    //�ݹ�һ�����
    CreateList(L1, a, 8);
    /////////////////////////////////////////
    cout << "\n2.����������нڵ�ֵ:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n3.����������нڵ�ֵ:";
    DispListR(L1);
    /////////////////////////////////////////
    cout << "\n4.��������������ݽ�����:" << ListLength(L1) << endl;
    /////////////////////////////////////////
    cout << "\n5.���ָ��λ��Ԫ��";
    cout << "������ȡ��λ��:";
    cin >> k;
    if (GetElem(L1, k, temp))
        cout << "ȡֵ�ɹ����õ�����ĵ�" << k << "��Ԫ�ص�ֵΪ:" << temp << endl;
    else
        cout << "ȡֵʧ�ܣ��������λ��" << k << "Խ��" << endl;
    /////////////////////////////////////////
    cout << "\n6.�ڵ�����ָ��λ�ò���Ԫ�� :" << endl;
    cout << "����������λ��:";
    cin >> k;
    cout << "���������Ԫ�ص�ֵ:";
    cin >> temp;
    if (ListInsert(L1, k, temp))
        cout << "����ɹ�" << endl;
    else
        cout << "����ʧ��!" << endl;
    /////////////////////////////////////////
    cout << "\n7.����������нڵ�ֵ:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n8.ɾ��������ָ��λ�õ�Ԫ��" << endl
         << "������ɾ����λ��:";
    cin >> k;
    if (ListDelete(L1, k, temp))
        cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ:" << temp << endl;
    else
        cout << "ɾ��ʧ��!" << endl;
    /////////////////////////////////////////
    cout << "\n9.����������нڵ�ֵ:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n10.ɾ��ָ��ֵ�ĵ�һ�����ݽ��" << endl;
    cout << "������ɾ����ֵ:";
    cin >> k;
    del(L1, k);
    cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ:" << k << endl;
    /////////////////////////////////////////
    cout << "\n11.����������нڵ�ֵ:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n12.ɾ��ָ��ֵ���������ݽ��" << endl;
    cout << "������ɾ����ֵ:";
    cin >> k;
    delall(L1, k);
    cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ:" << k << endl;
    /////////////////////////////////////////
    cout << "\n13.����������нڵ�ֵ:";
    DispList(L1);
    /////////////////////////////////////////
    cout << "\n14.�������������ֵ:" << maxv(L1) << endl;
    /////////////////////////////////////////
    cout << "\n15.�������������ֵ:" << minv(L1) << endl;
    /////////////////////////////////////////
    cout << "\n16.����Ԫ��:" << endl
         << "���������Ԫ�ص�ֵ:";
    cin >> temp;
    if (LocateElem(L1, temp))
        cout << "���Ԫ��" << temp << "��λ��Ϊ:" << LocateElem(L1, temp) << endl;
    else
        cout << "Ԫ��" << temp << "������." << endl;
    /////////////////////////////////////////
    cout << "\n17.�ͷŵ�����" << endl;
    DestroyList(L1);
    return 0;
}
