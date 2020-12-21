#include <bits/stdc++.h>
using namespace std;

const int MAXVERTEXSIZE = 20;
const int MAXEDGESIZE = 100;

struct MatGraph {
    int edge_weight[MAXVERTEXSIZE][MAXVERTEXSIZE];
    int vertex_number, edge_number;
};

void CreateMatGraph(MatGraph &MatGraph_,
                    const int edge_weight_[MAXVERTEXSIZE][MAXVERTEXSIZE],
                    const int &vertex_number_,
                    const int &edge_number_) {
    MatGraph_.edge_number = edge_number_, MatGraph_.vertex_number = vertex_number_;
    for (auto i = 0; i < vertex_number_; ++i)
        for (auto j = 0; j < vertex_number_; j++)
            MatGraph_.edge_weight[i][j] = edge_weight_[i][j];
}

void DisplyMatGraph(MatGraph &MatGraph_) {
    for (int i = 0, t; i < MatGraph_.vertex_number; ++i) {
        for (int j = 0; j < MatGraph_.vertex_number; ++j) {

            if ((t = MatGraph_.edge_weight[i][j]) == INT_MAX) {
                printf("  ∞");
            } else {
                printf("%3d", t);
            }
        }
        putchar('\n');
    }
}

void Prim(MatGraph MatGraph_, int vertex_) {
    int colsest_V_vertex[MatGraph_.vertex_number];
    int min_weight_V[MatGraph_.vertex_number];
    for (int i = 0; i < MatGraph_.vertex_number; ++i) {
        colsest_V_vertex[i] = vertex_;
        min_weight_V[i] = MatGraph_.edge_weight[i][vertex_];
    }
    int current_minweight_V, current_closestV_vertex;
    for (int added_V_number = 1;
         added_V_number < MatGraph_.vertex_number; ++added_V_number) {
        //遍历U-V中所有顶点，查看谁离V最近，把他加入V，输出加入了哪条边，权值和顶点
        current_minweight_V = INT_MAX;
        for (int i = 0; i < MatGraph_.vertex_number; ++i) {
            if (min_weight_V[i] != 0 && min_weight_V[i] < current_minweight_V) {
                current_minweight_V = min_weight_V[i];
                current_closestV_vertex = i;
            }
        }
    }
    printf("(%d--%d):%d\n", current_closestV_vertex,
           colsest_V_vertex[current_closestV_vertex],
           min_weight_V[current_closestV_vertex]);
    min_weight_V[current_closestV_vertex] = 0;
    colsest_V_vertex[current_closestV_vertex] = current_closestV_vertex;

    //遍历U-V中所有顶点，看他到新加入点的距离是不是小于原来的到V的距离，是的话更新
    for (int i = 0; i < MatGraph_.vertex_number; ++i) {
        if (min_weight_V[i] != 0) {
            if (MatGraph_.edge_weight[i][current_closestV_vertex] < min_weight_V[i]) {
                min_weight_V[i] = MatGraph_.edge_weight[i][current_closestV_vertex];
                colsest_V_vertex[i] = current_closestV_vertex;
            }
        }
    }
}

int main() {
    int edge_weight_[MAXVERTEXSIZE][MAXVERTEXSIZE] = {{0, 6, 1, 5, INT_MAX, INT_MAX},
                                                      {6, 0, 5, INT_MAX, 3, INT_MAX},
                                                      {1, 5, 0, 5, 6, 4},
                                                      {5, INT_MAX, 5, 0, INT_MAX, 2},
                                                      {INT_MAX, 3, 6, INT_MAX, 0, 6},
                                                      {INT_MAX, INT_MAX, 4, 2, 6, 0}};

    MatGraph MatGraph_;
    CreateMatGraph(MatGraph_, edge_weight_, 6, 10);
    cout << "矩阵图:\n";
    DisplyMatGraph(MatGraph_);
    Prim(MatGraph_, 0);
}