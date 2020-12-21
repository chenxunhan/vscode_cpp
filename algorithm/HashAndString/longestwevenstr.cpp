#include <bits/stdc++.h>
#define N 52
using namespace std;
int main() {
    char s[1020];
    while (~scanf("%s", &s)) {
        int cord[N] = {0};
        for (int i = 0; i < strlen(s); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ++cord[s[i] - 'a'];
                continue;
            }
            ++cord[s[i] - 'A' + 26];
        }
        int sum = 0, hasji = 0;
        for (int i = 0; i < N; ++i) {
            if (cord[i] & 1) {
                hasji = 1;
                sum += cord[i] - 1;
                continue;
            }
            sum += cord[i];
        }
        printf("%d\n", sum + hasji);
    }
    return 0;
}