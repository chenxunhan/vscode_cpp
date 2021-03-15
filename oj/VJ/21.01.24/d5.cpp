#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

const int N = 2e5 + 10;

struct Node {
    string id;
    int level;
    int diff;
} node[N];

inline bool cmp(Node a, Node b)
{
    if (a.diff != b.diff)
        return a.diff < b.diff;
    return a.level < b.level;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n,k; cin >> n >> k;
    map<string, int> m, sel;
    for (int i=0; i<n; ++i) {
        string s; node[i].id.resize(30);
        cin >> s >> node[i].diff;
        if (s[s.size() - 1] == '1' || s[s.size() - 1] == '2') {
            node[i].id = s.substr(0, s.size() - 1);
            if (s[s.size() - 1] == '1') {
                node[i].level = 1;
            } else {
                node[i].level = 2;
                m[node[i].id] = node[i].diff;
            }
        } else
            node[i].id = s, node[i].level = 0;
     }
    sort(node, node+n, cmp);
    
    int cnt = 0;
    long long ans = 0;
    
    for (int i = 0; cnt < k; ++i) {
        if (node[i].level < 2) {
            ++cnt;
            ans += node[i].diff;
            sel[node[i].id] = 1;
            if (node[i].level == 1 && node[i].diff > m[node[i].id] && cnt <= k-1)
                ++cnt, ans += m[node[i].id];
        } else if (sel[node[i].id] == 1)
            ans += node[i].diff, ++cnt;
    }
    cout << ans;
    return 0;
}