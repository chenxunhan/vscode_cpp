#include <bits/stdc++.h>
using namespace std;

long long m, n;
long long m1, n1;
long long g;
int main() {
    scanf("%lld%lld", &m, &n);
    g = __gcd(m, n);
    m1 = m / g, n1 = n / g;
    if ((m1 & 1) && (n1 & 1)) {
        printf("%lld", g);
        return 0;
    }
    if (((m1 & 1) && (!(n1 & 1))) || ((!(m1 & 1)) && (n1 & 1))) {
        printf("0");
    }
    return 0;
}
