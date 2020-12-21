#include <bits/stdc++.h>
#include <map>
using namespace std;

// map<string, int> myMap;
map<string, int> myMap{{"001", 1}, {"002", 2}};
map<string, int> newMap(myMap);
map<string, int> disMap() {
    map<string, int> tempMap(myMap);
    return tempMap;
}
map<string, int> newmap2(disMap());
map<string, int> newMap3(++myMap.begin(), myMap.end());

map<string, int, less<string>> lessmap(myMap);
map<string, int, greater<string>> greatermap;

int main() {
    for (auto i : myMap) {
        greatermap.emplace(i);
    }
    for (auto i = myMap.begin(); i != myMap.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }

    for (auto i = lessmap.begin(); i != lessmap.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
    for (auto i = greatermap.begin(); i != greatermap.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}