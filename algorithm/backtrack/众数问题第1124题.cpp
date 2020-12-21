//众数问题 第 1124 题.cpp
//陈逊瀚
#include <bits/stdc++.h>
using namespace std;

int arr[50005] = {0};
int table[50005]={0};

int main() {
    table[0] = 1;
    int n;
    int mode_num, repeat_num;
    cin >> n;
    for (int ni = 1; ni <= n; ++ni) {
        scanf("%d", arr + ni);
    }
    
    sort(table, arr + n);
    for (int ni = 1; ni <= n; ++ni) {
        ++table[ni];
        if(arr[ni]==arr[ni-1]){
            table[ni] += table[ni - 1];
        }
    }
    return 0;
}