#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int M[2][N];

int n, cols;
int sum = 0;
//  0   1
int up, dn;

void printM() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    putchar('\n');
}

void dfs(int num, bool bup) {
    if (M[1][cols - 1] == n) {
        if (bup == 1) {
            return;
        }
        printM();
        ++sum;
        (sum >= 2020 ? sum -= 2020 : 1);
        M[1][cols - 1] = 0;
        return;
    }
    if ((bup && up == cols)) {
        return;
    }
    if (bup) {
        M[0][up] = num;
    } else {
        if (M[0][dn] == 0) {
            return;
        }
        M[1][dn] = num;
    }
    ++up;
    dfs(num + 1, 1);
    M[0][up] = 0;
    --up;
    if (!(dn + 1 == cols - 1 && num + 1 != n)) {
        ++dn;
        dfs(num + 1, 0);
        M[1][dn] = 0;
        --dn;
    }
}

int main() {
    //2 4 6 8 ...
    //while (cin >> n) {
    {
        n = 8, up = 0, dn = -1;
        cols = n / 2;
        memset(M, 0, sizeof(M));
        sum = 0;
        dfs(1, 1);
        cout << sum;
    }
    return 0;
}