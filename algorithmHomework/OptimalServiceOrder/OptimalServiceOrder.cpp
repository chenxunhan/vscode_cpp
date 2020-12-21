
#include <algorithm>
#include <stdio.h>

//����ȴ�ʱ��
double waitTime(int OrderedServiceTime[], int OrderedServiceNumber) {
    double time(0);
    for (int i(0); i < OrderedServiceNumber; ++i)
        time += OrderedServiceTime[i] * (OrderedServiceNumber - i);
    return time / OrderedServiceNumber;
}

int main() {
    //̰��
    FILE *fpin = fopen("input.txt", "r");
    FILE *fpout = fopen("output.txt", "w");
    int serviceNumber;
    fscanf(fpin, "%d", &serviceNumber);
    int serviceTime[serviceNumber];
    for (int i = 0; i < serviceNumber; ++i)
        fscanf(fpin, "%d", serviceTime + i);
    std::sort(serviceTime, serviceTime + serviceNumber);
    fprintf(fpout, "%.2lf", waitTime(serviceTime, serviceNumber));
    printf("%.2lf", waitTime(serviceTime, serviceNumber));
    return 0;
}