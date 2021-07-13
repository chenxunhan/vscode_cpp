#include<cstdio>


//总结:
//new 出来没有释放的空间将会留在堆里
//其他新程序也无法使用,重拾,分配和释放
int main(){

	// cpp 1
//	int *a=new int[3];
//	for(int i=0;i<3;++i){
//		a[i]=i;
//	}
//	for(int i=0;i<3;++i){
//		printf("%d  ",a[i]);
//	}
//	puts("");
//	printf("a=%p",a);
	//cpp 2 
//	delete a;
	int *b=(int*)(0x7d14a0);
	for(int i=0;i<3;++i){
		printf("%d  ",b[i]);
	}
//	delete b;
	// cpp3
//	int *c=;
//	for(int i=0;i<3;++i){
//		printf("%d  ",c[i]);
//	}
//	delete c;
	return 0;
}