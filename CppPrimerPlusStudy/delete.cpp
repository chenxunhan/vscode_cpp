#include<cstdio>

int *f(){
	int *a;
	a=new int[10];
	a[7]=89;
	return a;
}

int main(){
	int *ff;
	ff=f();
	printf("%d",sizeof(ff));
	for(int i=0;i<=10;++i){
		printf("%d ",ff[i]);
	}
	puts("");
	delete [] ff;
	ff=f();
	printf("%d",sizeof(ff));
	for(int i=0;i<=10;++i){
		printf("%d ",ff[i]);
	}
	puts("");
	delete ff;
	return 0;
}