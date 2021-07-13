#include <bits/stdc++.h>
using namespace std;

// const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;
const int MAXN = 1e4 + 5, MAXM = 5e5 + 5;

int nodeNum, edgeNum, startIdx;
int head[MAXM], dis[MAXN];
bool vis[MAXN];

int edgeIdx = 0;
struct Edge {
    int toIdx;
    int dis;
    int linkListNext;
} edge[MAXM];
struct Node {
    int idx;
    int dis;
    // bool operator<(const Node &newNode) const {
    //     return newNode.dis < dis;
    // }
    bool operator>(const Node &newNode) const {
        return dis > newNode.dis;
    }
};
priority_queue<Node, vector<Node>, greater<Node> > q;

void addEdge(int fromIdx, int toIdx, int dis) {
    ++edgeIdx;
    edge[edgeIdx].toIdx = toIdx;
    edge[edgeIdx].dis = dis;
    edge[edgeIdx].linkListNext = head[fromIdx];
    head[fromIdx] = edgeIdx;
}

void dij() {
    dis[startIdx] = 0;
    q.push((Node){startIdx, 0});
    while (!q.empty()) {
        Node nowNode = q.top();
        q.pop();
        if (vis[nowNode.idx]) { //防止再算一次
            continue;
        }
        vis[nowNode.idx] = 1;
        for (int i = head[nowNode.idx]; i; i = edge[i].linkListNext) {
            if (dis[edge[i].toIdx] > edge[i].dis + dis[nowNode.idx]) {
                dis[edge[i].toIdx] = edge[i].dis + dis[nowNode.idx];
                q.push((Node){edge[i].toIdx, dis[edge[i].toIdx]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> nodeNum >> edgeNum >> startIdx;
    for (int i = 1; i <= nodeNum; ++i) {
        dis[i] = INT_MAX;
    }
    for (int i = 1, fromIdx, toIdx, dis; i <= edgeNum; ++i) {
        cin >> fromIdx >> toIdx >> dis;
        addEdge(fromIdx, toIdx, dis);
    }
    dij();
    for (int i = 1; i <= nodeNum; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}

P3371DanYuanZuiDuanLuJing
心得：
Dijkstra
选取最近的结点时候：用小根堆优化，堆里放结点, 保证拿出来的都是最近的结点
当输入是边时，用一个边的链表，head[nodeIdx] 指向边的最后一个idx,
edge[i].next指向下一个edge的idx
要记住思维里的边链表
要记住算法的图解
注意dijkstra只能非负边
注意给所有的节点设置dis为无穷



priority_queue的队头在右边就离谱
所以小根堆greater
大根堆less
eg. priority_queue <int ,vector<int>,greater<int> > q;

greater<> 是升序，重载 >
less<> 是降序，重载 <