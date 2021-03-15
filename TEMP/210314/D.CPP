#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

string n1, n2, teamName[35];
int s1, s2;
int caseNum, teamNum, matchNum;

enum type {
    win,
    lose,
    eq
};

int scoreDiff() {
    return abs(s1 - s2);
}

class Team {
  public:
    string name;
    int score = 0;
    int winNum = 0;
    int loseNum = 0;
    int eqNum = 0;

    int inNum = 0;
    int outNum = 0;

    int iodiff() {
        return inNum - outNum;
    }
    void action(type t) {
        if (t == win) {
            score += 3;
            ++winNum;
            return;
        }
        if (t == lose) {
            ++loseNum;
            return;
        }
        if (t == eq) {
            ++score;
            ++eqNum;
            return;
        }
    }
    void disp() {
        cout << name;
        printf(" %d %d %d %d %d %d\n", score, winNum, loseNum, eqNum, inNum, outNum);
    }
};

Team rank_[35];
map<string, Team> m;

void record() {
    m[n1].inNum += s1;
    m[n1].outNum += s2;
    m[n2].inNum += s2;
    m[n2].outNum += s1;
    if (s1 > s2) {
        m[n1].action(win);
        m[n2].action(lose);
    }
    if (s1 < s2) {
        m[n1].action(lose);
        m[n2].action(win);
    }
    if (s1 == s2) {
        m[n1].action(eq);
        m[n2].action(eq);
    }
}

bool c1(Team a, Team b) {
    return a.score > b.score;
}
bool c2(Team a, Team b) {
    return a.iodiff() > b.iodiff();
}
bool c3(Team a, Team b) {
    return a.inNum > b.inNum;
}
bool c4(Team a, Team b) {
    return a.name < b.name;
}
void SORT() {
    // rank_ + 1, rank_ + teamNum + 1
    stable_sort(rank_ + 1, rank_ + teamNum + 1, c4);
    stable_sort(rank_ + 1, rank_ + teamNum + 1, c3);
    stable_sort(rank_ + 1, rank_ + teamNum + 1, c2);
    stable_sort(rank_ + 1, rank_ + teamNum + 1, c1);
}

int main() {
    cin >> caseNum;
    for (int casei = 1; casei <= caseNum; ++casei) {
        cin >> teamNum >> matchNum;
        for (int i = 1; i <= teamNum; ++i) {
            cin >> n1;
            teamName[i] = m[n1].name = n1;
        }
        for (int i = 1; i <= matchNum; ++i) {
            cin >> n1 >> s1 >> n2 >> s2;
            record();
        }
        for (int i = 1; i <= teamNum; ++i) {
            rank_[i] = m[teamName[i]];
        }
        SORT();
        cout << "Group " << casei << ":\n";
        for (int i = 1; i <= teamNum; ++i) {
            rank_[i].disp();
        }
        m.erase(m.begin(), m.end());
        cout << endl;
        
    }
    return 0;
}