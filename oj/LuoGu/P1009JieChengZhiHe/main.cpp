#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 9999;

int res[MAXLEN] = {0};
int nowJc[MAXLEN] = {0};

void clear(int a[]) {
    for (int i(0); i < MAXLEN; ++i) {
        a[i] = 0;
    }
}

void numToArr(int arr[], int num) {
    clear(arr);
    for (int i(0); num; ++i) {
        arr[i] = num % 10;
        num /= 10;
    }
}

void getNowJc(int n) {
    for (int i(0); i < MAXLEN; ++i) {
        nowJc[i] *= n;
    }
    for (int i(0); i < MAXLEN; ++i) {
        if (nowJc[i] >= 10) {
            nowJc[i + 1] += nowJc[i] / 10;
            nowJc[i] %= 10;
        }
    }
}

void addInRes() {
    for (int i(0); i < MAXLEN; ++i) {
        res[i] += nowJc[i];
        if (res[i] >= 10) {
            res[i] -= 10;
            ++res[i + 1];
        }
    }
}

void print(int a[]) {
    int i(MAXLEN - 1);
    for (; i >= 1; --i) {
        if (a[i]) {
            break;
        }
    }
    for (; i >= 0; --i) {
        putchar('0' + a[i]);
    }
    putchar('\n');
}

int main() {
    int n = 50;
    cin >> n;
    numToArr(nowJc, 1);
    // {
    //     for (int i = 1; i <= 50; ++i) {
    //         getNowJc(i);
    //         print(nowJc);
    //     }
    // }
    for (int i = 1; i <= n; ++i) {
        getNowJc(i);
        addInRes();
        // printf("%d!:", i);
        // print(nowJc);
        // printf("res:");
        // print(res);
    }
    print(res);

    return 0;
}