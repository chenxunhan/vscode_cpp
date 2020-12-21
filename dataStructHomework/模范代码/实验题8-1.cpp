#include <iostream.h>
#include <iomanip.h>   //setw(3)��ʽ�����ʹ��,����������,�൱��C�����е�printf("%3d",n);

typedef int InfoType;
#define	MAXV 100				//��󶥵����
#define INF 32767				//INF��ʾ�� 

//���¶����ڽӾ�������
typedef struct 
{  	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct  				//ͼ�Ķ���
{  	int edges[MAXV][MAXV]; 		//�ڽӾ���
   	int n,e;   					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//ͼ���ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode           	//�ߵĽڵ�ṹ����
{	int adjvex;              	//�ñߵ��յ�λ��
   	struct ANode *nextarc; 		//ָ����һ���ߵ�ָ��
   	InfoType info;           	//�ñߵ������Ϣ,�������ڴ��Ȩֵ
} ArcNode;
typedef int Vertex;             //���
typedef struct Vnode      		//�ڽӱ�ͷ�ڵ������
{	Vertex data;            	//������Ϣ
    ArcNode *firstarc;     		//ָ���һ����(��һ���߱���ĵ�ַ)
} VNode;
typedef VNode AdjList[MAXV];	//AdjList���ڽӱ�����
typedef struct 
{	AdjList adjlist;         	//�ڽӱ�
    int n,e;                 	//ͼ�ж�����n�ͱ���e
} ALGraph;                   	//ͼ���ڽӱ�����

//-------------------------------------
//--------����Ȩͼ���㷨-----------------
//-------------------------------------
void MatToList(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j;
	ArcNode *p;
	G=new ALGraph;
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
			{   
			   	p=new ArcNode;	//p->adjvex=j;����һ���ڵ�*p
				
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}



void ListToMat(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]����ֵ0
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


void DispMat(MGraph g)		//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			cout<<"    "<<g.edges[i][j];
		cout<<endl;
	}
}


void DispAdj(ALGraph *G)	//����ڽӱ�G
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
//--------��Ȩͼ���㷨-----------------
//-------------------------------------
void MatToList1(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j;
	ArcNode *p;
	G=new ALGraph;
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)	//����һ����
			{   
			   	p=new ArcNode;	//����һ���ڵ�*p
				p->adjvex=j;
				p->info=g.edges[i][j];  //��Ȩֵ�����ڽӱ��еı�߽��
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}


void ListToMat1(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]����ֵ0
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
			g.edges[i][p->adjvex]=p->info;//��Ȩֵ�����ڽӾ����е���Ӧֵ
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}


void DispMat1(MGraph g)
//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				cout<<setw(3)<<"��"<<"  ";
			else
				cout<<setw(3)<<g.edges[i][j]<<"  ";
		cout<<endl;
	}
}


void DispAdj1(ALGraph *G)
//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;   //��ȡ��һ���߱���ĵ�ַ
		cout<<setw(3)<<i;           //������ı��
		while (p!=NULL)
		{
			cout<<"---->";
			cout<<p->adjvex<<","<<p->info;//�ֱ������߽���еĽ��ֵ��Ȩֵ
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
	g.n=6;g.e=10;			//����P311ͼ8.55�������ȨͼG���ڽӾ���
	for (int i=0;i<g.n;i++)	
		for (int j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	cout<<"����ͼG���ڽӾ���:"<<endl;
	DispMat1(g);

	G=new ALGraph;
	cout<<"ͼG���ڽӾ���ת�����ڽӱ�:"<<endl;
	MatToList1(g,G);
	DispAdj1(G);

	cout<<"ͼG���ڽӱ�ת�����ڽ�����:"<<endl;
	ListToMat1(G,g1);
	DispMat1(g1);
}