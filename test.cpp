#include <stdio.h>
#include <string.h>
int main() {
    void f2(char *p);
    int p[10], *q = p, a;
    printf("string:");
    for (a = 0; a < 10; a++)
        scanf("%c", p);
    printf("\n");
    q = p;
    f2(q);
}

void f2(char *p) {
    char *q;
    int i, n, m = 0;
    n = strlen(p);
    for (i = 0; i < n; i++) {
        if (p[i] != 'a') {
            *q = *(p + i);
            q++;
            m++;
        }
        for (i = 0; i < m; i++) {
            printf("%c", *q);
        }
    }
}