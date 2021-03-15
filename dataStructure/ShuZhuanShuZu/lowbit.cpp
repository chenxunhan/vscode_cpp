#include <bits/stdc++.h>
using namespace std;

//二进制中从最低位到高位连续零的长度
int lowbit_self(int value) {
    int ret = 0;
    while ((value & 1) == 0) {
    while (value & 1 == 0) {
        ++ret;
        value >>= 1;
    }
    return ret;
}

void printRule(int value) {
    int k = pow(2, lowbit_self(value));
    printf("C[%d] = ", value);
    for (int i = 1; i <= k; ++i) {
        printf("A[%d] + ", value + i - k);
    }
    putchar('\n');
}

int main() {
    for (int i = 1; i <= 8; ++i) {
        printRule(i);
    }
    return 0;
}