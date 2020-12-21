#include<bits/stdc++.h>

using namespace std;

int N,t;
int mx,mn;
int main(){
	scanf("%d",&N);
	--N;
	scanf("%d",&t);
	mx=mn=t;
	while(N--){
		scanf("%d",&t);
		(t>mx?mx=t:(t<mn?mn=t:1));
	}
	cout<<(mx-mn)/mn+1;
	return 0;
}

