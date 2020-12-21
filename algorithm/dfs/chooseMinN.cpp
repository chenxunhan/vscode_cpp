#include <bits/stdc++.h>
#define loop(i, x, y) for (register int i = x; i <= y; ++i)
using namespace std;
const int N = 10;

int m, n;
int a[N];
vector<int> res;

void dfsc(int pos, int num) {
    if (num == 0) {
        for (int i = 0; i < res.size(); ++i) {
            cout << res.at(i) << " ";
        }
        cout << endl;
        return;
    }

    loop(i, pos, n - 1) {
        res.push_back(a[i]);
        dfsc(i + 1, num - 1);
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    loop(i, 0, n - 1) {
        cin >> a[i];
    }
    dfsc(0, m);

    return 0;
}
