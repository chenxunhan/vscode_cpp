#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;
int res(0);
enum gridType {
    e = 0,
    b = 1,
    w = 2
};

class Table {
  public:
    gridType v[5][5];
    gridType win();
    void reset();

} table;

int xb = 1, yb, xw, yw;
string state() {
    string s = "";
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            s += char(int(table.v[i][j]) + 60);
        }
    }
    return s;
}
unordered_set<string> recordMap;
bool last = 0;
void dfs(bool white) {
    string s = state();
    if (recordMap.find(s) != recordMap.end()) {
        return;
    } else {
        recordMap.insert(s);
    }
    gridType t=table.win();
    if (t != e||last) {
        if (t == w && last) {
            ++res;
        }
        return;
    }

    for (int j = 1; j <= 4; ++j) {
        for (int i = 1; i <= 4 && table.v[i - 1][j] != e; ++i) {
            if (table.v[i][j] == e) {
                table.v[i][j] = (white ? w : b);
                last = (j == yw && i == xw);
                dfs(!white);
                table.v[i][j] = e;
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &yb, &xw, &yw);
    res = 0;
    table.reset();
    table.v[xb][yb] = b;
    dfs(1);
    printf("%d", res);
}

gridType Table::win() {
    //col win
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (v[i][j] != e && v[i][j] == v[i + 1][j] && v[i][j] == v[i + 2][j])
                return v[i][j];
        }
    }
    //rang win
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 2; ++j) {
            if (v[i][j] != e && v[i][j] == v[i][j + 1] && v[i][j] == v[i][j + 2])
                return v[i][j];
        }
    }
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            if (v[i][j] != e && v[i][j] == v[i + 1][j + 1] && v[i][j] == v[i + 2][j + 2])
                return v[i][j];
        }
    }
    for (int i = 1; i <= 2; ++i) {
        for (int j = 3; j <= 4; ++j) {
            if (v[i][j] != e && v[i][j] == v[i + 1][j - 1] && v[i][j] == v[i + 2][j - 2])
                return v[i][j];
        }
    }
    return e;
}

void Table::reset() {
    for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j < 5; j++) {
            v[i][j] = e;
        }
    }
    for (int j = 1; j <= 4; ++j) {
        v[0][j] = b;
    }
}