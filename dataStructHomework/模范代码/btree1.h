#include <iostream>
#define MaxSize 100
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;

void CreateBTNode(BTNode *&b,char *str)		//��str������������
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
			case '(':top++;St[top]=p;k=1; break;		//Ϊ��ڵ�
			case ')':top--;break;
			case ',':k=2; break;                      	//Ϊ�ҽڵ�
			default:p=new BTNode;
					p->data=ch;
					p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    //pָ��������ĸ��ڵ�
						b=p;
					else  							//�ѽ������������ڵ�
					{	
						switch(k) 
						{
						case 1:St[top]->lchild=p;break;
						case 2:St[top]->rchild=p;break;
						}
					}
		}
		j++;
		ch=str[j];
	}
}

BTNode *St[MaxSize];                   //��Ÿ��ڵ�ĵ�ַ��ջ
void CreatBTNode(BTNode *&b,char *str,int i,int j)//�����ַ���s�ݹ鴴��������b,�жϵ��ַ���i��Ԫ��,j��Ϊ��Ÿ��ڵ��ַ��ջ��ջ��ָ��
{
	if(str[i]=='\0');      //�Ѿ������,�����κβ���
	else
		if(str[i]=='(')          
			if(str[i+1]==',')      //�������'('��','����������++j,������һ���ڵ�ĸ��ڵ������һλ,i+1ָ����һ��Ԫ��
				CreatBTNode(St[j-1]->lchild,str,++i,++j);
			else                 //����'(',ָ�����ӽڵ�,ջ������
				CreatBTNode(St[j-1]->lchild,str,++i,j);
		else if(str[i]==')')    //�������')',���ڵ���ջ,ջ��-1,,��--j
			CreatBTNode(b,str,++i,--j);
		else if(str[i]==',')    //�������',',ָ���Һ��ӽڵ�,���ڵ���ջ
			CreatBTNode(St[j-1]->rchild,str,++i,--j);
		else                 //��ĸ�����,������д�������,��������ݵĵ�ַ��ջ
		{
			b=new BTNode;
			b->data=str[i];
			b->lchild=b->rchild=NULL;
			St[j]=b;
			CreatBTNode(b,str,++i,++j);//��ջ��ջ��j+1,i+1ָ����һ��Ԫ��
		}
}



BTNode *FindNode(BTNode *b,ElemType x)	//����data��Ϊx�Ľڵ�ָ��
{
	BTNode *p;
	if (b==NULL)
	     return NULL;
	else if (b->data==x)
	     return b;
	else
	{	
		p=FindNode(b->lchild,x);
		if (p!=NULL) 
			return p;
		else 
			return FindNode(b->rchild,x);
	}
}


BTNode *LchildNode(BTNode *p)	//����*p�ڵ�����ӽڵ�ָ��
{
    return p->lchild;
}


BTNode *RchildNode(BTNode *p)	//����*p�ڵ���Һ��ӽڵ�ָ��
{
    return p->rchild;
}


int BTNodeDepth(BTNode *b)	//�������b�����
{
   	int lchilddep,rchilddep;
   	if (b==NULL) 
		return(0); 							//�����ĸ߶�Ϊ0
   	else  
	{	
		lchilddep=BTNodeDepth(b->lchild);	//���������ĸ߶�Ϊlchilddep
	  	rchilddep=BTNodeDepth(b->rchild);	//���������ĸ߶�Ϊrchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
   	}
}


void DispBTNode(BTNode *b)	//�����ű�ʾ�����������
{
	if (b!=NULL)
	{
		cout<<b->data;
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			cout<<"(";
			DispBTNode(b->lchild);
			if (b->rchild!=NULL) cout<<",";
			DispBTNode(b->rchild);
			cout<<")";
		}
	}
}


