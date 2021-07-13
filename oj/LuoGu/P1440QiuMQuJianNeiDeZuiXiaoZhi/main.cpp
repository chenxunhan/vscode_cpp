#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int a[MAXN];//原数组

int head, tail;
struct {int val,id;}que[MAXN];//单调队列,一个放val,一个放id

int n, k;//数组长度, 窗口大小

void get_k_min() {//求窗口内最小值
    head = 1, tail = 0;//head严格对应首元，tail严格对应尾元，所以当tail>=head时，说明有元素。而一开始队列为空，so要这样赋值。其实这跟普通队列一样。
    for (int i = 1; i < n; ++i) { //a[i]表示当前要处理的值
        while (head <= tail && que[tail].val >= a[i]) --tail;/*只要队列里有元素，并且
        尾元素比待处理值大，即表示尾元素已经不可能出场，so出队。
        直到尾元素<待处理值，满足"单调"。  */ 

        que[++tail].val = a[i]; //待处理值入队
        que[tail].id = i;      //同时存下其编号
        while (que[head].id <= i - k) ++head;//如果队首元素已经"过时"，出队
        printf("%d\n",que[head].val); //输出最值，即队首元素。i>=k表示该输出, 总共输出n-(k-1)=n+1-k个答案//a[i-k+1 ~ i]区间的min值
    }
}


int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    int t=(k-1);
    puts("0");
    get_k_min();

    return 0;
}