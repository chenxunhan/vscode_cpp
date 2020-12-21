//1452: [蓝桥杯2019初赛]平方和
#include<bits/stdc++.h>
#define loop(i,x,y) for(register int i=x;i<y;++i)
using namespace std;

typedef unsigned long long ull;

bool has(int num){
	int a;
	while(num){
		a=num%10;
		if(a==1||a==2||a==0||a==9){
			return true;
		}
		num/=10;
	}
	return 0;
}

ull sum=0;

int main(){
	loop(i,1,2019+1){
		if(has(i)){
			sum+=i*i;
		}
	}
	printf("%llu",sum);
	return 0;
}
