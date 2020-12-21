//1453: [蓝桥杯2019初赛]数列求值

#include<bits/stdc++.h>
#define loop(i,x,y) for(register int i=x;i<y;++i)
using namespace std;
const int MOD=10000;
int res;
	int a[3];

void f(int k){
	a[0]=a[1]=a[2]=1;
	loop(i,3,k+1){
		int n=a[0]+a[1]+a[2];
		n%=MOD;
		a[0]=a[1],a[1]=a[2],a[2]=n;
	}
}

int main(){
	//f(20190324-1);
	//printf("%d",a[2]);
	printf("4659");
	return 0;
}
