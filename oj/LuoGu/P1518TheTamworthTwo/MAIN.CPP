#include <cstdio>

// const int SIZE = 10;
enum Direction {
    Up = 0,
    Right = 1,
    Down = 2,
    Left = 3
};
enum Player {
    fa,
    cow
};
char Map[10][10];

//fa:x;cow:y
// [x1][y_1][x2][y2][x_dir][y_dir]
int x1 = 0, y_1 = 0;
int x2 = 0, y2 = 0;
int x_dir = Up, y_dir = Up;
bool status[10][10][10][10][4][4] = {0};
int pastTime = 0;

bool isOut(int x, int y) {
    return (x < 0 || y < 0 || x >= 10 || y >= 10);
}

bool isban(Player player) {
    int x, y, dir;
    if (player == fa) {
        x = x1, y = y_1;
        dir = x_dir;
    } else if (player == cow) {
        x = x2, y = y2;
        dir = y_dir;
    }
    // printf("tset");
    if (dir == Up) {
        return (isOut(x - 1, y) || Map[x - 1][y] == '*');
    } else if (dir == Down) {
        return (isOut(x + 1, y) || Map[x + 1][y] == '*');
    } else if (dir == Left) {
        return (isOut(x, y - 1) || Map[x][y - 1] == '*');
    } else if (dir == Right) {
        return (isOut(x, y + 1) || Map[x][y + 1] == '*');
    }
    return 0;
}

void turn(Player player) {
    if (player == fa) {
        ++x_dir;
        x_dir %= 4;
    } else if (player == cow) {
        ++y_dir;
        y_dir %= 4;
    }
}

void move(Player player) {
    int x, y, dir;
    char c;
    if (player == fa) {
        x = x1, y = y_1;
        dir = x_dir;
        c = 'F';
    } else if (player == cow) {
        x = x2, y = y2;
        dir = y_dir;
        c = 'C';
    }
    if (dir == Up) {
        Map[x][y] = '.';
        Map[x - 1][y] = c;
        
        // return (isOut(x - 1, y) || Map[x - 1][y] == '*');
    } else if (dir == Down) {

        Map[x][y] = '.';
        // Map[x + 1][y] = c;
        // return (isOut(x + 1, y) || Map[x + 1][y] == '*');
    } else if (dir == Left) {

        Map[x][y] = '.';
        // Map[x][y - 1] = c;
        // return (isOut(x, y - 1) || Map[x][y - 1] == '*');
    } else if (dir == Right) {

        Map[x][y] = '.';
        // Map[x][y + 1] = c;
        // return (isOut(x, y + 1) || Map[x][y + 1] == '*');
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        scanf("%s", Map[i]);
        for (int j = 0; j < 10; ++j) {
            // scanf("%c", Map[i][j]);
            if (Map[i][j] == 'F') {
                x1 = i, y_1 = j;
                printf("f:%d-%d\n", x1, y_1);
            }
            if (Map[i][j] == 'C') {
                x2 = i, y2 = j;
                printf("c:%d-%d\n", x2, y2);
            }
        }
    }
    printf("f:%d-%d\n", x1, y_1);

    printf("c:%d-%d\n", x2, y2);

    while (1) {
        if (status[x1][y_1][x2][y2][x_dir][y_dir]) {
            // printf("%d-%d-%d-%d-%d-%d", x1, y_1, x2, y2, x_dir, y_dir);
            printf("%d\n", pastTime);
            printf("0");
            break;
        }
        status[x1][y_1][x2][y2][x_dir][y_dir] = 1;
        //fa
        if (isban(fa)) {
            turn(fa);
        } else {
            move(fa);
        }

        //cow
        if (isban(cow)) {
            turn(cow);
        } else {
            move(cow);
        }

        ++pastTime;
        if ((x1 == x2) && (y_1 == y2)) {
            printf("%d", pastTime);
            break;
        }
    }
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j)
    //         printf("%c", Map[i][j]);
    //     putchar('\n');
    // }

    return 0;
}