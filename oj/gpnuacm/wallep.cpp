//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    while (~scanf("%d", &n)) {
        sum = 0;
        while (n) {
            sum += (n & 1);
            n >>= 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
