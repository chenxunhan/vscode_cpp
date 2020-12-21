#include <bits/stdc++.h>
#include <list>
using namespace std;

typedef char ElemType;

int main() {
    list<ElemType> L;
    list<ElemType>::iterator it = L.begin();    
    for (int i = 0; i < 5; ++i) {
        L.push_back('a' + i);
    }
    for (ElemType i : L) {
        cout << i << " ";
    }
    putchar('\n');
    cout << "length=" << L.size() << endl;
    cout << "L is " << (L.empty() ? "" : "not ") << "empty.\n";
    {
        int iti = 3;
        while (iti--) {
            ++it;
        }
    }
    cout << "the ele3 in L is " << *(it) << endl;
    {
        int pos = 0;
        for (it = L.begin(); *(it) != 'a'; ++it, ++pos) {
            cout << "\'a\' position in L is " << pos << endl;
        }
    }
    {
        int iti = 4;
        it = L.begin();
        while (iti--) {
            ++it;
        }
    }
    L.insert(it, 'f');
    for (ElemType i : L) {
        cout << i << " ";
    }
    putchar('\n');
    L.clear();

    return 0;
}