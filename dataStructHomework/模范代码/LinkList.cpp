#include <iostream.h>

typedef char ElemType;

typedef struct LNode   /*定义单链表结点类型*/
{ 
    ElemType data;
    struct LNode *next;    /*指向后继结点*/
} LinkList;


/////////////////////////////////////////////////////////
//头插法建表
void CreateListF(LinkList *&L,ElemType a[],int n)
{ 
	LinkList *s;int i;
    L=new LinkList;  /*创建头结点*/
    L->next=NULL;
    for (i=0;i<n;i++)
    { 
		s=new LinkList;   /*创建新结点*/
        s->data=a[i];
		s->next=L->next;  /*将*s插在原开始结点之前,头结点之后*/
        L->next=s;
	}
}


///////////////////////////////////////////////////////
//尾插法建表
void CreateListR(LinkList *&L,ElemType a[],int n)
{  
	LinkList *s,*r;int i;
    L=new LinkList;  /*创建头结点*/
    r=L;    /*尾指标r始终指向终端结点,开始时指向头结点*/
    for (i=0;i<n;i++)
    { 
		s=new LinkList;   /*创建新结点*/
		s->data=a[i];r->next=s;  /*将*s插入*r之后*/
		r=s;
     }
     r->next=NULL;	/*终端结点next域置为NULL*/
}


/////////////////////////////////////////////////////////
//1.初始化单链表
void InitList(LinkList *&L)
{
	L=new LinkList;  	 /*创建头结点*/
	L->next=NULL;
}

/////////////////////////////////////////////////////////
//2.销毁单链表
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=NULL)
	{ 
		delete p;
		p=q;q=p->next;
	}
	delete p;
}



////////////////////////////////////////////////////////
//3.判定是否为空表
int ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}


///////////////////////////////////////////////////////
//4.求单链表的长度
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=NULL)
	{  
		i++;
		p=p->next;
	}
	return(i);
} 


///////////////////////////////////////////////////////
//5.输出单链表
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=NULL)
	{  
		cout<<p->data<<"    ";
		p=p->next;
	}
	cout<<endl;
}


///////////////////////////////////////////////////////
//6.求单表L中指定位置的某个数据元素GetElem(L,i,&e)
int GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;
	while (j<i && p!=NULL)
	{ 
		j++;
		p=p->next;
	}
	if (p==NULL) 
		return 0; /*不存在第i个数据结点*/
	else	  /*存在第i个数据结点*/
	{ 
		e=p->data;
		return 1;
	}
}


//////////////////////////////////////////////////////////
//7.按元素值查找
int LocateElem(LinkList *L,ElemType e)
{
	LinkList *p=L->next;int n=1;
	while (p!=NULL && p->data!=e)
	{  
		p=p->next; 
		n++; 
	}
	if (p==NULL) 
		return(0);
	else
		return(n);
}

//////////////////////////////////////////////////////////////
//8.插入数据元素
int ListInsert(LinkList *&L,int i,ElemType e)
{ 
	int j=0;
	LinkList *p=L,*s;
    while (j<i-1 && p!=NULL)     /*查找第i-1个结点*/
    { 
		j++;
	    p=p->next;
    }
	if (p==NULL)
		return 0; /*未找到位序为i-1的结点*/
	else	/*找到位序为i-1的结点*p*/
	{   
		s=new LinkList;		/*创建新结点*s*/
	    s->data=e;
	    s->next=p->next;  /*将*s插入到*p之后*/
	    p->next=s;
	    return 1;
	}
}




///////////////////////////////////////////////////////////////
//9.删除数据元素
int ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	while (j<i-1 && p!=NULL)  /*查找第i-1个结点*/
	{ 
		j++;
		p=p->next;
	}
	if (p==NULL) 
		return 0; /*未找到位序为i-1的结点*/
	else	/*找到位序为i-1的结点*p*/
	{    
		q=p->next;	   /*q指向要删除的结点*/
		if (q==NULL) 
			return 0;    /*若不存在第i个结点,返回0*/
		e=q->data;
	    p->next=q->next;	 /*从单链表中删除*q结点*/
	    delete q;       /*释放*q结点*/
	    return 1;
	}
}



/////////////////////////////////////////
//以下为主函数部分

void main()
{
	LinkList *L1;
	cout<<"1.初始化单链表:"<<endl;InitList(L1);

	cout<<"\n2.尾插法建表:"<<endl;
	ElemType a[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"插入失败!";
	cout<<"\n3.单链表的元素为:";
	DispList(L1);


	cout<<"\n4.该单链表的长度为:"<<ListLength(L1)<<endl;

	cout<<"\n5.该单链表";
	if(ListEmpty(L1))
		cout<<"为空!"<<endl;
	else
		cout<<"不为空!"<<endl;


	cout<<"\n6.取元素";
	ElemType temp;cout<<"请输入取的位置:";int k;cin>>k;
	if(GetElem(L1,k,temp))
		cout<<"取值成功，该单链表的第"<<k<<"个元素的值为:"<<temp<<endl;
	else
		cout<<"取值失败，你输入的位置"<<k<<"越界:"<<endl;

  
	cout<<"\n7.查找元素:"<<endl<<"请输入查找元素的值:";cin>>temp;
	if(LocateElem(L1,temp))
		cout<<"输出元素'"<<temp<<"'的位置为:"<<LocateElem(L1,temp)<<endl;
	else
		cout<<"元素'"<<temp<<"'不存在."<<endl;
  
	cout<<"\n8.在单链表指定位置插入元素 :"<<endl;
	cout<<"请输入插入的位置:";cin>>k;
	cout<<"请输入插入元素的值:";cin>>temp;

	if(ListInsert(L1,k,temp))
		cout<<"插入成功"<<endl;
	else
		cout<<"插入失败!"<<endl;

	cout<<"\n9.输出单链表"<<endl;
	DispList(L1);
	
	cout<<"\n10.删除单链表指定位置的元素"<<endl;
	cout<<"请输入删除的位置:";cin>>k;
	if(ListDelete(L1,k,temp))
		cout<<"删除成功，删除的元素为:"<<temp<<endl;
	else
		cout<<"删除失败!"<<endl;

	cout<<"\n11.输出单链表"<<endl;
	DispList(L1);
	cout<<"\n12.释放单链表"<<endl;
	DestroyList(L1);

}



