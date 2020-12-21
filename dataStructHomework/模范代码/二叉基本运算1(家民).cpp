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
	
	cout << "(1) 括号表示法输出该树：" << endl;
	cout << a << endl << endl;
	
	cout << "(2) 输出一个节点的值，输出该节点的左，右孩子的值" << endl;
	cout << "请输入需要查找的节点："; cin >> c1;
	if (p2 = FindNode(bt, c1))
	{
		cout << "找到该节点" << endl;
		if (p2->lchild)
			cout << "该节点的左孩子为：" << p2->lchild->data << endl;
		else
			cout << "该节点没有左孩子" << endl;

		if (p2->rchild)
			cout << "该节点的右孩子为：" << p2->rchild->data << endl;
		else
			cout << "该节点没有右孩子" << endl;
	}
	else
		cout << "找不到该节点" << endl;
	cout << endl;
	
	cout << "(3) 输出该二叉树的高度" << endl;
	cout << "该二叉树的高度为：" << BTHeight(bt) << endl << endl;
	
	cout << "(4) 输出该二叉树的节点的个数" << endl;
	cout << "该二叉树共有" << CountNode(bt) << "个节点" << endl << endl;
	
	cout << "(5) 输出该二叉树双分支节点的个数" << endl;
	cout << "该二叉树共有" << CountDNode(bt) << "个双分支节点" << endl << endl;
	
	cout << "(6) 输出该二叉树单分支节点的个数" << endl;
	cout << "该二叉树共有" << CountSNode(bt) << "个单分支节点" << endl << endl;

	cout << "(7) 输出该二叉树的叶子节点的个数" << endl;
	cout << "该二叉树共有" << CountLeafNode(bt) << "个叶子节点" << endl << endl;
	
	cout << "(8) 输出该二叉树的宽度" << endl;
	int i, mx = 0, height = BTHeight(bt);
	int* cnt = new int[height + 1];
	
	for (i = 1; i <= height; ++i)
		cnt[i] = 0;
	CountithNode(bt, 1, cnt);
	
	for (i = 1; i <= height; ++i)
		mx = mx > cnt[i] ? mx : cnt[i];
	cout << "该二叉树的宽度为" << mx << endl << endl;
	
	cout << "(9) 输出二叉树中的两个节点的最近公共祖先" << endl;
	cout << "请输入两个节点的值："; cin >> c1 >> c2;
	if (p2 = FindLCNode(bt, c1, c2))
		cout << "它们的最近的公共祖先是:" << p2->data << endl << endl;
	else
		cout << "未找到这两个节点" << endl << endl;

	cout << "(10) 销毁二叉树" << endl;
	DestroyBTree(bt);
	
	return 0;
}
