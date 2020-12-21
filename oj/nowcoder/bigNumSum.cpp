#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// 9999 2332434
// -3242 -23423
// -2342 13234
// 23424 -123123

string revStr(string a) {
    for (int i = 0, j = a.size() - 1; i < j; ++i, --j) 
        swap(a[i], a[j]);
    return a;
}

string Sum(string a, string b) {
    bool aNeg = (a[0] == '-'), bNeg = (b[0] == '-');
    int aXi = (aNeg ? -1 : 1), bXi = (bNeg ? -1 : 1);

    string sumNrac; //sum no reverse addChar
    for (int ai = a.size() - 1, bi = b.size() - 1;;) {
        if (ai >= aNeg)
            sumNrac += aXi * (a[ai--] - '0');
        if (bi >= bNeg)
            sumNrac += bXi * (b[bi--] - '0');
    }

    return;
}

int main() {
    string a, b;
    while (~scanf("%s %s", a.c_str(), b.c_str())) {
        printf("%s\n", Sum(a, b));
    }
    return 0;
}