#include<cstdio>
using namespace std;

inline void f1(int);
inline void f2(int);

int main(){
    f1(1);
    return 0;
}

inline void f1(int i){
    printf("f1: %d\n",i);
    f2(i+1);
}


inline void f2(int i){
    printf("f2: %d\n",i);
    f1(i-1);
}