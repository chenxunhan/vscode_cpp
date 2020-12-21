#include <bits/stdc++.h>
using namespace std;
 
void f(const int &n){
	int *b=new int[n];
}
 
 

int main() {
	//int a(6);?=int a=6;
	int a=6;
	 int b,&c=b;
	return 0; 
}

/*
#include <bits/stdc++.h>
using namespace std;

bool peo[105] = {0};

int checknum(int i, int j) {
    int sum = 0, k = j - i + 1;
    bool has = 0;
    for (; i <= j; ++i) {
        if (peo[i] == 1) {
            has = 1;
            break;
        }
    }
    sum = (has ? 1 + k : 1);
    return sum;
}

int main() {
    peo[3] = 1;
    int mn = INT_MAX, nk;
    for (int k = 1; k <= 100; ++k) {
        if (100 % k == 0) {
            cout << k << " ";
            int now = 0;
            for (int i = 1, j = i + k - 1; j <= 100; i += k, j += k) {
                now += checknum(i, j);
            }
            if (now < mn) {
                mn = now, nk = k;
            }
            cout << now << endl;
        }
    }
    cout << nk << " " << mn;
    //k=10;
    return 0;
}
*/
