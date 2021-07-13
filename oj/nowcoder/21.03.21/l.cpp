#include <bits/stdc++.h>
using namespace std;

// const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;
const int MAXN = 505, MAXM = 500 * (500 - 1) / 2 + 5;

int nodeNum, edgeNum, oilNum, oilDis, startIdx = 1;
bool isoil[MAXN] = {0};
int head[MAXM];

int edgeIdx = 0;
struct Edge {
    int toIdx;
    int dis;
    int linkListNext;
} edge[MAXM];

struct Choice {
    int dis = INT_MAX;
    int restOil = 0;
    int vis = 0;
} choice[MAXN];//res

struct Node {
    int idx;
    int dis;
    int restOil;
    bool isOil() {
        return isoil[idx];
    }
    bool operator>(const Node &newNode) const {
        return dis > newNode.dis;
    }
};
priority_queue<Node, vector<Node>, greater<Node>> q;

void addEdge(int fromIdx, int toIdx, int dis) {
    ++edgeIdx;
    edge[edgeIdx].toIdx = toIdx;
    edge[edgeIdx].dis = dis;
    edge[edgeIdx].linkListNext = head[fromIdx];
    head[fromIdx] = edgeIdx;
}

void dij() {
    choice[startIdx].dis = 0;
    q.push((Node){startIdx, 0, oilDis});
    while (!q.empty()) {
        Node nowNode = q.top();
        q.pop();
        if (choice[nowNode.idx].vis&&nowNode.restOil<=choice[nowNode.idx].restOil) { //·ÀÖ¹ÔÙËãÒ»´Î
            continue;
        }
        choice[nowNode.idx].vis = 1;
        for (int i = head[nowNode.idx]; i; i = edge[i].linkListNext) {
            if (choice[edge[i].toIdx].dis > edge[i].dis + choice[nowNode.idx].dis
            && choice[nowNode.idx].restOil-edge[i].dis>=0) {
                choice[edge[i].toIdx].dis = edge[i].dis + choice[nowNode.idx].dis;
                q.push((Node){edge[i].toIdx, choice[edge[i].toIdx].dis,choice[nowNode.idx].restOil-edge[i].dis});
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &nodeNum, &edgeNum, &oilNum, &oilDis);
    for (int i = 1, t; i <= oilNum; ++i) {
        scanf("%d", &t);
        isoil[t] = 1;
    }
    for (int i = 1, fromIdx, toIdx, dis; i <= edgeNum; ++i) {
        scanf("%d%d%d", &fromIdx, &toIdx, &dis);
        addEdge(fromIdx, toIdx, dis);
    }
    dij();
    if (choice[nodeNum].dis == INT_MAX) {
        puts("stuck");
    } else {
        printf("%d\n", choice[nodeNum].dis);
    }

    return 0;
}
