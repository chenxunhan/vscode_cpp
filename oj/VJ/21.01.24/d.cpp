#include<iostream>
#include<map>
using namespace std;

const int N = 2e5 + 10;

struct {
    string id;
    int level;
    int diff;
    int pre;
} node[N];

int main()
{
    //sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n,k; 
	cin >> n >> k;
    map<string, int> m;
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s >> node[i].diff;
        if (s[s.size() - 1] == '1' || s[s.size() - 1] == '2') {
            node[i].id = s.substr(0, s.size() - 1);
            if (m[node[i].id]) {
                node[i].level = 2;
                node[i].pre = m[node[i].id];
            } else {
                node[i].level = 1;
                node[i].pre = -1;
            }
        } else {
            node[i].level = 0;
            node[i].pre = -1;
        }
    }
    
    
    return 0;
}
