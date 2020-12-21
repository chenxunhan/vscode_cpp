#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXTABLELENGTH = 15;

FILE *fpin;
int tableLength;
int table[MAXTABLELENGTH][MAXTABLELENGTH];
int dpTableMaxValue[2][MAXTABLELENGTH][MAXTABLELENGTH];

int main() {
    fpin = fopen("input.txt", "r");
    fscanf(fpin, "%d", &tableLength);
    int x, y, v;
    while (fscanf(fpin, "%d%d%d", &x, &y, &v) && (x || y || v)) {
        table[x][y] = v;
    }
    //step is not the real step, step0=2 ==1+1 ,first pos
    for (int step = 2, stepLim = 2 * tableLength; step <= stepLim; ++step) {
        for (int p1stX = min(step - 1, tableLength); p1stX; --p1stX) {
            for (int p2ndX = min(step - 1, tableLength); p2ndX; --p2ndX) {
                dpTableMaxValue[step & 1][p1stX][p2ndX] =
                    max(
                        max(
                            dpTableMaxValue[(step - 1) & 1][p1stX - 1][p2ndX],
                            dpTableMaxValue[(step - 1) & 1][p1stX - 1][p2ndX - 1]),
                        max(
                            dpTableMaxValue[(step - 1) & 1][p1stX][p2ndX],
                            dpTableMaxValue[(step - 1) & 1][p1stX][p2ndX - 1])) +
                    table[p1stX][step - p1stX] +
                    table[p2ndX][step - p2ndX] * (p1stX != p2ndX);
            }
        }
    }
    printf("%d\n", dpTableMaxValue[0][tableLength][tableLength]);
    return 0;
}