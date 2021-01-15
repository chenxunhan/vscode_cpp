#include <iostream>
using namespace std;

int main() {
    struct date {
        int year, month, day;
    } today;
    printf("%d  %d", sizeof(struct date), sizeof(today));
    return 0;
}