#include<bits/stdc++.h>
using namespace std;
const int N=35;
int a[N][N]={0};
int n,m;
int main(){
	
	cin>>n>>m;
	a[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!(((i+1)%2==0)&&(j%2==0))){
				a[i+1][j]+=a[i][j];
			}
			if(!((i%2==0)&&((j+1)%2==0))){
				a[i][j+1]+=a[i][j];
			}
		}
	}
	/* 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<a[n][m];
	
	return 0;
}
