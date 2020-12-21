//cxh
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> res;
vector<int> root;

bool inc(vector<int> arr, int a) {
    for (int i : arr) {
        if (i == a) {
            return true;
        }
    }
    return false;
}

void backtrack(vector<int> &track) {
    if (track.size() == n) {
        res.push_back(track);
        return;
    }
    for (int i : root) {
        if (inc(track, i)) {
            continue;
        }
        track.push_back(i);
        backtrack(track);
        track.pop_back();
    }
}

void print(vector<vector<int>> res) {
    for (vector<int> resi : res) {
        for (int i : resi) {
            cout << i << " ";
        }
        putchar('\n');
    }
}

int main() {
    while (cin >> n) {
        res.clear();
        root.clear();
        int nt = n;
        while (nt--) {
            int tmp;
            cin >> tmp;
            root.push_back(tmp);
        }
        sort(root.begin(), root.end());
        vector<int> track;
        backtrack(track);
        print(res);
    }
    return 0;
}