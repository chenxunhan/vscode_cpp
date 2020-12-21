#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool rdsame(string a, string b) {
    if (a.find(b) != string::npos) {
        return 1;
    }
    return 0;
    // for (int i = 0; i <= a.size() / 2; ++i) {
    //     string ai = a.substr(i, a.size() / 2);
    //     if (ai == b) {
    //         return true;
    //     }
    // }
    // return false;
}

bool revsame(string a, string b) {
    // cout << a << endl;
    reverse(a.begin(), a.end());
    // cout << a << endl
    //      << endl;
    if (a.find(b) != string::npos) {
        return 1;
    }
    return 0;
    // for (int i = 0; i <= a.size() / 2; ++i) {
    //     string ai = a.substr(i, a.size() / 2);
    //     if (ai == b) {
    //         return true;
    //     }
    // }
    // return false;
}

vector<string> save;
string s = "aaabbbbccccc";
// string s = "aaabbbbccc";

int main() {
    int sum = 0;
    do {
        bool canin = 1;
        //    for (string si : save) {
        for (int i = 0; i < save.size(); ++i) {
            string si = save[i], re = string(si);
            reverse(re.begin(), re.end());
            // if (rdsame(si, s) || revsame(si, s)) {
            if (si.find(s) != string::npos || re.find(s) != string::npos) {
                canin = 0;
                break;
            }
        }
        if (canin == 1) {
            cout << ++sum << endl;
            save.push_back(s + s);
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << endl
         << "ans:" << save.size() << endl;

    // do {
    //     cout << ++sum << endl;
    // } while (next_permutation(s.begin(), s.end()));
    // cout << endl
    //      << "ans:" << save.size() << endl;
    return 0;
}
