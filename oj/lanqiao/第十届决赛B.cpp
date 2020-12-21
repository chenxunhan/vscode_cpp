/*
2019可以被分解成若干个两两不同的素数，请问不同的分解方案有多少种？
注意：分解方案不考虑顺序，如2+2017=2019和2017+2=2019属于同一种方案

1 2 3 5 7 11 13 17 19 
1=1				1 
2=2				1 
3=1+2,3			2 
4=1+3			1 
5=2+3			1 
6=1+5,1+2+3		2 
7=1+5,1+2+3

fi:i是不是质数 
dp[i]:i的分解方案种类数目 
dp1=1,
dp2=f2+0,
dp3=f3+0,
dp4=f4+
*/ 
#include<bits/stdc++.h>
using namespace std;

bool zhi[2025]={0};

bool iszhi(int num){
	for(int i=2;i<=sqrt(num);++i){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}

void getzhi(int m=2019){
	for(int i=1;i<=m;++i){
		zhi[i]=iszhi(i);
		cout<<i<<"--"<<zhi[i]<<endl;
	}
}
int sum=0;
void dfs(int pos,int num){
	if(pos>2019||num>2019){
		return;
	}
	if(num==2019){
		++sum;
		return;
	}
	for(int i=pos;i<=2019;++i){
		if(zhi[i]==1)
			dfs(i+1,num+i);
	}
}

int main(){
	getzhi(20);
	//dfs(1,0);
	//cout<<sum;
	return 0;
}
