//1007
//cxh
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    int sum, t;
    cin >> a;
    while (a--) {
        sum = 0;
        cin >> b;
        while (b--) {
            cin >> t;
            sum += t;
        }
        cout << sum << endl;
    }
    return 0;
}
