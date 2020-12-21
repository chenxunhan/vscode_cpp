//竞赛第三道
//cxh
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> room;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

bool ishz(int a, int b) {
    return gcd(a, b) == 1;
}

bool command(int &t) { //可能扫描会出错
    char x;
    bool in_out; //1 in ;0 out
    scanf("%c", &x);
    scanf("%d", &t);
    return x == '+';
}

bool isallhz(int a) {
    bool ok = 1;
    for (int i = 0; i < room.size(); ++i) {
        if (!ishz(a, room[i])) {
            return false;
        }
    }
    return 1;
}

void output(string a) {
    if (a == "ok") {
        puts("Ok");
    } else if (a == "ai") {
        puts("Already In");
    } else if (a == "ao") {
        puts("Already Out");
    }
}

void output(string a, int n) {
    if (a == "cw")
        printf("Conflict With %d\n", n);
}

bool isin(int a, int &pos) {
    for (int i = 0; i < room.size(); ++i) {
        if (a == room[i]) {
            pos = i;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    int t;
    while (~scanf("%d%d", &n, &k)) {
        for (int ni = 0; ni < n; ++ni) {
            if (command(t)) { //"+"
                if (isallhz(t)) {
                    output("ok");
                    room.push_back(t);
                } else {
                    puts("cw", );
                }
            } else {
                int pos;
                if (isin(t, pos)) {
                    room.erase(room.begin() + 1);
                    output("ok");
                } else {
                    output("ao");
                }
            }
        }
    }
    return 0;
}
