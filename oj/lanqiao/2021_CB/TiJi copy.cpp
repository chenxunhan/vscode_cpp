#include <bits/stdc++.h>
#include<climits>
using namespace std;


 long long n = 2021041820210418;
set<long long> v;
set<Ele> e;
int ans = 0;
int main() {
    // n = 4;
    for (int i = 1, sqrtn = sqrt(n); i <= sqrtn; ++i) {
        if (!(n % i)) {
            v.insert(i);
            v.insert(n / i);
        }
    }
    v.insert(n);
    for (auto i = v.begin(); i != v.end(); ++i)
        printf("%lld ", *i);

    printf("\n%d\n", v.size());
    for (auto i = v.begin(); i != v.end(); ++i) {
        for (auto j = v.begin(); j != v.end(); ++j) {
            for (auto k = v.begin(); k != v.end(); ++k) {
                if ((*i) * (*j) * (*k) == n) {
                    e.insert(Ele{*i, *j, *k});
                }
            }
        }
    }
    for (auto i = e.begin(); i != e.end(); ++i) {
        // printf("%lld %lld %lld\n", (*i).a, (*i).b, (*i).c);
    }
    printf("%d", e.size());
    return 0;
}
