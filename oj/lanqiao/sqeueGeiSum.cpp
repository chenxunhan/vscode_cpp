#include<bits/stdc++.h>

using namespace std;
const int mod=10000;

//        0 1 2 3 [4]

int f(int n){
	int a[4]={1,1,1,-1};
	for(int i=3;i+1<=n;++i){
		a[3]=(a[0]+a[1]+a[2]);
		a[3]%=mod;
		a[0]=a[1];
		a[1]=a[2];
		a[2]=a[3];
	}
	return a[3];
}
// 1  2  3  4  5  6  7
// 1, 1, 1, 3, 5, 9, 17
int main(){
	//for(int i=4;i<=10;++i)
	cout<<f(20190324)<<endl;
	//4659 
	return 0;
}
