#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 2e5 + 5;
int eleNum, cmdNum;
int ele[MAXSIZE], cmd[MAXSIZE];

//大根堆
class Hgt {
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
class Hls {
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
    Hgt greaterHeap;
    Hls lessHeap;
    int oi = 0;

    void maintain() {//这个对顶堆应该是大根堆连小根堆，因为是求升序第几个 '大' 的
        while (greaterHeap.eleNum < oi) {
            greaterHeap.add(lessHeap.getTop());
            lessHeap.removeTop();
        }

        while (greaterHeap.eleNum > oi) {
            lessHeap.add(greaterHeap.getTop());
            greaterHeap.removeTop();
        }
    }

    void add(int nele) {//先放大根堆
        if (greaterHeap.eleNum == 0 || nele <= greaterHeap.getTop()) {
            greaterHeap.add(nele);
        } else {
            lessHeap.add(nele);
        }
        maintain();
    }
    int iTop() {
        ++oi;
        maintain();
        return greaterHeap.getTop();
    }
} specialheap;

int main() {
    int eleIdx = 1;
    scanf("%d%d", &eleNum, &cmdNum);
    for (int i = 1; i <= eleNum; ++i) {
        scanf("%d", ele + i);
    }
    for (int i = 1, t; i <= cmdNum; ++i) {
        scanf("%d", &t);
        while (eleIdx <= t) {
            specialheap.add(ele[eleIdx++]);
        }
        printf("%d\n", specialheap.iTop());
    }

    return 0;
}