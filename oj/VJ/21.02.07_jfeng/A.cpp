// ��������YES
// ����ż��
//     ��2^?  NO
//     ����2^?  YES

#include <bits/stdc++.h>
using namespace std;

int n;
long long t, m;
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &t);
        if (t & 1) {
            puts("YES");
            continue;
        }
        m = log2(t);
        if (pow(2, m) == t) {
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}