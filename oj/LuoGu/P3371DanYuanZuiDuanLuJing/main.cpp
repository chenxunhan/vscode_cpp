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
        if (vis[nowNode.idx]) { //��ֹ����һ��
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
�ĵã�
Dijkstra
ѡȡ����Ľ��ʱ����С�����Ż�������Ž��, ��֤�ó����Ķ�������Ľ��
�������Ǳ�ʱ����һ���ߵ�����head[nodeIdx] ָ��ߵ����һ��idx,
edge[i].nextָ����һ��edge��idx
Ҫ��ס˼ά��ı�����
Ҫ��ס�㷨��ͼ��
ע��dijkstraֻ�ܷǸ���
ע������еĽڵ�����disΪ����



priority_queue�Ķ�ͷ���ұ߾�����
����С����greater
�����less
eg. priority_queue <int ,vector<int>,greater<int> > q;

greater<> ���������� >
less<> �ǽ������� <