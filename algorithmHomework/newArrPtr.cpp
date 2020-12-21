// 设置一个虚拟定位循环数组函数指针
#include <bits/stdc++.h>
#define N 10
using namespace std;

int *newarr(int a[], int len, int nindex, int index) {
    return a + (index + nindex) % len;
}

class ArrayPointer {
  private:
    int *a, len, nindex;

  public:
    void init(int *a0, int len0, int nindex0) {
        a = a0, len = len0, nindex = nindex0;
    }
    int *pt(int index) {
        return a + (index + nindex) % len;
    }
} arPt;

int main() {
    int a[N];
    for (int i = 0; i < N; ++i) 
        a[i] = i;
    
    for (int i : a) 
        cout << i << " ";
    
    putchar('\n');
    int index, nindex;
    while (~scanf("%d%d", &index, &nindex)) {
        arPt.init(a, N, nindex);
        cout << *(arPt.pt(index)) << endl;
    }

    return 0;
}