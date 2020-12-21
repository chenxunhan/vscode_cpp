#include <stdio.h>

int main() {
    int a, b, c;
    // while (~scanf("%d%d%d", &a, &b, &c))
    {
        scanf("%d%d%d", &a, &b, &c);
        int time = c / 5 + (c % 5 != 0);
        double p = 1;
        if (time > b) {
            printf("1");
        } else {
            for (int i = 0; i < time && i < b; ++i) {
                p *= (double) (b - i) / (double) (a - i);
            }
            if ((double) (1 - p) == (double) ((int) (1 - p))) {
                printf("%.0lf", 1 - p);
            } else
                printf("%.9lf", 1 - p);
        }
    }
    return 0;
}