#include <iostream>
#define MaxSize 100
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;

void CreateBTNode(BTNode *&b,char *str)		//由str串创建二叉链
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{
   	   	switch(ch) 
		{
			case '(':top++;St[top]=p;k=1; break;		//为左节点
			case ')':top--;break;
			case ',':k=2; break;                      	//为右节点
			default:p=new BTNode;
					p->data=ch;
					p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    //p指向二叉树的根节点
						b=p;
					else  							//已建立二叉树根节点
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

BTNode *St[MaxSize];                   //存放父节点的地址的栈
void CreatBTNode(BTNode *&b,char *str,int i,int j)//根据字符串s递归创建二叉树b,判断第字符串i个元素,j作为存放父节点地址的栈的栈顶指针
{
	if(str[i]=='\0');      //已经到最后,不做任何操作
	else
		if(str[i]=='(')          
			if(str[i+1]==',')      //如果遇到'('和','连续出现则++j,否则下一个节点的父节点会上升一位,i+1指向下一个元素
				CreatBTNode(St[j-1]->lchild,str,++i,++j);
			else                 //遇到'(',指向左孩子节点,栈顶不变
				CreatBTNode(St[j-1]->lchild,str,++i,j);
		else if(str[i]==')')    //如果遇到')',父节点退栈,栈顶-1,,即--j
			CreatBTNode(b,str,++i,--j);
		else if(str[i]==',')    //如果遇到',',指向右孩子节点,父节点退栈
			CreatBTNode(St[j-1]->rchild,str,++i,--j);
		else                 //字母的情况,则将数据写入二叉树,将这个数据的地址进栈
		{
			b=new BTNode;
			b->data=str[i];
			b->lchild=b->rchild=NULL;
			St[j]=b;
			CreatBTNode(b,str,++i,++j);//进栈后栈顶j+1,i+1指向下一个元素
		}
}



BTNode *FindNode(BTNode *b,ElemType x)	//返回data域为x的节点指针
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


BTNode *LchildNode(BTNode *p)	//返回*p节点的左孩子节点指针
{
    return p->lchild;
}


BTNode *RchildNode(BTNode *p)	//返回*p节点的右孩子节点指针
{
    return p->rchild;
}


int BTNodeDepth(BTNode *b)	//求二叉树b的深度
{
   	int lchilddep,rchilddep;
   	if (b==NULL) 
		return(0); 							//空树的高度为0
   	else  
	{	
		lchilddep=BTNodeDepth(b->lchild);	//求左子树的高度为lchilddep
	  	rchilddep=BTNodeDepth(b->rchild);	//求右子树的高度为rchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
   	}
}


void DispBTNode(BTNode *b)	//以括号表示法输出二叉树
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


int BTWidth(BTNode *b)  //求二叉树b的宽度(队列法)
{
	struct 
	{
		int lno;		//节点的层次编号
		BTNode *p;		//节点指针
	} Qu[MaxSize];		//定义顺序非循环队列
	int front,rear;							//定义队首和队尾指针
	int lnum,max,i,n;
	front=rear=0;							//置队列为空队
    if (b!=NULL) 
	{
		rear++;	
		Qu[rear].p=b;						//根节点指针入队
		Qu[rear].lno=1;						//根节点的层次编号为1
		while (rear!=front)					//队列不为空
		{
			front++;
			b=Qu[front].p;					//队头出队
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)			//左孩子入队
			{
				rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)			//右孩子入队
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


//获得每一行的宽度  (递归法)
void width(BTNode *b,int w[],int i)//i代表第i层宽度,根为第一层，w[1..n]存储1---n层的宽度
{
	if(b!=NULL)
	{
		w[i]++;  //第i层的节点数加1
		width(b->lchild,w,i+1);  //对左子树递归,每往下一层，深度就会加1
		width(b->rchild,w,i+1);
	}
}


//在所有宽度种找出最大值
int maxwidth(int w[],int h)
{
	for(int i=1;i<=h;i++)
		if(w[i]>w[1])
			w[1]=w[i];
	return w[1];
}

int Nodes(BTNode *b)	//求二叉树b的节点个数
{
	if (b==NULL)  //P198图7.4中  a 状态
		return 0;
    else
       return Nodes(b->lchild)+Nodes(b->rchild)+1;	//P198图7.4中  b,c,d,e 状态
}


int countleaf(BTNode *T)
{
	if(T==NULL)         //当结点为空时，叶子结点数为0 条件也可以写成if(!T)  //P198图7.4中  a 状态
		return 0;
	else if(T->lchild==NULL && T->rchild==NULL) //当结点左右子树皆为空时,返回结点数值1  //P198图7.4中  b 状态
		return 1;
	else
		return(countleaf(T->lchild)+countleaf(T->rchild)); //返回左子树的结点数与右子树的叶子结点数之和 //P198图7.4中  c,d,e状态
}//递归统计叶子结点


int count_T2(BTNode *T)
{
	if(T==NULL)         //当结点为空时，双分支结点数为0  //P198图7.4中  a 状态
		return 0;
	else if(T->lchild!=NULL && T->rchild!=NULL) //当结点左右子树皆不为空时,返回双分支结点数值1再加上左右子树的双分支结点数  //P198图7.4中  e状态
		return 1+count_T2(T->lchild)+count_T2(T->rchild);
	else
		return (count_T2(T->lchild)+count_T2(T->rchild)); //返回左子树的双分支结点数与右子树的双分支结点数之和 //P198图7.4中  b,c,d 状态
}//递归统计双分支结点

int count_T1(BTNode *T)
{
	if(!T)         //当结点为空时，单分支结点数为0 //P198图7.4中  a 状态
		return 0;
	else if(T->lchild && !T->rchild  || !T->lchild && T->rchild) //当结点为右空左不空或左空右不空时,返回单分支结点数值1再加上左右子树的单分支结点数//P198图7.4中  c,d 状态
		return 1+count_T1(T->lchild)+count_T1(T->rchild);
	else
		return (count_T1(T->lchild)+count_T1(T->rchild)); //返回左子树的单分支结点数与右子树的单分支结点数之和
}//递归统计单分支结点


void DestroyBTNode(BTNode *&b)
{
	if (b!=NULL)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		delete b;
	}
}
