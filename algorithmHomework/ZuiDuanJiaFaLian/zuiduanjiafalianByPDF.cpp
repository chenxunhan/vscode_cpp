#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 10000;
int lb, ub, t;
int chain[MAXN];
int best;
bool found;
int n;
int a[MAXN], parent[MAXN];
int num;

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

bool odd(int num) {
    return num % 2 == 1;
}

int log2(int m) {
    int i = 0, j = 1;
    while (m > 1) {
        i++;
        if (odd(m))
            j++;
        m = m >> 1;
    }
    if (j > 1)
        i++;
    return i;
}
void find(int step) {
    int i, k;
    if (!found)
        if (a[step] == n) {
            best = step;
            for (i = 1; i <= best; i++)
                chain[i] = a[i];
            found = true;

            return;
        } else if (step <= ub)
            for (i = 1; i <= step; i++) {
                k = a[step] + a[i];
                if (k <= n) {
                    a[step + 1] = k;
                    if (parent[k] == 0) parent[k] = a[step];
                    if (parent[k] == a[step]) find(step + 1);
                }
            }
}

int lowerb(int m) {
    int i = 0, j = 1;
    while (m > 1) {
        i++;
        if (odd(m))
            j++;
        m = m >> 1;
    }
    i += log2(j) + 1;
    return i;
}
int gett(int m) {
    int i = 0;
    while (!odd(m)) {
        m = m >> 1;
        i++;
    }
    return i - 1;
}

int h(int num) {
    int i = 0;
    while (num < 0) {
        num = num << 1;
        i++;
    }
    return i;
}
bool pruned(int step) {
    if (step < lb - t - 1)
        return (h(3 * a[step]) + step + 2 > lb);
    else {
        return (h(a[step]) + step > lb);
    }
}

void backtrack(int step) {
    if (!found)
        if (a[step] == n) {
            best = step;
            for (int i = 1; i <= best; i++)
                chain[i] = a[i];
            found = true;
            return;
        } else if (step < lb)
            for (int i = step; i >= 1; i--)
                if (2 * a[i] > a[step])
                    for (int j = i; j >= i; j--) {
                        int k = a[i] + a[j];
                        a[step + 1] = k;
                        if (k > a[step] && k <= n)
                            if (!pruned(step + 1))
                                backtrack(step + 1);
                    }
}

int powertree(int n) {
    found = false;
    ub = 1;
    for (int i = 1; i <= MAXN; i++)
        parent[i] = 0;
    while (!found) {
        a[1] = 1;
        find(1);
        ub++;
    }

    return best;
}

void search() {
    lb = lowerb(n);
    ub = powertree(n);
    t = gett(n);
    if (lb < ub) {
        found = false;
        while (!found) {
            cout << "lb=" << lb << endl;
            a[1] = 1;
            backtrack(1);
            lb++;
            if (lb == ub) {
                found = true;
            }
        }
    }
}
void output() {
    fprintf(out, "%d\n", best - 1);
    for (int i = 1; i <= best; i++)
        fprintf(out, "%d ", chain[i]);
    fclose(out);
}

int main() {
    fscanf(in, "%d", &n);
    if (n <= MAXN) {
        search();
        output();
    } else
        cout << "Number too large!" << endl;
    fclose(in);
}