#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	int time0=time(NULL);
	for(int i=0;i<=INT_MAX;++i){
		if(i%1000000000==0){
//			printf("%d\n",time(NULL)-time0);
			printf("\b");
			scanf("%d\n",&a);
		}
	}


	
	return 0;
}
