#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 2e5 + 5;
int eleNum, cmdNum;
int ele[MAXSIZE], cmd[MAXSIZE];

//�����
class Hgt {
  public:
    int eleNum = 0,ele[MAXSIZE] = {0};
    void up(int idx) { //���� ���� ����Ų
        while (idx > 1 && ele[idx] > ele[idx / 2]) 
            swap(ele[idx], ele[idx / 2]),idx /= 2;
    }
    void down(int idx) { //С�� ���� ��ҶŲ
        int childIdx;
        while (idx * 2 <= eleNum){ //�������棬û����
            childIdx = idx *2;     //��λ������
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

//С����
class Hls {
  public:
    int  eleNum = 0,ele[MAXSIZE] = {0};
    void up(int idx) { //С�� ���� ����Ų
        while (idx > 1 && ele[idx] < ele[idx / 2]) 
            swap(ele[idx], ele[idx / 2]), idx /= 2;
    }
    void down(int idx) { //���� ���� ��ҶŲ
        int childIdx;
        while (idx * 2 <= eleNum) { //�������棬û����
            childIdx = idx * 2;      //��λ������
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
    void adjust() {//����Զ���Ӧ���Ǵ������С���ѣ���Ϊ��������ڼ��� '��' ��
        while (hgt.eleNum < oi)
            hgt.push(hls.top()), hls.pop();
        while (hgt.eleNum > oi)
            hls.push(hgt.top()), hgt.pop();
    }
    void push(int nele) {//�ȷŴ����
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