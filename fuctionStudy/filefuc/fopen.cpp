#include <bits/stdc++.h>
#define N 100
using namespace std;

int main() {
    FILE *fp = fopen("a.txt", "a+");
    for (int i = 0; i < N; ++i) {
        fprintf(fp, "%d\n", i);
    }
    return 0;
}