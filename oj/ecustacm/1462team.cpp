#include<bits/stdc++.h>

using namespace std;

const int N=20,M=5;

int a[N+5][M+5];

bool ch[N+5];
int mx,sum;

void dfs(int num){
	if(num==6){
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=N;++i){
		if(ch[i]==0){
			ch[i]=1;
			sum+=a[i][num];
			dfs(num+1);
			sum-=a[i][num];
			ch[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	for(int i=1;i<=N;++i){
		for(int j=0;j<=M;++j){
			cin>>a[i][j];
		}
	}
	
	dfs(1);
	cout<<"res:"<<mx;
	//cout<<510;
	return 0;
} 
