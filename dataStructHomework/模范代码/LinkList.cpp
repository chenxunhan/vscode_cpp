#include <iostream.h>

typedef char ElemType;

typedef struct LNode   /*���嵥����������*/
{ 
    ElemType data;
    struct LNode *next;    /*ָ���̽��*/
} LinkList;


/////////////////////////////////////////////////////////
//ͷ�巨����
void CreateListF(LinkList *&L,ElemType a[],int n)
{ 
	LinkList *s;int i;
    L=new LinkList;  /*����ͷ���*/
    L->next=NULL;
    for (i=0;i<n;i++)
    { 
		s=new LinkList;   /*�����½��*/
        s->data=a[i];
		s->next=L->next;  /*��*s����ԭ��ʼ���֮ǰ,ͷ���֮��*/
        L->next=s;
	}
}


///////////////////////////////////////////////////////
//β�巨����
void CreateListR(LinkList *&L,ElemType a[],int n)
{  
	LinkList *s,*r;int i;
    L=new LinkList;  /*����ͷ���*/
    r=L;    /*βָ��rʼ��ָ���ն˽��,��ʼʱָ��ͷ���*/
    for (i=0;i<n;i++)
    { 
		s=new LinkList;   /*�����½��*/
		s->data=a[i];r->next=s;  /*��*s����*r֮��*/
		r=s;
     }
     r->next=NULL;	/*�ն˽��next����ΪNULL*/
}


/////////////////////////////////////////////////////////
//1.��ʼ��������
void InitList(LinkList *&L)
{
	L=new LinkList;  	 /*����ͷ���*/
	L->next=NULL;
}

/////////////////////////////////////////////////////////
//2.���ٵ�����
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
//3.�ж��Ƿ�Ϊ�ձ�
int ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}


///////////////////////////////////////////////////////
//4.������ĳ���
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
//5.���������
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
//6.�󵥱�L��ָ��λ�õ�ĳ������Ԫ��GetElem(L,i,&e)
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
		return 0; /*�����ڵ�i�����ݽ��*/
	else	  /*���ڵ�i�����ݽ��*/
	{ 
		e=p->data;
		return 1;
	}
}


//////////////////////////////////////////////////////////
//7.��Ԫ��ֵ����
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
//8.��������Ԫ��
int ListInsert(LinkList *&L,int i,ElemType e)
{ 
	int j=0;
	LinkList *p=L,*s;
    while (j<i-1 && p!=NULL)     /*���ҵ�i-1�����*/
    { 
		j++;
	    p=p->next;
    }
	if (p==NULL)
		return 0; /*δ�ҵ�λ��Ϊi-1�Ľ��*/
	else	/*�ҵ�λ��Ϊi-1�Ľ��*p*/
	{   
		s=new LinkList;		/*�����½��*s*/
	    s->data=e;
	    s->next=p->next;  /*��*s���뵽*p֮��*/
	    p->next=s;
	    return 1;
	}
}




///////////////////////////////////////////////////////////////
//9.ɾ������Ԫ��
int ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	while (j<i-1 && p!=NULL)  /*���ҵ�i-1�����*/
	{ 
		j++;
		p=p->next;
	}
	if (p==NULL) 
		return 0; /*δ�ҵ�λ��Ϊi-1�Ľ��*/
	else	/*�ҵ�λ��Ϊi-1�Ľ��*p*/
	{    
		q=p->next;	   /*qָ��Ҫɾ���Ľ��*/
		if (q==NULL) 
			return 0;    /*�������ڵ�i�����,����0*/
		e=q->data;
	    p->next=q->next;	 /*�ӵ�������ɾ��*q���*/
	    delete q;       /*�ͷ�*q���*/
	    return 1;
	}
}



/////////////////////////////////////////
//����Ϊ����������

void main()
{
	LinkList *L1;
	cout<<"1.��ʼ��������:"<<endl;InitList(L1);

	cout<<"\n2.β�巨����:"<<endl;
	ElemType a[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"����ʧ��!";
	cout<<"\n3.�������Ԫ��Ϊ:";
	DispList(L1);


	cout<<"\n4.�õ�����ĳ���Ϊ:"<<ListLength(L1)<<endl;

	cout<<"\n5.�õ�����";
	if(ListEmpty(L1))
		cout<<"Ϊ��!"<<endl;
	else
		cout<<"��Ϊ��!"<<endl;


	cout<<"\n6.ȡԪ��";
	ElemType temp;cout<<"������ȡ��λ��:";int k;cin>>k;
	if(GetElem(L1,k,temp))
		cout<<"ȡֵ�ɹ����õ�����ĵ�"<<k<<"��Ԫ�ص�ֵΪ:"<<temp<<endl;
	else
		cout<<"ȡֵʧ�ܣ��������λ��"<<k<<"Խ��:"<<endl;

  
	cout<<"\n7.����Ԫ��:"<<endl<<"���������Ԫ�ص�ֵ:";cin>>temp;
	if(LocateElem(L1,temp))
		cout<<"���Ԫ��'"<<temp<<"'��λ��Ϊ:"<<LocateElem(L1,temp)<<endl;
	else
		cout<<"Ԫ��'"<<temp<<"'������."<<endl;
  
	cout<<"\n8.�ڵ�����ָ��λ�ò���Ԫ�� :"<<endl;
	cout<<"����������λ��:";cin>>k;
	cout<<"���������Ԫ�ص�ֵ:";cin>>temp;

	if(ListInsert(L1,k,temp))
		cout<<"����ɹ�"<<endl;
	else
		cout<<"����ʧ��!"<<endl;

	cout<<"\n9.���������"<<endl;
	DispList(L1);
	
	cout<<"\n10.ɾ��������ָ��λ�õ�Ԫ��"<<endl;
	cout<<"������ɾ����λ��:";cin>>k;
	if(ListDelete(L1,k,temp))
		cout<<"ɾ���ɹ���ɾ����Ԫ��Ϊ:"<<temp<<endl;
	else
		cout<<"ɾ��ʧ��!"<<endl;

	cout<<"\n11.���������"<<endl;
	DispList(L1);
	cout<<"\n12.�ͷŵ�����"<<endl;
	DestroyList(L1);

}



