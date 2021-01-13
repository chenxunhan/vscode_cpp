#include <bits/stdc++.h>
using namespace std;

const int LEN = 1003;

void clear(int a[]) {
    for (int i; i < LEN; ++i) {
        a[i] = 0;
    }
}

void read(int a[]) {
    static char s[LEN];
    scanf("%s", s);
    clear(a);
    int len = strlen(s);
    for (int i(0); i < LEN; ++i) {
        a[LEN - 1 - i] = s[i] - '0';
    }
}
void numToArray(int a[], int n) {
    clear(a);
    for (int i(0); n; ++i) {
        a[i] = n % 10;
        n /= 10;
    }
}

void print(const int a[]) {
    int i;
    for (i = LEN - 1; i >= 1; --i) {
        if (a[i] != 0) {
            break;
        }
    }
    for (; i >= 0; --i) {
        putchar(a[i] + '0');
    }
    putchar('\n');
}

void add(const int a[], const int b[], int c[]) {
    clear(c);
    for (int i(0); i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            ++c[i + 1];
            c[i] -= 10;
        }
    }
}

void sub(const int a[], const int b[], int c[]) {
    clear(c);
    for (int i(0); i < LEN - 1; ++i) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            --c[i + 1];
            c[i] += 10;
        }
    }
}

void mul_shorts(const int a[], const int b, int c[]) {
    clear(c);
    for (int i(0); i < LEN - 1; ++i) {
        c[i] += a[i] * b;
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

void mul(int a[], int b[], int c[]) {
    clear(c);
    for (int i = 0; i < LEN - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            c[i] += a[j] * b[i - j];
        }
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

int main() {
    int n = 3;
    // scanf("%d", &n);
    int res[2][LEN];
    numToArray(res[1], 1);
    for (int i = 2; i <= n; ++i) {
        mul_shorts(res[!(i & 1)], i, res[i & 1]);
    }
    print(res[n & 1]);
    return 0;
}