#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
    list<char> charList;
    for (int i = 0; i < 10; ++i) {
        charList.push_front('A' + i);
    }
    //do not foget ::
    for (list<char>::iterator p = charList.begin();
         p != charList.end(); ++p) {
        cout << *p << " ";
    }

    // pop_back() is void,not a TYPE
    putchar('\n');
    cout << charList.back();
    charList.pop_back();
    for (char i : charList) {
        cout << i << " ";
    }
    list<char>::iterator it = charList.end();
    return 0;
}