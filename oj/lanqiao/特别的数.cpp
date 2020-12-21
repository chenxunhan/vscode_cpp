#include<bits/stdc++.h>

using namespace std;

bool has(int n){
	int t;
	while(n){
		t=n%10;
		if(t==2||t==0||t==1||t==9){
			return 1;
		}
		n/=10;
	}
	return 0;
} 

int sum=0,n;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		if(has(i)){
			sum+=i;
			//cout<<i<<endl;
		}
	}
	cout<<sum;//
	return 0;
}
