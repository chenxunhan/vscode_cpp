#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 4000 + 5;
// bool aIsPlus, bIsPlus;
// char aNumStr[MAXSIZE], bNumStr[MAXSIZE];
// int aNumArr[MAXSIZE], bNumArr[MAXSIZE];
// int resNumArr[MAXSIZE];

struct Number {
    bool hasNeg = 0;
    char numStr[MAXSIZE] = {0};
    int numArr[MAXSIZE] = {0};
} a, b, res;

// void NumStrToArr(char c,char numStr[], int NumArr[]) {
//     if(c == '')
//     int numStrLen = strlen(numStr);
//     for (int i = 0; i < numStrLen; ++i) {
//         NumArr[numStrLen - 1 - i] = numStr[i] - '0';
//     }
// }
void NumStrToArr(Number &number) {
    if (number.numStr[0] == '-') {
        number.hasNeg = 1;
    }
    int numStrLen = strlen(number.numStr);
    for (int i = strlen(number.numStr) - 1; i >= number.hasNeg; --i) {
        number.numArr[numStrLen - 1 - i] = number.numStr[i] - '0';
    }
}
// void add_AB_InRes() {
//     for (int i = 0; i < MAXSIZE; ++i) {
//         resNumArr[i] += aNumArr[i] + bNumArr[i];
//         if (resNumArr[i] >= 10) {
//             resNumArr[i + 1] += resNumArr[i] / 10;
//             resNumArr[i] %= 10;
//         }
//     }
// }
void mul_AB_InRes() {
    if (a.hasNeg != b.hasNeg) {
        res.hasNeg = 1;
    }
    for (int i = 0; i < MAXSIZE; ++i) {
        // res.numArr[i] += a.numArr[i] + b.numArr[i];

        for (int j = 0; j <= i; ++j) {
            res.numArr[i] += a.numArr[i - j] * b.numArr[j];
        }

        if (res.numArr[i] >= 10) {
            res.numArr[i + 1] += res.numArr[i] / 10;
            res.numArr[i] %= 10;
        }
    }
}
void printResNumArr() {
    int okHead;
    for (okHead = MAXSIZE; okHead; --okHead) {
        if (res.numArr[okHead]) {
            break;
        }
    }
    if (res.hasNeg) {
        putchar('-');
    }
    for (; okHead >= 0; --okHead) {
        putchar('0' + res.numArr[okHead]);
    }
}

int main() {
    scanf("%s", a.numStr);
    scanf("%s", b.numStr);
    NumStrToArr(a);
    NumStrToArr(b);
    mul_AB_InRes();
    printResNumArr();
    return 0;
}