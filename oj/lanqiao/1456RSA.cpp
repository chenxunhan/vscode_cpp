#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll ksc(ll x, ll y, ll mod) {
    return (x * y - (ll)((long double) x / mod * y) * mod + mod) % mod;
}

ll fast_pow(ll x, ll k, ll p) {
    ll ret = 1;
    x %= p;
    while (k > 0) {
        if (k & 1) ret = ksc(ret, x, p);
        k >>= 1;
        x = ksc(x, x, p);
    }
    return ret;
}
ll phi(ll n) {
    ll ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1) {
        ret = ret / n * (n - 1);
    }
    return ret;
}
ll get_p(ll n) {
    ll i;
    for (i = 3; i <= n && (n % i != 0); ++i, ++i) {
    }
    return i;
}
int main() {
    ll n = (ll) 1001733993063167141;
    ll d = 212353;
    ll C = 20190324;
    ll p, q, e, k;
    printf("n=%lld\n", n);
    p = get_p(n);
    q = n / p;
    printf("p=%lld, q=%lld\n", p, q);
    k = (p - 1) * (q - 1);
    printf("k=(p-1)*(q-1)=%lld\n", k);
    printf("phi(k)=%lld\n", phi(k));
    e = fast_pow(d, phi(k) - 1, k);
    printf("e=d^(phi(k)-1)=%lld (mod k)\n", e);
    printf("d*e=%lld (mod k)\n", ksc(d, e, k));
    ll X = fast_pow(C, e, n);
    printf("X=C^e (mod n)= %lld\n", X);
    return 0;
}