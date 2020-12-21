#include <bits/stdc++.h>
#define N 50
using namespace std;

void conquer(int a[], int front, int mid, int rear) {
    int A[mid - front + 1], B[rear - mid + 1];
    for (int i = 0; i < mid - front; ++i) {
        A[i] = a[front + i];
    }
    for (int i = 0; i < rear - mid; ++i) {
        B[i] = a[mid + i];
    }
    int i, j, k = front;
    for (i = j = 0; i < (mid - front) && j < (rear - mid); ++k) {
        a[k] = (A[i] < B[j]) ? A[i++] : B[j++];
    }
    if (i == (mid - front)) {
        while (k != rear) {
            a[k] = B[j];
            ++j, ++k;
        }
    } else {
        while (k != rear) {
            a[k] = A[i];
            ++i, ++k;
        }
    }
}

void divide(int a[], int front, int rear) {
    int mid = (front + rear) / 2;
    if ((rear - front) >= 3) {
        divide(a, front, mid);
        divide(a, mid, rear);
    }
    conquer(a, front, mid, rear);
}

int main() {
    int a[N];
    int n = N;
    for (int i = 0; i < n; ++i) {
        a[i] = n - i - 1;
    }
    for (int i : a) {
        printf("%d ", i);
    }
    putchar('\n');
    putchar('\n');
    divide(a, 0, N);
    for (int i : a) {
        printf("%d ", i);
    }
    return 0;
}