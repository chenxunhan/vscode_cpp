//ÖØ×ö£¡
//cxh
#include <bits/stdc++.h>
using namespace std;
int main() {
    int idx, tail;
    int n, a[105];
    while (~scanf("%d", &n)) {
        int sum = 0;
        memset(a, 0, 4 * (n + 5));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tail);
            for (idx = i; idx > 0; idx--) {
                if (a[idx - 1] > tail) {
                    a[idx] = a[idx - 1];
                    ++sum;
                } else
                    break;
            }
            a[idx] = tail;
        }
        printf("%d\n", sum);
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int arr[];
int min_idx(char *ar) {
    int min = INT_MAX;
    int idx = -1;
    int i = 0;
    while (*(ar + i)) {
        if (*(ar + i) < min) {
            min = *(ar + i);
            idx = i;
        }
        ++i;
    }
    return idx;
}

int main() {
    int n, t;
    int sum;
    while (~scanf("%d", &n)) {
        char ar[n + 5];
        int i = sum = 0;
        for (; i < n; ++i) {
            scanf("%d", &t);
            ar[i] = t - 160 + 1;
        }
        ar[i] = 0;
        while (strlen(ar) != 0) {
            int idx = min_idx(ar);
            sum += idx;
            ar[idx] = 0;
            strcat(ar, ar + idx + 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}
x*/