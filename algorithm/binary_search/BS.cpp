#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=100;

int arr[MAXSIZE];
/*
[start,end]而非[start,end)
如果取end), 当key>arr[]任何数
那么mid将会=end, 并在arr[mid]越界
*/
int binary_search(int start,int end, int key){
	int mid,retidx=-1;
	while(start<=end){
		mid=start+((end-start)>>1);
		if(arr[mid]>key){
			end=mid-1;
		}else if(arr[mid]<key){
			start=mid+1;
		}else{
			return mid;
		}
	}
}

int main(){
	srand((unsigned)time(NULL));
	for(int i=0;i<MAXSIZE;++i){
		arr[i]=rand()%1000;
	}
	int key=9999;
	sort(arr,arr+MAXSIZE);	
	for(int i=0;i<MAXSIZE;++i){
		if(i%5==0){
			putchar('\n');
		}
		printf("%3d:%4d  ",i,arr[i]);
	}
	cout<<"\n----------------------\n";
//	printf("%3d:%4d  ",binary_search(0,MAXSIZE,999),999);
	printf("%3d:%4d  ",lower_bound(arr,arr+MAXSIZE,key)-arr,key);
	printf("%3d:%4d  ",upper_bound(arr,arr+MAXSIZE,key)-arr,key);

	return 0;
}