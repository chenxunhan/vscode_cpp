#include <bits/stdc++.h>
int main() {
    double dis(4.3), hasReachDis = 0, nowStepDis(2);
    int step(0);
    // scanf("%d", &dis);
    // for (; hasReachDis < dis;) {
    //     ++step;
    //     hasReachDis += nowStepDis;
    //     nowStepDis *= 0.98;
    // }
    // printf("%d", step);
    printf("%.0lf", ceil(log(1.0 - dis / 100) / log(0.98)));
    // std::cout << ceil(log(1.0 - dis / 100) / log(0.98));
    return 0;
}

//            a1 a2 a3 a4 a5 a6 a7 a8 a9
// 2*(0.98^?) 0  1  2  3  4 5 6
// (a1(1-q^n))/(1-q)>=dis
// a1=2,q=0.98,step=n-1
// get min_n

// 1-q^n>=dis*(1-q)/a1

// 1-dis*(1-q)/a1>=q^n,
// lg()>=nlg(q)