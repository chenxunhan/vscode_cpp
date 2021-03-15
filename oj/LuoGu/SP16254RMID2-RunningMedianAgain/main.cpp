#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1e5 + 5;

//大根堆
class GreaterHeap {
  private:
  public:
    int ele[MAXSIZE] = {0};
    int eleNum = 0;
    void up(int idx) { //大数 堆里 往根挪
        while (idx > 1 && ele[idx] > ele[idx / 2]) {
            swap(ele[idx], ele[idx / 2]);
            idx /= 2;
        }
    }
    void down(int idx) { //小数 堆里 往叶挪
        int childIdx;
        while (idx * 2 <= eleNum) //还在里面，没到底
        {
            childIdx = idx * 2;                                                //定位左子树
            if (childIdx + 1 <= eleNum && ele[childIdx + 1] > ele[childIdx]) { //
                ++childIdx;
            }
            if (ele[childIdx] <= ele[idx]) {
                break;
            }
            swap(ele[idx], ele[childIdx]);
            idx = childIdx;
        }
    }
    void add(int nele) {
        ele[++eleNum] = nele;
        up(eleNum);
    }
    void removeTop() {
        swap(ele[1], ele[eleNum]);
        --eleNum;
        down(1);
    }
    int getTop() {
        return ele[1];
    }
};

//小根堆
class LessHeap {
  private:
  public:
    int ele[MAXSIZE] = {0};
    int eleNum = 0;
    void up(int idx) { //小数 堆里 往根挪
        while (idx > 1 && ele[idx] < ele[idx / 2]) {
            swap(ele[idx], ele[idx / 2]);
            idx /= 2;
        }
    }
    void down(int idx) { //大数 堆里 往叶挪
        int childIdx;
        while (idx * 2 <= eleNum) //还在里面，没到底
        {
            childIdx = idx * 2;                                                //定位左子树
            if (childIdx + 1 <= eleNum && ele[childIdx + 1] < ele[childIdx]) { //
                ++childIdx;
            }
            if (ele[childIdx] >= ele[idx]) {
                break;
            }
            swap(ele[idx], ele[childIdx]);
            idx = childIdx;
        }
    }
    void add(int nele) {
        ele[++eleNum] = nele;
        up(eleNum);
    }
    void removeTop() {
        swap(ele[1], ele[eleNum]);
        --eleNum;
        down(1);
    }
    int getTop() {
        return ele[1];
    }
};

class {
  private:
  public:
    LessHeap lessHeap;
    GreaterHeap greaterHeap;
    int medianIdx() {
        return (lessHeap.eleNum + greaterHeap.eleNum + 1) / 2;
    }

    void maintain() {
        while (lessHeap.eleNum < medianIdx()) {
            lessHeap.add(greaterHeap.getTop());
            greaterHeap.removeTop();
        }
        while (lessHeap.eleNum > medianIdx()) {
            greaterHeap.add(lessHeap.getTop());
            lessHeap.removeTop();
        }
    }

    void add(int nele) {
        if (lessHeap.eleNum == 0 || nele >= lessHeap.getTop()) {
            lessHeap.add(nele);
        } else {
            greaterHeap.add(nele);
        }
        maintain();
    }
    int getMedian() {
        return lessHeap.getTop();
    }
    void removeMedian() {
        lessHeap.removeTop();
        maintain();
    }
} specialheap;

int main() {
    int t;
    while (scanf("%d", &t) && t) {
        if (t == -1) {
            printf("%d\n", specialheap.getMedian());
            // printf("=         %d\n", specialheap.getMedian());
            specialheap.removeMedian();
            continue;
        }
        specialheap.add(t);
    }
    return 0;
}