//hit mole
//cxh
//先写最快解，再写最优解
#include <bits/stdc++.h>
using namespace std;

int cix(int num) {//correct index x
    return 4 - ((num - 1) / 4 + 1); //wait better
}

int ciy(int num) {//correct index x
    return (num - 1) % 4;
}

int main() {
    int n;
    while(cin>>n){
        int input_num;
        bool root[4][4] = {0};
        while(n--){
            cin >> input_num;
            root[cix(input_num)][ciy(input_num)] = 1;
        }
    }
    return 0;
}