#include <bits/stdc++.h>
using namespace std;

void SplitString(string sour, string c, vector<string> &dent) {
    string::size_type a = 0, b = sour.find(c);
    while (b < sour.size() && string::npos != b) {
        dent.push_back(sour.substr(a, b - a));
        a = b + c.size();
        b = sour.find(c, a);
    }
    if (a != sour.size()) {
        dent.push_back(sour.substr(a));
    }
}

int main() {
    string pattern;
    while (cin >> pattern) {
        getchar();
        vector<string> str;
        string stline;

        getline(cin, stline);
        SplitString(stline, " ", str);
        if (str.size() != pattern.size()) {
            puts("0");
            continue;
        }
        unordered_map<string, char> amap;
        unordered_map<char, string> bmap;
        bool ok = 1;
        for (int i = 0; i < pattern.size(); ++i) {
            if (amap.find(str[i]) != amap.end() && amap[str[i]] != pattern[i]) {
                ok = 0;
                break;
            }
            if (bmap.find(pattern[i]) != bmap.end() && bmap[pattern[i]] != str[i]) {
                ok = 0;
                break;
            }
            amap[str[i]] = pattern[i];
            bmap[pattern[i]] = str[i];
        }
        if (ok) {
            puts("1");
            continue;
        }
        puts("0");
    }
    return 0;
}