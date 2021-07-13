#include<cstdio>
#include<array>
using std::array;
int main(){
	array<int,10>a;
	for(int i=0;i<10;++i){
		a[i]=i;
	}
	for(int i=0;i<10;++i){
		printf("%d ",a[i]);
	}
	puts("");
	a[-1]=-1;
	a[-2]=-2;
	printf("%d\n",a[-2]);
	printf("%d\n",a[-2]);
	
	printf("%d\n",a[-1]);
	printf("%d\n",a[-2]);
	puts("");
	for(int i=0;i<10;++i){
		printf("%d ",a[i]);
	}
	puts("");
	printf("%d",a[-1]);
	puts("");
	
	return 0;
}