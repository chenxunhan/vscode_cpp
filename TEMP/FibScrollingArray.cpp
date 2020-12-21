#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 20;
    int a[3] = {1, 1}; //0 1 2
    cout << a[0] << " " << a[1] << " ";
    for (int i = 2; i <= n; ++i) {
        a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3];
        cout << a[i % 3] << " ";
    }
    return 0;
}