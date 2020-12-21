#include <bits/stdc++.h>
using namespace std;

int sum = 0;
void f(int pos, int num) {
    if (pos == 14 && num == 13) {
        ++sum;
        return;
    }
    if (pos > 14 || num > 13) {
        return;
    }
    for (int i = 0; i <= 4; ++i) {
        f(pos + 1, num + i);
    }
}

int main() {
    f(1, 0);
    printf("%d", sum);
    return 0;
}