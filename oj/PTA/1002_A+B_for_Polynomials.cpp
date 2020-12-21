
#include <bits/stdc++.h>
using namespace std;

double coes[1005] = {0};
bool coesUsed[1005] = {0};
int main() {
    int lineN;
    int exp;
    double coe;
    int resN = 0;
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &lineN);
        while (lineN--) {
            scanf("%d %lf", &exp, &coe);
            coes[exp] += coe;
            if (!coesUsed[exp]) {
                coesUsed[exp] = 1;
                ++resN;
            }
        }
    }
    printf("%d", resN);
    for (int i = 1004; i >= 0; --i) {
        if (coes[exp]!=0) {
            coes[i] = ((double) ((int) (coes[i] * 10))) / 10;
            printf(" %d %.1lf", i, coes[i]);                        
        }
    }
    putchar('\n');
    return 0;
}