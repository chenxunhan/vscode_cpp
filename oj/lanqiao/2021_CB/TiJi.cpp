#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n = 13082761331670030;
// ull n = ULLONG_MAX;
set<ull> v;
int main() {
    //9223372036854775807
    //20210418202104181
    // for (n = ULLONG_MAX - 2;n = ULLONG_MAX - 2; ++n) {
    v.clear();
    for (ull i = 1, sqrtn = sqrt(n); i <= sqrtn; ++i) {
        if (!(n % i)) {
            v.insert(i);
            v.insert(n / i);
        }
    }
    v.insert(n);
    printf("%llu:%d\n", n, v.size());
    // }
    return 0;
}
