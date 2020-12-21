#include <iostream>
#include "btree_jm.h"

int main()
{
	ElemType c1, c2, *p1;
	BTNode *bt, *p2;
	
	ElemType a[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
//	ElemType a[100] = "A(B(D(,G)),C(E,F))";

	p1 = a;
	CreateBTree(bt, p1);
	
	cout << "(1) ���ű�ʾ�����������" << endl;
	cout << a << endl << endl;
	
	cout << "(2) ���һ���ڵ��ֵ������ýڵ�����Һ��ӵ�ֵ" << endl;
	cout << "��������Ҫ���ҵĽڵ㣺"; cin >> c1;
	if (p2 = FindNode(bt, c1))
	{
		cout << "�ҵ��ýڵ�" << endl;
		if (p2->lchild)
			cout << "�ýڵ������Ϊ��" << p2->lchild->data << endl;
		else
			cout << "�ýڵ�û������" << endl;

		if (p2->rchild)
			cout << "�ýڵ���Һ���Ϊ��" << p2->rchild->data << endl;
		else
			cout << "�ýڵ�û���Һ���" << endl;
	}
	else
		cout << "�Ҳ����ýڵ�" << endl;
	cout << endl;
	
	cout << "(3) ����ö������ĸ߶�" << endl;
	cout << "�ö������ĸ߶�Ϊ��" << BTHeight(bt) << endl << endl;
	
	cout << "(4) ����ö������Ľڵ�ĸ���" << endl;
	cout << "�ö���������" << CountNode(bt) << "���ڵ�" << endl << endl;
	
	cout << "(5) ����ö�����˫��֧�ڵ�ĸ���" << endl;
	cout << "�ö���������" << CountDNode(bt) << "��˫��֧�ڵ�" << endl << endl;
	
	cout << "(6) ����ö���������֧�ڵ�ĸ���" << endl;
	cout << "�ö���������" << CountSNode(bt) << "������֧�ڵ�" << endl << endl;

	cout << "(7) ����ö�������Ҷ�ӽڵ�ĸ���" << endl;
	cout << "�ö���������" << CountLeafNode(bt) << "��Ҷ�ӽڵ�" << endl << endl;
	
	cout << "(8) ����ö������Ŀ��" << endl;
	int i, mx = 0, height = BTHeight(bt);
	int* cnt = new int[height + 1];
	
	for (i = 1; i <= height; ++i)
		cnt[i] = 0;
	CountithNode(bt, 1, cnt);
	
	for (i = 1; i <= height; ++i)
		mx = mx > cnt[i] ? mx : cnt[i];
	cout << "�ö������Ŀ��Ϊ" << mx << endl << endl;
	
	cout << "(9) ����������е������ڵ�������������" << endl;
	cout << "�����������ڵ��ֵ��"; cin >> c1 >> c2;
	if (p2 = FindLCNode(bt, c1, c2))
		cout << "���ǵ�����Ĺ���������:" << p2->data << endl << endl;
	else
		cout << "δ�ҵ��������ڵ�" << endl << endl;

	cout << "(10) ���ٶ�����" << endl;
	DestroyBTree(bt);
	
	return 0;
}
