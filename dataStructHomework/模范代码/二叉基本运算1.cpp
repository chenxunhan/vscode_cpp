#include <iostream>
#include "btree1.h"

void main()
{
	BTNode *bt,*p;
	char a[100]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	//cout<<"�������������ű�ʾ��:";
	//cin>>a;
	//CreateBTNode(bt,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	CreatBTNode(bt,a,0,0);//�ݹ鷽ʽ����������
	cout<<"�������Ļ�����������:"<<endl;
	cout<<"  (1)���������:";DispBTNode(bt);cout<<endl;
	cout<<"  (2)���ҽڵ㺢��:"<<endl;
	cout<<"��������Ҫ���ҵ�Ԫ�أ�";ElemType c='H';cin>>c;
	p=FindNode(bt,c);
	if(p==NULL)
		cout<<"��Ԫ�ز����ڶ������ڡ�"<<endl;
	else
	{
		if(p->lchild!=NULL)
			cout<<c<<"��"<<"���ӽڵ�Ϊ��"<<p->lchild->data<<endl;
		else
			cout<<c<<"û�����ӽڵ�!"<<endl;
		if(p->rchild!=NULL)
			cout<<c<<"��"<<"�Һ��ӽڵ�Ϊ��"<<p->rchild->data<<endl;
		else
			cout<<c<<"û���Һ��ӽڵ�!"<<endl;
	}
	cout<<endl;
	cout<<"  (3)���������:"<<BTNodeDepth(bt)<<endl;
	cout<<"  (4)�����Ŀ��(����ʵ�ַ�ʽ):"<<BTWidth(bt)<<endl;//�ö��з�ʽʵ��

	int w[20]={0},h=BTNodeDepth(bt);//��ʼ��ÿһ�еĿ��Ϊ0,hΪ���������
	width(bt,w,1);
	cout<<"���ÿ��Ŀ��:";
	for(int i=1;i<=h;i++)
		cout<<w[i]<<"\t";


	cout<<"\n�������Ŀ��Ϊ(�ݹ�ʵ�ַ�ʽ)��"<<maxwidth(w,h)<<endl;
	cout<<"  (5)�����Ľڵ����:"<<Nodes(bt)<<endl;
	cout<<"������Ҷ�ӽ��Ϊ:"<<countleaf(bt)<<"��"<<endl;
	cout<<"������˫��֧���Ϊ:"<<count_T2(bt)<<"��"<<endl;
	cout<<"�����ĵ���֧���Ϊ:"<<count_T1(bt)<<"��"<<endl;

	
	cout<<"  (7)�ͷŶ�����"<<endl;
	DestroyBTNode(bt);
}
