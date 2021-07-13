
typedef pair<int, int> PII;// first�洢���룬second�洢�ڵ���
const int MAXN=1e4+5, MAXM=5e5+5;
int n, m;//n���㣬m����
int sid;//������
int cnt=0;//�߼��Ĵ�С,��̬���µ����Ϊm

struct Edge{
    int to, w, next;
    //�յ㣬��Ȩ��ͬ������һ���ߵı��
}edge[MAXM];//�߼�,ע��˫����Ҫ*2

int head[MAXN];//head[i],��ʾ��iΪ�������һ�����ڱ߼������λ�ã���ţ�,��β��-1(Ҳ��������0,�Ͳ���init)

void add_edge(int u, int v, int w)
{
    edge[cnt].to = v; //�յ�
    edge[cnt].w = w; //Ȩֵ
    edge[cnt].next = head[u];
    head[u] = cnt++;//������uΪ�����һ���ߵ��ڱ߼��ı��
}

int dist[MAXN];        // �洢���е㵽1�ŵ�ľ���
bool st[MAXN];     // �洢ÿ�������̾����Ƿ���ȷ��

int dijkstra() {
    for(int i=0;i<MAXN;++i)
        dist[i]=INT_MAX;
    dist[sid] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, sid});      // first�洢���룬second�洢�ڵ���
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;//��ֹ����һ��
        st[ver] = true;
        for (int i = head[ver]; i; i = edge[i].next) {
            int j = edge[i].to;
            if (dist[j] > distance + edge[i].w) {
                dist[j] = distance + edge[i].w;
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&sid);
    for(int i=1,u,v,w;i<=m;++i){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}
