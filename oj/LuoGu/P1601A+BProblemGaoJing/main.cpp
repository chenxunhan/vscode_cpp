#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 500 + 5;
char aNumStr[MAXSIZE], bNumStr[MAXSIZE];
int aNumArr[MAXSIZE], bNumArr[MAXSIZE];
int resNumArr[MAXSIZE];

void NumStrToArr(char numStr[], int NumArr[]) {
    int numStrLen = strlen(numStr);
    for (int i = 0; i < numStrLen; ++i) {
        NumArr[numStrLen - 1 - i] = numStr[i] - '0';
    }
}
void add_AB_InRes() {
    for (int i = 0; i < MAXSIZE; ++i) {
        resNumArr[i] += aNumArr[i] + bNumArr[i];
        if (resNumArr[i] >= 10) {
            resNumArr[i + 1] += resNumArr[i] / 10;
            resNumArr[i] %= 10;
        }
    }
}
void printResNumArr() {
    int okHead;
    for (okHead = MAXSIZE; okHead; --okHead) {
        if (resNumArr[okHead]) {
            break;
        }
    }
    for (; okHead >= 0; --okHead) {
        putchar('0' + resNumArr[okHead]);
    }
}

int main() {
    scanf("%s", aNumStr);
    scanf("%s", bNumStr);
    NumStrToArr(aNumStr, aNumArr);
    NumStrToArr(bNumStr, bNumArr);
    add_AB_InRes();
    printResNumArr();
    return 0;
}