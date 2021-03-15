#include <iostream>
#include <map>
using namespace std;

map<long long, string> m;
map<long long, bool>::iterator it;
int main() {
    // int caseNum;
    // scanf("%d", &caseNum);
    // for (int i = 1,n,t; i <= caseNum;++i){
    //     scanf("%d", &n);

    // }
    cout << m.size() << endl;
    cout << m[1] << endl;
    cout << m.size() << endl;
    printf("%d\n", (bool) (m[1] == ""));
    m[2] = "3";
    cout << m[2] << endl;
    m[2] = "5";
    cout << m[2] << endl;

    return 0;
}