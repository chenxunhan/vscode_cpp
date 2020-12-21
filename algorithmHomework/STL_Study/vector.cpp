#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    //constructor new one
    vector<int> v1(0); //vector()  empty
    v1.push_back(1);
    v1.clear();
    v1.reserve(10);
    cout << "v1 size()=" << v1.size() << endl;
    v1.resize(10, 8);
    cout << "v1 is empty?" << (v1.empty() ? "yes" : "no") << endl;
    //vector( size_type num, const TYPE &val );
    vector<int> v2(10, 3);                          //10个3
    vector<int> v3(v2);                             //引用一个vector
    vector<int> v4(v2.begin(), v2.begin() + 3 + 1); //[0,3],use [) itrator
    for (int i = 0; v2.begin() + i < v2.end(); ++i) {
        cout << *(v2.begin() + i) << " ";
        --*(v2.begin() + i);
    }
    putchar('\n');
    // vector can compare, use != and ==, do not use > and <
    vector<int> v5;
    for (int i = 0; i < 5; ++i) {
        v5.push_back(i);
    }
    for (int i : v5) {
        cout << i << " ";
    }
    putchar('\n');
    // capacity() != size()
    for (int i = 0; i < v5.capacity(); ++i) {
        cout << v5[i] << " ";
    }
    putchar('\n');
    v5.erase(v5.begin() + 2);
    for (int i : v5) {
        cout << i << " ";
    }

    return 0;
}