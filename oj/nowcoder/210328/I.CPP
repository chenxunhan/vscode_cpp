#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXSIZE = 1e6 + 5;
int n;
int arr[MAXSIZE], _next[MAXSIZE];

void getNext() {
    int j = 0, k = -1;
    _next[0] = -1;
    while (j < n) {
        if (k == -1 || arr[j] == arr[k])
            _next[++j] = ++k;
        else
            k = _next[k];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; --i) {
        scanf("%d", arr + i);
    }
    getNext();
    int resk = n - 1, resp = 1;
    for (int i = 0, p, k; i <= n; ++i) {
        p = i - _next[i], k = n - i;
        if (p + k < resk + resp) {
            resk = k, resp = p;
            continue;
        }
        if (p + k == resk + resp && p < resp) {
            resk = k, resp = p;
        }
    }
    printf("%d %d", resk, resp);
    return 0;
}