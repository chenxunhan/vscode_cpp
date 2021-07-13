#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD=123456789;
int n;
LL sum=0;
int ele8(int e){
	int time=8;
	LL ret=1;
	while(time--){
		ret*=e;
		ret%=MOD;
	}
	return ret;
}

int main(){
//	scanf("%d",&n);
//n=987654;
n=1000000;
	for(int i=1;i<=n;++i){
		sum+=ele8(i);
		sum%=MOD;
	}
	printf("%lld",sum);
	return 0;
}