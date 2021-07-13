#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN =1e6+5;
int que[MAXN], ans[MAXN];

int n, k;

void getmin() {
    int head = 0, tail = 0;//队头 队尾
    for (int i = 1; i < k; ++i) {
        while (head <= tail && ans[que[tail]] >= ans[i])
            --tail;
        que[++tail] = i;
    }
    for (int i = k; i <= n; ++i) {
        while (head <= tail && ans[que[tail]] >= ans[i])
            --tail;
        que[++tail] = i;
        while (que[head] <= i - k)
            ++head;
        printf("%d ", ans[que[head]]);
    }
}

void getmax() {
    int head = 0, tail = 0;//队头 队尾
    for (int i = 1; i < k; ++i) {
        while (head <= tail && ans[que[tail]] <= ans[i])
            --tail;
        que[++tail] = i;
    }
    for (int i = k; i <= n; ++i) {
        while (head <= tail && ans[que[tail]] <= ans[i])
            --tail;
        que[++tail] = i;
        while (que[head] <= i - k)
            ++head;
        printf("%d ", ans[que[head]]);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", ans+i);
    getmin();
    printf("\n");
    getmax();
    printf("\n");
    return 0;
}