#include <bits/stdc++.h>
using namespace std;
int a[8005] = {0};
// int dp[2][400005] = {0};
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }
    cout << "sum:" << sum << endl;
    sort(a, a + n);
    int limit = sum / 2 + (sum & 1);
    int l = 0;

    cout << "li:" << limit << endl;
    for (int i = 0; l + a[i] <= limit; ++i) {
        l += a[i];
    }
    cout << "l:" << l << endl;
    // for (int ni = 1; ni <= n; ++ni) {
    //     for (int li = 1; li <= limit; ++li) {
    //         dp[ni & 1][li] = max(li >= a[ni] ? dp[!(ni & 1)][li - a[ni]] + a[ni] : 0, dp[!(ni & 1)][li]);
    //         // printf("%4d", dp[ni & 1][li]);
    //     }
    //     // putchar('\n');
    // }
    // printf("last:%d\n", dp[n & 1][limit]);
    printf("%d", abs(sum - l - l));
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int a[8005] = {0};
int dp[2][400005] = {0};
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }
    int limit = sum / 2 + (sum & 1);
    // cout << "li:" << limit << endl;
    for (int ni = 1; ni <= n; ++ni) {
        for (int li = 1; li <= limit; ++li) {
            dp[ni & 1][li] = max(li >= a[ni] ? dp[!(ni & 1)][li - a[ni]] + a[ni] : 0, dp[!(ni & 1)][li]);
            // printf("%4d", dp[ni & 1][li]);
        }
        // putchar('\n');
    }
    // printf("last:%d\n", dp[n & 1][limit]);
    printf("%d", abs(sum - 2 * dp[n & 1][limit]));
    return 0;
}
*/