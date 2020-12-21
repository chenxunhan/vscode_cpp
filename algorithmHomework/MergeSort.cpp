#include <bits/stdc++.h>
using namespace std;

void Merge(int array[], int front, int mid, int rear) {
    int arrayLeft[mid - front], arrayRight[rear - mid]; //应修改arrayLeft[mid - front+1]
    int leftIndex = front, rightIndex = mid + 1;
    for (int i = front; i < mid; ++i) {
        arrayLeft[i] = array[i];
    } /*上方全错要修改
    for (int i = front, j = 0; i < mid; ++i) {
        arrayLeft[j++] = array[i];
    }*/
    for (int i = mid + 1; i < rear; ++i) {
        arrayRight[i] = array[i];
    } /*修改
    for (int i = mid + 1, j = 0; i < rear; ++i) {
        arrayRight[j++] = array[i];
    }*/
    while (leftIndex < mid && rightIndex < rear) {
        if (arrayLeft[leftIndex] < arrayRight[rightIndex]) {
            array[front] = arrayLeft[leftIndex];
            ++leftIndex;
        } else {
            array[front] = arrayRight[rightIndex];
            ++rightIndex;
        }
        ++front;
    }
}

void MergeSort(int array[], int front, int rear) {
    int mid = front + (rear - front) / 2; //此行应在判断条件内，可简化为(front+rear)/2
    if (front < rear) {
        MergeSort(array, front, mid);
        MergeSort(array, mid + 1, rear);
        Merge(array, front, mid, rear);
    }
}

int main() {

    int array[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = 9 - i;
        //cout << array[i] << endl;
    }
    MergeSort(array, 0, 10);
    for (int i : array) {
        cout << i << endl;
    }

    return 0;
}