#include <bits/stdc++.h>
using namespace std;

int main() {
    char a[1000] = {0};
    char *apt = a;
    for (int i = 0; i < 100; ++i) {
        apt += sprintf(apt, "%d", i);
    }
    printf("%s", a);
    return 0;
}