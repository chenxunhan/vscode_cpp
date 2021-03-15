#include <cmath>
#include <cstdio>

long long x2x(long long x) {
    return x * x + x;
}

bool ok(long long t) {
    long long ot = t;
    t = sqrt(t);
    // if(t==(1+2+3+...+x)){
    //     return 1;
    // }
    while (t * t + t > ot) {
        --t;
    }
    return (t * t + t == ot);
}

int main() {
    long long n, t;
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld", &t);
        if (ok(2 * (t - 1))) {
            printf("1 ");
            continue;
        }
        printf("0 ");
    }
    return 0;
}