#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+5,MAXM=1e5+5;
int n, m;//n���㣬m����
int cnt=0;//�߼��Ĵ�С,��̬���µ����Ϊm

struct Edge{
    int to, next;
}edge[MAXM*2];//�߼�,ע��˫����Ҫ*2

int head[MAXN];

void add_edge(int u, int v){
    edge[cnt].to = v; //�յ�
    edge[cnt].next = head[u];
    head[u] = cnt++;//������uΪ�����һ���ߵ��ڱ߼��ı��
}

bool coled[MAXN]={0};//�Ƿ������,��Ⱦ��ɫ
bool col[MAXN]={0};//ÿһ�����Ⱦɫ
int bwnum[2];//�ڰ�����Ⱦɫ���Եĵ���,bwnum['0/1']����'��/��'Ⱦɫ������,Ҳ���Ƕ���ͼ����part��part�ĵ�����

//�ж�nodeΪid�Ľ�����ڵ�ͼ�Ƿ��Ϊ����ͼ,��main����ʱ��color��ʼ=0
bool dfs(int node,bool color=0){
    if(coled[node])//����ѱ�Ⱦ��ɫ
    {
        if(col[node]==color)return true;//�������ԭ������ɫ��������
        return false;//��ԭ������ɫ���������˳�ͻ��������
    }
    coled[node]=true;//��¼
    bwnum[col[node]=color]++;//��һ����ɫ�ĸ�����1���Ҵ˵����ɫҲ��¼����
    bool tf=true;//�Ƿ����
    for(int i=head[node];i&&tf;i=edge[i].next)//������
    {
        tf=tf&&dfs(edge[i].to,!color);//�Ƿ���Լ���Ⱦɫ
    }
    return tf;//�����Ƿ����Ⱦɫ
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;++i) {
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);//���������ߣ����Դ�����
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(coled[i]) continue;//����˵��ѱ�����Ϊһ���Ѿ�������������ͼ�������ظ�����
        bwnum[0]=bwnum[1]=0;//��ʼ��
        if(!dfs(i)){//�������Ⱦɫ
            printf("Impossible");
            return 0;//ֱ������
        }
        ans+=min(bwnum[0],bwnum[1]);//����С��һ��
    }
    printf("%d",ans);//�����
    return 0;
}