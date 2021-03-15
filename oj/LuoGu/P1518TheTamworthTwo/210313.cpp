#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char map[12][12];
enum Dir {
    up,
    right,
    down,
    left
};
class Pos {
  public:
    int x, y;
    bool operator!=(const Pos &p) {
        return !((this->x == p.x) && (this->y == p.y));
    }
};

class player {
  public:
    Pos pos;
    Dir dir = up;
    bool isBan() {
        if (
            (dir == up && map[pos.x - 1][pos.y] == '*') ||
            (dir == down && map[pos.x + 1][pos.y] == '*') ||
            (dir == left && map[pos.x][pos.y - 1] == '*') ||
            (dir == right && map[pos.x][pos.y + 1] == '*')) {
            return 1;
        }
        return 0;
    }
    void move() {
        if (dir == up) {
            --pos.x;
            return;
        }
        if (dir == down) {
            ++pos.x;
            return;
        }
        if (dir == left) {
            --pos.y;
            return;
        }
        if (dir == right) {
            ++pos.y;
            return;
        }
    }
    void turn() {
        dir = (Dir)(dir + 1);
        dir = (Dir)(dir % 4);
    }
    void action() {
        if (isBan()) {
            turn();
        } else {
            move();
        }
    }
} fam, cow;

void inputMap() {
    for (int i = 0; i < 12; ++i) {
        map[0][i] = map[11][i] = '*';
    }
    for (int i = 1; i <= 10; ++i) {
        scanf("%s", map[i] + 1);
        map[i][0] = map[i][11] = '*';
        for (int j = 1; j <= 10; ++j) {
            if (map[i][j] == 'F') {
                map[i][j] = '.';
                fam.pos = (Pos){i, j};
                continue;
            }
            if (map[i][j] == 'C') {
                map[i][j] = '.';
                cow.pos = (Pos){i, j};
                continue;
            }
        }
    }
}

//famDir cowDir famX FamY cowX cowY
bool status[4][4][12][12][12][12] = {0};
bool hasStatus() {
    if (status[fam.dir][cow.dir][fam.pos.x][fam.pos.y][cow.pos.x][cow.pos.y]) {
        return 1;
    }
    return 0;
}
void recordStatus() {
    status[fam.dir][cow.dir][fam.pos.x][fam.pos.y][cow.pos.x][cow.pos.y] = 1;
}
int pasTime = 0;
int main() {
    inputMap();
    while (fam.pos != cow.pos) {
        if (hasStatus()) {
            pasTime = 0;
            break;
        }
        recordStatus();
        fam.action();
        cow.action();
        ++pasTime;
    }
    printf("%d", pasTime);
    return 0;
}