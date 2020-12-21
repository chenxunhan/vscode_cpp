#include <bits/stdc++.h>
using namespace std;

int randRange(int a, int b) {
    return a + rand() % (b - a + 1);
}

bool randBG() {
    return rand() % 2;
}

void randChip(bool a[], int n) {
    //int num_good = randRange((n / 2) + 1, n), num_bad = n - num_good;
    int num_good = n / 2, num_bad = n - num_good;
    int a_num_good = 0, a_num_bad = 0;
    for (int i = 0; i < n; ++i) {
        if (a_num_good < num_good && a_num_bad < num_bad) {
            a[i] = randBG();
            (a[i] == 1) ? (++a_num_good) : (++a_num_bad);
        } else {
            bool lackGood = (a_num_good < num_good ? 1 : 0);
            for (; i < n; ++i) {
                a[i] = lackGood;
            }
            break;
        }
    }
}

void printa(bool a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
    }
}

int main() {
    srand(time(NULL));
    bool a[100] = {0}, n;
    while (~scanf("%d", &n)) {
        randChip(a, n);
        printa(a, n);
        cout << endl;
    }

    return 0;
}