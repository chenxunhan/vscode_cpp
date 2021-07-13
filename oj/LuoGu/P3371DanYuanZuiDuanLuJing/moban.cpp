
typedef pair<int, int> PII;// first存储距离，second存储节点编号
const int MAXN=1e4+5, MAXM=5e5+5;
int n, m;//n个点，m条边
int sid;//出发点
int cnt=0;//边集的大小,动态更新到最后为m

struct Edge{
    int to, w, next;
    //终点，边权，同起点的上一条边的编号
}edge[MAXM];//边集,注意双边需要*2

int head[MAXN];//head[i],表示以i为起点的最后一条边在边集数组的位置（编号）,结尾是-1(也可以设置0,就不用init)

void add_edge(int u, int v, int w)
{
    edge[cnt].to = v; //终点
    edge[cnt].w = w; //权值
    edge[cnt].next = head[u];
    head[u] = cnt++;//更新以u为起点上一条边的在边集的编号
}

int dist[MAXN];        // 存储所有点到1号点的距离
bool st[MAXN];     // 存储每个点的最短距离是否已确定

int dijkstra() {
    for(int i=0;i<MAXN;++i)
        dist[i]=INT_MAX;
    dist[sid] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, sid});      // first存储距离，second存储节点编号
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;//防止再算一次
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
