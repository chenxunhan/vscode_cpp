#include <iostream.h>
#include <iomanip.h>   //setw(3)格式化输出使用,设置输出宽度,相当于C语言中的printf("%3d",n);

typedef int InfoType;
#define	MAXV 100				//最大顶点个数
#define INF 32767				//INF表示∞ 

//以下定义邻接矩阵类型
typedef struct 
{  	int no;						//顶点编号
	InfoType info;				//顶点其他信息
} VertexType;					//顶点类型
typedef struct  				//图的定义
{  	int edges[MAXV][MAXV]; 		//邻接矩阵
   	int n,e;   					//顶点数，边数
	VertexType vexs[MAXV];		//存放顶点信息
} MGraph;						//图的邻接矩阵类型

//以下定义邻接表类型
typedef struct ANode           	//边的节点结构类型
{	int adjvex;              	//该边的终点位置
   	struct ANode *nextarc; 		//指向下一条边的指针
   	InfoType info;           	//该边的相关信息,这里用于存放权值
} ArcNode;
typedef int Vertex;             //起点
typedef struct Vnode      		//邻接表头节点的类型
{	Vertex data;            	//顶点信息
    ArcNode *firstarc;     		//指向第一条边(第一个边表结点的地址)
} VNode;
typedef VNode AdjList[MAXV];	//AdjList是邻接表类型
typedef struct 
{	AdjList adjlist;         	//邻接表
    int n,e;                 	//图中顶点数n和边数e
} ALGraph;                   	//图的邻接表类型

//-------------------------------------
//--------不带权图的算法-----------------
//-------------------------------------
void MatToList(MGraph g,ALGraph *&G)
//将邻接矩阵g转换成邻接表G
{
	int i,j;
	ArcNode *p;
	G=new ALGraph;
	for (i=0;i<g.n;i++)					//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//检查邻接矩阵中每个元素
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		//邻接矩阵的当前元素不为0
			{   
			   	p=new ArcNode;	//p->adjvex=j;创建一个节点*p
				
				p->nextarc=G->adjlist[i].firstarc;		//将*p链到链表后
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}



void ListToMat(ALGraph *G,MGraph &g)
//将邻接表G转换成邻接矩阵g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]赋初值0
	   	for (j=0;j<G->n;j++)
			g.edges[i][j]=0;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=1;
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}


void DispMat(MGraph g)		//输出邻接矩阵g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			cout<<"    "<<g.edges[i][j];
		cout<<endl;
	}
}


void DispAdj(ALGraph *G)	//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		cout<<setw(3)<<i;
		while (p!=NULL)
		{
			cout<<setw(3)<<p->adjvex;
			p=p->nextarc;
		}
		cout<<endl;
	}
}
//-------------------------------------
//--------带权图的算法-----------------
//-------------------------------------
void MatToList1(MGraph g,ALGraph *&G)
//将邻接矩阵g转换成邻接表G
{
	int i,j;
	ArcNode *p;
	G=new ALGraph;
	for (i=0;i<g.n;i++)					//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//检查邻接矩阵中每个元素
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)	//存在一条边
			{   
			   	p=new ArcNode;	//创建一个节点*p
				p->adjvex=j;
				p->info=g.edges[i][j];  //将权值赋给邻接表中的表边结点
				p->nextarc=G->adjlist[i].firstarc;		//将*p链到链表后
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}


void ListToMat1(ALGraph *G,MGraph &g)
//将邻接表G转换成邻接矩阵g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]赋初值0
	   	for (j=0;j<G->n;j++)
			if (i==j)
				g.edges[i][j]=0;
			else
				g.edges[i][j]=INF;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;//将权值赋给邻接矩阵中的相应值
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}


void DispMat1(MGraph g)
//输出邻接矩阵g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				cout<<setw(3)<<"∞"<<"  ";
			else
				cout<<setw(3)<<g.edges[i][j]<<"  ";
		cout<<endl;
	}
}


void DispAdj1(ALGraph *G)
//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;   //获取第一个边表结点的地址
		cout<<setw(3)<<i;           //输出起点的编号
		while (p!=NULL)
		{
			cout<<"---->";
			cout<<p->adjvex<<","<<p->info;//分别输出表边结点中的结点值与权值
			p=p->nextarc;
		}
		cout<<"^"<<endl;
	}
}


void main()
{
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	g.n=6;g.e=10;			//建立P311图8.55中有向带权图G的邻接矩阵
	for (int i=0;i<g.n;i++)	
		for (int j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	cout<<"有向图G的邻接矩阵:"<<endl;
	DispMat1(g);

	G=new ALGraph;
	cout<<"图G的邻接矩阵转换成邻接表:"<<endl;
	MatToList1(g,G);
	DispAdj1(G);

	cout<<"图G的邻接表转换成邻接邻阵:"<<endl;
	ListToMat1(G,g1);
	DispMat1(g1);
}