#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int top;
}SqStack;
/*初始化栈s*/
void InitStack(SqStack * &s)                
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
/*销毁栈s*/
void DestroyStack(SqStack * &s)              
{
	free(s);
}
/*求栈s的长度*/
int StackLength(SqStack *s)              
{
	return(s->top+1);
}
/*判断栈s是否为空*/
int StackEmpty(SqStack *s)           
{
	return(s->top==-1);
}
/*进栈*/
int Push(SqStack * &s,ElemType e)                
{
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
/*出栈*/
int Pop(SqStack * &s,ElemType &e)                
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
/*取栈顶元素*/
int GetTop(SqStack *s,ElemType &e)        
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
/*从栈顶到栈底输出元素*/
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
	printf("(1)初始化栈s\n");
	InitStack(s);

	printf("(2)栈为%s\n",(StackEmpty(s)?"空":"非空"));
	StackEmpty(s);

	printf("(3)依次进栈元素A,B,C,D,E\n");
	ElemType a[5]={'A','B','C','D','E'};
	for(int i=0;i<5;i++)
	{
		if(!Push(s,a[i]))
			printf("插入失败！\n");
	}

	printf("(4)栈为%s\n",(StackEmpty(s)?"空":"非空"));
	
	printf("(5)输出出栈序列:");
	while(!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c",e);
	}
	printf("\n");

	printf("(6)栈为%s\n",(StackEmpty(s)?"空":"非空"));

	printf("(7)释放栈\n");
	DestroyStack(s);
}
