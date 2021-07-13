#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 100;

int arrNum , arr[MAXSIZE];
int step;

void initarr(int arrNum_) {
    arrNum = arrNum_;
    for (int i = 0; i < arrNum; ++i) {
        arr[i] = i;
    }
}

void printarr() {
    for (int i = 0; i < arrNum; ++i) {
        printf("[%3d]:%3d, ", i, arr[i]);
        if ((i + 1) % 5 == 0) {
            puts("");
        }
    }
    puts("");
}

void jumparr(int step) {
    printf("jumpStep: %d\n", step);
    int originalPos;
    int nowPos;
    int nowEle, lastEle;
    for (int stepi = 0; stepi < step; ++stepi) {
        lastEle = (stepi + arrNum - step) % arrNum;
        originalPos = nowPos = stepi;
        do {
            nowEle = arr[nowPos];
            arr[nowPos] = lastEle;
            lastEle = nowEle;
            nowPos = (nowPos + step) % arrNum;
        } while (nowPos != originalPos);
    }
}

int main() {
    initarr(50);
    printarr();
    jumparr(step = 4);
    printarr();
    return 0;
}