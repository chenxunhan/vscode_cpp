#include<bits/stdc++.h>

using namespace std;

bool b[30];
int a[30][30];
int n=20;
int now=0,mx=-1;
void dfs(int pos,int num){
	if(num==5+1){
		if(now>mx){
			mx=now;
		}
		return ;
	}
	if(pos>=21){
		return ;
	}
	for(int i=1;i<=n;++i){
		if(b[i]==0){
			b[i]=1;
			now+=a[i][num];
			dfs(i+1,num+1);
			now-=a[i][num];
			b[i]=0;
		}
	}
	
} 

int main(){
	int t;
	for(int i=1;i<=20;++i){
		cin>>t;
		for(int j=1;j<=5;++j){
			cin>>a[i][j];
		}
	}
	dfs(1,1);
	cout<<"ans:"<<mx<<endl;
	//369 
	return 0;
}


//

