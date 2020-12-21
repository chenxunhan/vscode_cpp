#include<bits/stdc++.h>

int main(){
	int xy;
	bool ok=1;
	for(xy=2019+2019+2;ok;++xy){
		for(int x=2020;ok&&(xy-x)>2019;++x){
			if(2*x*x==2019*2019+(xy-x)*(xy-x)){
				printf("x+y:%d,x:%d,y:%d\n",xy,x,xy-x);
				ok=0;
			}
		}
	}
	return 0;
}
