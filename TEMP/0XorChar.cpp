#include <bits/stdc++.h>
using namespace std;

int main() {
    for (char i = '0'; i <= '9'; ++i) {
        printf("%d = %d = %d \n", i, i ^ '0', i - '0');
    }
    return 0;
}