#include<bits/stdc++.h>

using namespace std;

int a[20]={0};

int getdeep(int n){
	int deep=0;
	while(n){
		n>>=1;
		++deep;
	}
	return deep;
}

int N,t;
int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>t;
		a[getdeep(i)]+=t;
	}
	int mv=-1,md=1;
	for(int i=1;i<=20;++i){
		if(a[i]>mv){
			mv=a[i];
			md=i;
		}
	}
	cout<<md;
	/*
	int n;
	while(cin>>n){
		cout<<getdeep(n)<<endl;
	}*/
	return 0;
}

/*
1
2--
4--
8--

deep
2^(deep-1)~2^deep-1

*/
