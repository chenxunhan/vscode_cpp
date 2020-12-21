#include <bits/stdc++.h>
using namespace std;

bool used[10];

void save(int n) {
    while (n) {
        int use = n % 10;
        used[use] = 1;
        n /= 10;
    }
}

int sum() {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += used[i];
    }
    return sum;
}

int main() {
    int i = 0;
    bool isok = 0;
    while (!isok) {
        memset(used, 0, sizeof(used));
        save(i * i);
        save(i * i * i);
        ++i;
        if (sum() == 10) {
            isok = 1;
        }
    }
    cout << i - 1;

    return 0;
}