#include<bits/stdc++.h>
#define loop(i,x,y) for(register int i=x;i<y;++i)
using namespace std;

//choose 7 in 49
bool used[50];

int a[8];

void ci(int a[]){
	for(int i=1;i<=7;++i){
		for(int u=1;u<=49;++u){
			if(used[u]==0&&u>a[i-1]){
				used[u]=1;
				
			}
		}
	}
}
