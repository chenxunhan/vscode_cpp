#include <bits/stdc++.h>
using namespace std;
void Divide(int n, int MIN_DIV);
int DivSum(int n);

int chose[100] = {0};
int sum(0);
int main() {
    printf("请输入被划分的数：");
    int n;
    scanf("%d", &n);
    double time0 = clock();
    Divide(n, n);
    printf("%d\n", sum);
    printf("%lf", (double) ((clock() - time0) / CLOCKS_PER_SEC));
    return 0;
}

void Divide(int n, int MIN_DIV) {
    //拆分完则输出
    if (!n) {
        for (int i = 1; i < chose[0]; ++i)
            printf("%d+", chose[i]);
        printf("%d\n", chose[chose[0]]);
        sum += 1;
        return;
    }
    //回溯
    ++chose[0];
    for (int i = (n < MIN_DIV ? n : MIN_DIV); i > 0; --i) {
        chose[chose[0]] = i;
        Divide(n - i, i);
    }
    --chose[0];
    return;
}
