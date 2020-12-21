#include <bits/stdc++.h>
using namespace std;

int y, m, d;
int month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool isRunNian(int y) {
    if ((!(y % 4) && y % 100) || !(y % 400))
        return true;
    return false;
}

void add() {
    ++d;
    if (d > month[isRunNian(y)][m]) {
        d = 1;
        ++m;
    }
    if (m > 12) {
        m = 1;
        ++y;
    }
}

void print() {
    printf("%d-%02d-%02d\n", y, m, d);
}

int main() {
    int a;
    while (~scanf("%d%d%d%d", &y, &m, &d, &a)) {
        while (a--) {
            add();
        }
        print();
    }

    return 0;
}