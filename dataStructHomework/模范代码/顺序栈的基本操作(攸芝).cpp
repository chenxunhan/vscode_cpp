#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int top;
}SqStack;
/*��ʼ��ջs*/
void InitStack(SqStack * &s)                
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
/*����ջs*/
void DestroyStack(SqStack * &s)              
{
	free(s);
}
/*��ջs�ĳ���*/
int StackLength(SqStack *s)              
{
	return(s->top+1);
}
/*�ж�ջs�Ƿ�Ϊ��*/
int StackEmpty(SqStack *s)           
{
	return(s->top==-1);
}
/*��ջ*/
int Push(SqStack * &s,ElemType e)                
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
/*��ջ*/
int Pop(SqStack * &s,ElemType &e)                
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
/*ȡջ��Ԫ��*/
int GetTop(SqStack *s,ElemType &e)        
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
/*��ջ����ջ�����Ԫ��*/
void DispStack(SqStack * s)      
{
	int i;
	for(i=s->top;i>=0;i--)
	printf("%c",s->data[i]);
	printf("\n");
}

int main()
{	
	char e;
    SqStack *s;
	printf("(1)��ʼ��ջs\n");
	InitStack(s);

	printf("(2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	StackEmpty(s);

	printf("(3)���ν�ջԪ��A,B,C,D,E\n");
	ElemType a[5]={'A','B','C','D','E'};
	for(int i=0;i<5;i++)
	{
		if(!Push(s,a[i]))
			printf("����ʧ�ܣ�\n");
	}

	printf("(4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	
	printf("(5)�����ջ����:");
	while(!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c",e);
	}
	printf("\n");

	printf("(6)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));

	printf("(7)�ͷ�ջ\n");
	DestroyStack(s);
}
