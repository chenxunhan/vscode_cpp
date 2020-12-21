#include <bits/stdc++.h>

int bitsByLoop(short number) {
    short bits(0);
    while (number) {
        ++bits;
        number >>= 1;
    }
    return bits > 0 ? bits : 1;
}

int bitsByDivide(short number) {
    short bits(0);
    (number & 0xff00) &&
        (bits += 8,
         number >>= 8),
        (number & 0xf0) &&
            (bits += 4,
             number >>= 4),
        (number & 0xc) &&
            (bits += 2,
             number >>= 2),
        (number & 2) &&
            (++bits,
             number >>= 1),
        bits += number & 1;
    return bits;
}

int main() {
    // printf("%d\n", sizeof(short));
    // printf("%d\n%d", bitsByLoop(0), bitsByLoop(INT_MAX));
    short test_number = 512;
    printf("%d==%d\n", bitsByLoop(test_number), bitsByDivide(test_number));
    return 0;
}