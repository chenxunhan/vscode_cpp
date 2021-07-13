#include <iostream>
using namespace std;

class A{
    #define size size()
    int size() { return 2; }
} a;

int main() {
    return 0;
}