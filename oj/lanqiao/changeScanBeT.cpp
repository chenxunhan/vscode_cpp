#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char S[N], T[N];
int Slen, Tlen;

int Min = INT_MAX;
int main() {
    scanf("%s", S);
    scanf("%s", T);
    Slen = strlen(S), Tlen = strlen(T);
    for (int i = 0; i <= Slen - Tlen; ++i) {
        int min = 0;
        for (int j = 0; T[j] != 0; ++j) {
            min += (S[i + j] != T[j]);
        }
        if (min < Min) {
            Min = min;
        }
    }
    cout << Min << endl;
    return 0;
}