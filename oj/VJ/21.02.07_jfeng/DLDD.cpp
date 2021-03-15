#include <bits/stdc++.h>

using namespace std;

struct Node {
    int weight, degree = 0;
} nodes[100005];

bool comp(Node a, Node b) { return a.weight > b.weight; }

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n;
        scanf("%d", &n);

        long long sum(0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &nodes[i].weight);
            nodes[i].degree = 0;
            sum += nodes[i].weight;
        }
        for (int i(1), head, tail; i <= n - 1; ++i) //n-1
        {
            scanf("%d%d", &head, &tail);
            ++nodes[head].degree;
            ++nodes[tail].degree;
        }

        sort(nodes + 1, nodes + n + 1, comp);

        int times(n - 1 - 1);
        int posit(1);
        // printf("   =");
        printf("%lld ", sum);
        for (int i(0); i < times; ++i) {
            while (1) {
                if (nodes[posit].degree >= 2) {
                    break;
                }
                ++posit;
            }
            sum += nodes[posit].weight;
            --nodes[posit].degree;
            printf("%lld ", sum);
        }
        putchar('\n');
    }

    return 0;
}
