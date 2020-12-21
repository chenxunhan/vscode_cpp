#include <iostream>
#include "btree1.h"

void main()
{
	BTNode *bt,*p;
	char a[100]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	//cout<<"请输入树的括号表示法:";
	//cin>>a;
	//CreateBTNode(bt,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	CreatBTNode(bt,a,0,0);//递归方式创建二叉树
	cout<<"二叉树的基本运算如下:"<<endl;
	cout<<"  (1)输出二叉树:";DispBTNode(bt);cout<<endl;
	cout<<"  (2)查找节点孩子:"<<endl;
	cout<<"请输入你要查找的元素：";ElemType c='H';cin>>c;
	p=FindNode(bt,c);
	if(p==NULL)
		cout<<"该元素不存于二叉树内。"<<endl;
	else
	{
		if(p->lchild!=NULL)
			cout<<c<<"的"<<"左孩子节点为："<<p->lchild->data<<endl;
		else
			cout<<c<<"没有左孩子节点!"<<endl;
		if(p->rchild!=NULL)
			cout<<c<<"的"<<"右孩子节点为："<<p->rchild->data<<endl;
		else
			cout<<c<<"没有右孩子节点!"<<endl;
	}
	cout<<endl;
	cout<<"  (3)该树的深度:"<<BTNodeDepth(bt)<<endl;
	cout<<"  (4)该树的宽度(队列实现方式):"<<BTWidth(bt)<<endl;//用队列方式实现

	int w[20]={0},h=BTNodeDepth(bt);//初始化每一行的宽度为0,h为该树的深度
	width(bt,w,1);
	cout<<"输出每层的宽度:";
	for(int i=1;i<=h;i++)
		cout<<w[i]<<"\t";


	cout<<"\n二叉树的宽度为(递归实现方式)："<<maxwidth(w,h)<<endl;
	cout<<"  (5)该树的节点个数:"<<Nodes(bt)<<endl;
	cout<<"该树的叶子结点为:"<<countleaf(bt)<<"个"<<endl;
	cout<<"该树的双分支结点为:"<<count_T2(bt)<<"个"<<endl;
	cout<<"该树的单分支结点为:"<<count_T1(bt)<<"个"<<endl;

	
	cout<<"  (7)释放二叉树"<<endl;
	DestroyBTNode(bt);
}
