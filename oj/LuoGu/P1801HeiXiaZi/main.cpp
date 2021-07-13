#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 2e5 + 5;
int eleNum, cmdNum;
int ele[MAXSIZE], cmd[MAXSIZE];

//大根堆
class Hgt {
  public:
    int eleNum = 0,ele[MAXSIZE] = {0};
    void up(int idx) { //大数 堆里 往根挪
        while (idx > 1 && ele[idx] > ele[idx / 2]) 
            swap(ele[idx], ele[idx / 2]),idx /= 2;
    }
    void down(int idx) { //小数 堆里 往叶挪
        int childIdx;
        while (idx * 2 <= eleNum){ //还在里面，没到底
            childIdx = idx *2;     //定位左子树
            (childIdx + 1 <= eleNum && ele[childIdx + 1] > ele[childIdx]) && ++childIdx;
            if (ele[childIdx] <= ele[idx])  break;
            swap(ele[idx], ele[childIdx]), idx = childIdx;
        }
    }
    void push(int nele) {  ele[++eleNum] = nele, up(eleNum); }
    void pop() {
        swap(ele[1], ele[eleNum]),--eleNum,down(1);
    }
    int top() { return ele[1]; }
};

//小根堆
class Hls {
  public:
    int  eleNum = 0,ele[MAXSIZE] = {0};
    void up(int idx) { //小数 堆里 往根挪
        while (idx > 1 && ele[idx] < ele[idx / 2]) 
            swap(ele[idx], ele[idx / 2]), idx /= 2;
    }
    void down(int idx) { //大数 堆里 往叶挪
        int childIdx;
        while (idx * 2 <= eleNum) { //还在里面，没到底
            childIdx = idx * 2;      //定位左子树
            (childIdx + 1 <= eleNum && ele[childIdx + 1] < ele[childIdx]) && ++childIdx;
            if (ele[childIdx] >= ele[idx])   break;
            swap(ele[idx], ele[childIdx]),  idx = childIdx;
        }
    }
    void push(int nele) {  ele[++eleNum] = nele, up(eleNum); }
    void pop() {
        swap(ele[1], ele[eleNum]),--eleNum, down(1);
    }
    int top() {return ele[1]; }
};

class {
  public:
    Hgt hgt;  Hls hls;
    int oi = 0;
    void adjust() {//这个对顶堆应该是大根堆连小根堆，因为是求升序第几个 '大' 的
        while (hgt.eleNum < oi)
            hgt.push(hls.top()), hls.pop();
        while (hgt.eleNum > oi)
            hls.push(hgt.top()), hgt.pop();
    }
    void push(int nele) {//先放大根堆
        if (hgt.eleNum == 0 || nele <= hgt.top())  hgt.push(nele);
        else   hls.push(nele);
    }
    int iTop() {
        ++oi;   adjust();
        return hgt.top();
    }
} ddheap;

int main() {
    int eleIdx = 1;
    scanf("%d%d", &eleNum, &cmdNum);
    for (int i = 1; i <= eleNum; ++i) {
        scanf("%d", ele + i);
    }
    for (int i = 1, t; i <= cmdNum; ++i) {
        scanf("%d", &t);
        while (eleIdx <= t) {
            ddheap.push(ele[eleIdx++]);
        }
        printf("%d\n", ddheap.iTop());
    }

    return 0;
}