int BTWidth(BTNode *b)  //�������b�Ŀ��(���з�)
{
	struct 
	{
		int lno;		//�ڵ�Ĳ�α��
		BTNode *p;		//�ڵ�ָ��
	} Qu[MaxSize];		//����˳���ѭ������
	int front,rear;							//������׺Ͷ�βָ��
	int lnum,max,i,n;
	front=rear=0;							//�ö���Ϊ�ն�
    if (b!=NULL) 
	{
		rear++;	
		Qu[rear].p=b;						//���ڵ�ָ�����
		Qu[rear].lno=1;						//���ڵ�Ĳ�α��Ϊ1
		while (rear!=front)					//���в�Ϊ��
		{
			front++;
			b=Qu[front].p;					//��ͷ����
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)			//�������
			{
				rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)			//�Һ������
			{
				rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		max=0;lnum=1;i=1;
		while (i<=rear)
		{
			n=0;
			while (i<=rear && Qu[i].lno==lnum) 
			{
				n++;i++;
			}
			lnum=Qu[i].lno;
			if (n>max) max=n;
		}
		return max;
	}
	else
		return 0;
}


//���ÿһ�еĿ��  (�ݹ鷨)
void width(BTNode *b,int w[],int i)//i�����i����,��Ϊ��һ�㣬w[1..n]�洢1---n��Ŀ��
{
	if(b!=NULL)
	{
		w[i]++;  //��i��Ľڵ�����1
		width(b->lchild,w,i+1);  //���������ݹ�,ÿ����һ�㣬��Ⱦͻ��1
		width(b->rchild,w,i+1);
	}
}


//�����п�����ҳ����ֵ
int maxwidth(int w[],int h)
{
	for(int i=1;i<=h;i++)
		if(w[i]>w[1])
			w[1]=w[i];
	return w[1];
}

int Nodes(BTNode *b)	//�������b�Ľڵ����
{
	if (b==NULL)  //P198ͼ7.4��  a ״̬
		return 0;
    else
       return Nodes(b->lchild)+Nodes(b->rchild)+1;	//P198ͼ7.4��  b,c,d,e ״̬
}


int countleaf(BTNode *T)
{
	if(T==NULL)         //�����Ϊ��ʱ��Ҷ�ӽ����Ϊ0 ����Ҳ����д��if(!T)  //P198ͼ7.4��  a ״̬
		return 0;
	else if(T->lchild==NULL && T->rchild==NULL) //���������������Ϊ��ʱ,���ؽ����ֵ1  //P198ͼ7.4��  b ״̬
		return 1;
	else
		return(countleaf(T->lchild)+countleaf(T->rchild)); //�����������Ľ��������������Ҷ�ӽ����֮�� //P198ͼ7.4��  c,d,e״̬
}//�ݹ�ͳ��Ҷ�ӽ��


int count_T2(BTNode *T)
{
	if(T==NULL)         //�����Ϊ��ʱ��˫��֧�����Ϊ0  //P198ͼ7.4��  a ״̬
		return 0;
	else if(T->lchild!=NULL && T->rchild!=NULL) //��������������Բ�Ϊ��ʱ,����˫��֧�����ֵ1�ټ�������������˫��֧�����  //P198ͼ7.4��  e״̬
		return 1+count_T2(T->lchild)+count_T2(T->rchild);
	else
		return (count_T2(T->lchild)+count_T2(T->rchild)); //������������˫��֧���������������˫��֧�����֮�� //P198ͼ7.4��  b,c,d ״̬
}//�ݹ�ͳ��˫��֧���

int count_T1(BTNode *T)
{
	if(!T)         //�����Ϊ��ʱ������֧�����Ϊ0 //P198ͼ7.4��  a ״̬
		return 0;
	else if(T->lchild && !T->rchild  || !T->lchild && T->rchild) //�����Ϊ�ҿ��󲻿ջ�����Ҳ���ʱ,���ص���֧�����ֵ1�ټ������������ĵ���֧�����//P198ͼ7.4��  c,d ״̬
		return 1+count_T1(T->lchild)+count_T1(T->rchild);
	else
		return (count_T1(T->lchild)+count_T1(T->rchild)); //�����������ĵ���֧��������������ĵ���֧�����֮��
}//�ݹ�ͳ�Ƶ���֧���


void DestroyBTNode(BTNode *&b)
{
	if (b!=NULL)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		delete b;
	}
}
