#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

vector<pair<char, int> > smapv;

struct cp {
    bool operator()(const char &a, const char &b) {
        return a < b;
    }
};

map<char, int, cp> m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char c;
    while (~scanf("%c", &c) && c != '#') {
        if ('a' <= c && c <= 'z')
            ++m[c];
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (m.find(c) != m.end())
        //if(m.count(c)>0) 
            cout << c << " " << m.at(c) << endl;
        else
            cout << c << " " << 0 << endl;
    }
    return 0;
}

