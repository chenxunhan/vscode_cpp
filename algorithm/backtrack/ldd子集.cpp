#include <bits/stdc++.h>
using namespace std;

int num[10], choice[10] = {0}, n, posit;

void pr() {
    for (int j = 0; j < n; j++) {
        if (choice[j]) printf("%d ", num[j]);
    }
    putchar('\n');
}

void selec() {
    for (int j = posit; j < n; j++) {
        choice[j] = 1;
        posit = j + 1;
        pr();
        selec();
        choice[j] = 0;
    }
}

int main() {
    int j;
    char in;
    while (~scanf("%d", &n)) {
        putchar('\n');
        posit = 0;
        for (j = 0; j < n; j++) {
            in = getchar();
            while (in > '9' || in < '0')
                in = getchar();
            num[j] = in - '0';
        }
        sort(num, num + n);
        selec();
    }

    return 0;
}