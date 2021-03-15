#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll a[maxn], dp[maxn];
int main() {
    io();
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[0] += 1; //[2,i]、[3，i]、[4，i]、...、[i，i]
        for (int j = k; j >= a[i]; j--)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        ans = (ans + dp[k]) % mod; //前i个数的和为K的数量
    }
    cout << ans << endl;
    return 0;
}