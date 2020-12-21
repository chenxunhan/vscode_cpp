#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    while (~scanf("%d", &n)) {
        n *= 3, sum = 0;
        while (n >= 3) {
            sum += n / 3;
            n = n / 3 + n % 3;
        }
        printf("%d\n", sum);
    }

    return 0;
}