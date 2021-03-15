// #include<cstdio>
#include <climits>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;
char t;
int wNum, senNum;
map<string, string> m;
map<string, string>::iterator iter;
// stringstream inp;
string word, Word, str;
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),
    cout.tie(0);
    cin >> wNum;
    for (int i = 1; i <= wNum; ++i) {
        cin >> word;
        getchar();
        getline(cin, Word);
        m[word] = Word;
        // mapStudent.insert(pair<int, string>(000, "student_zero"));
    }
    cin >> senNum;
    // cout << senNum << endl;
    // cout << endl;
    getline(cin, str);
    for (int i = 1; i < senNum; ++i) {
        getline(cin, str);
        // inp<<str;
        stringstream inp(str);

        inp >> word;
        if (m.find(word) != m.end())
            cout << m[word];
        else
            cout << word;

        while (inp >> word) {
            if (m.find(word) != m.end())
                cout << " " << m[word];
            else
                cout << " " << word;
        }
        cout << endl;
    }
    getline(cin, str);
    stringstream inp(str);
    // inp<<str;

    inp >> word;
    if (m.find(word) != m.end())
        cout << m[word];
    else
        cout << word;

    while (inp >> word) {
        if (m.find(word) != m.end())
            cout << " " << m[word];
        else
            cout << " " << word;
    }
    return 0;
}
