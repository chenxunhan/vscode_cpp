#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

bool has(int n){
	int t;
	while(n){
		t=n%10;
		if(t==2||t==4){
			return 1;
		}
		n/=10;
	}
	return 0;
} 

bool ok(int a,int b,int c){
	if((0<a)&&(a<b)&&(b<c)){
		return 1;
	}
	return 0;
}


int sum=0;
int main(){
	FILE *fa=fopen("fa.txt","w");
	
	for(int i=1;i<=2019;++i){
		for(int j=i+1;j<=2019;++j){
			int a=i-0,b=j-i,c=2019-j;
			//cout<<i-0<<" "<<j-i<<" "<<2019-j<<endl;
			if(ok(a,b,c)&& (!has(a))&& (!has(b))&& (!has(c))){
				++sum;
				//fprintf(fa,"%d %d %d\n",a,b,c);
				//cout<<i<<" "<<j-i<<" "<<2019-j<<endl;
			}
		}
	}
	printf("\n\nsum:%d",sum);
	//cout<<"\n\nsum:"<<sum;//40785
	
	
	return 0;
}

