#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

const int MAXTABLELENGTH = 15;
enum direction {
    
    left_up,
    up_up,
    up_left,
    left_left
};

FILE *fpin, *fpout;
int tableLength;
int table[MAXTABLELENGTH][MAXTABLELENGTH] = {0};
int dpMaxValue[MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH] = {0};
direction dpMaxValueDir[MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH];

string Apath, Bpath;
int time = -1;
void printPath(int a, int b, int c, int d) {
    printf("a:%d,b:%d,c:%d,d:%d\n", a, b, c, d);
    ++time;
    if (time == 2 * (tableLength - 1)) {
        // if (a == 1 && b == 1) {
        // if (a == 1 && b == 1 && c == 1 && d == 1) {
        printf("Apath:%s\n", Apath.c_str());
        printf("Bpath:%s\n", Bpath.c_str());
        return;
    }
    switch (dpMaxValueDir[a][b][c][d]) {
    case up_up:
        Apath = "¡ý" + Apath;
        Bpath = "¡ý" + Bpath;
        printPath(a - 1, b, c - 1, d);
        break;
    case up_left:
        Apath = "¡ý" + Apath;
        Bpath = "¡ú" + Bpath;
        printPath(a - 1, b, c, d - 1);
        break;
    case left_left:
        Apath = "¡ú" + Apath;
        Bpath = "¡ú" + Bpath;
        printPath(a, b - 1, c, d - 1);
        break;
    case left_up:
        Apath = "¡ú" + Apath;
        Bpath = "¡ý" + Bpath;
        printPath(a, b - 1, c - 1, d);
        break;
    default:
        break;
    }
}

int main() {
    fpin = fopen("input.txt", "r");
    fscanf(fpin, "%d", &tableLength);
    printf("len:%d\n", tableLength);
    int x, y, v;
    while (fscanf(fpin, "%d%d%d", &x, &y, &v) && !(x == 0 && y == 0 && v == 0)) {
        // if (x == 0 && y == 0 && v == 0) {
        //     break;
        // }
        table[x][y] = v;
        // printf("%d\n", v);
    }
    fclose(fpin);
    for (int a = 1; a <= tableLength; ++a) {
        for (int b = 1; b <= tableLength; ++b) {
            for (int c = 1; c <= tableLength; ++c) {
                for (int d = 1; d <= tableLength; ++d) {
                    // dpMaxValue[a][b][c][d] = max(max(dpMaxValue[a][b - 1][c - 1][d], dpMaxValue[a][b - 1][c][d - 1]), max(dpMaxValue[a - 1][b][c][d - 1], dpMaxValue[a - 1][b][c - 1][d])) + table[a][b] + table[c][d];
                    if (dpMaxValue[a][b][c][d] <= dpMaxValue[a][b - 1][c - 1][d]) {
                        dpMaxValue[a][b][c][d] = dpMaxValue[a][b - 1][c - 1][d];
                        dpMaxValueDir[a][b][c][d] = left_up;
                        // dpMaxValueDir[a][b][c][d][1] = up;
                    }
                    if (dpMaxValue[a][b][c][d] <= dpMaxValue[a][b - 1][c][d - 1]) {
                        dpMaxValue[a][b][c][d] = dpMaxValue[a][b - 1][c][d - 1];
                        dpMaxValueDir[a][b][c][d] = left_left;
                        // dpMaxValueDir[a][b][c][d][1] = left;
                    }
                    if (dpMaxValue[a][b][c][d] <= dpMaxValue[a - 1][b][c][d - 1]) {
                        dpMaxValue[a][b][c][d] = dpMaxValue[a - 1][b][c][d - 1];
                        dpMaxValueDir[a][b][c][d] = up_left;
                        // dpMaxValueDir[a][b][c][d][1] = left;
                    }
                    if (dpMaxValue[a][b][c][d] <= dpMaxValue[a - 1][b][c - 1][d]) {
                        dpMaxValue[a][b][c][d] = dpMaxValue[a - 1][b][c - 1][d];
                        dpMaxValueDir[a][b][c][d] = up_up;
                        // dpMaxValueDir[a][b][c][d][1] = up;
                    }
                    dpMaxValue[a][b][c][d] += table[a][b] + table[c][d];
                    if (a == c && b == d) {
                        dpMaxValue[a][b][c][d] -= table[a][b];
                    }
                }
            }
        }
    }
    printf("%d\n", dpMaxValue[tableLength][tableLength][tableLength][tableLength]);
    //a path
    printPath(tableLength, tableLength, tableLength, tableLength);
    //b path
    return 0;
}