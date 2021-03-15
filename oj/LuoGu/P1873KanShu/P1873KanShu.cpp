#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=1e6+5;

int n,m;
int tree[MAXSIZE];

long long cutRest(int e){
	long long sum=0;
	for(int i=1;i<=n;++i){
		((tree[i]>e)&&(sum+=tree[i]-e));
	}
	return sum;
}

int find(){
	int start=1,end =1e9,mid;
	while(start<=end){
		mid=start+((end-start)>>1);
		if(cutRest(mid)<m){
			end=mid-1;
		}else{
			if(cutRest(mid+1)<m){
				return mid;
			}
			start=mid+1;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",tree+i);
	}
	printf("%d",find());
	return 0;
}