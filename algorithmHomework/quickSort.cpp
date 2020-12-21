#include <bits/stdc++.h>
#define N 20
using namespace std;

void quickSort(int a[], int I, int J) {
    if (J - I <= 1)
        return;
    int pivot = a[J - 1];
    bool dir = 1;
    int i = I, j = J - 1;
    while (i < j) {
        if (dir) {
            if (a[i] > pivot) {
                a[j] = a[i], dir = 0;
                continue;
            }
            ++i;
            continue;
        } //dir==0
        if (a[j] < pivot) {
            a[i] = a[j], dir = 1;
            continue;
        }
        --j;
    }
    //if (i == j) {
    a[i] = pivot;
    quickSort(a, I, j);
    quickSort(a, j + 1, J);
}

int randRange(int i, int j) { //[i,j]
    return i + rand() % (j - i + 1);
}

int main() {
    srand(time(NULL));
    int a[N];
    for (int i = 0; i < N; ++i) {
        a[i] = N - i - 1;
    }
    for (int i = N; i < N; ++i) {
        swap(a[i], a[randRange(i, N - 1)]);
    }
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    quickSort(a, 0, N);
    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}