#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=100;

int arr[MAXSIZE];


//1 1 2 2 3 3 
int bls(int start, int end, int key){
	int ostart=start,mid,ret=-1;
	while(start<=end){
		mid=start+((end-start)>>1);
		if(arr[mid]>key){
			end=mid-1;
		}else if(arr[mid]<key){
			start=mid+1;
		}else{//arr[mid]==key
			if(mid==ostart||arr[mid-1]!=key){
				ret=mid;
			}
			end=mid-1;
		}
	}
	return ret;
}

int brs(int start, int end, int key){
	int oend=end, mid,ret=-1;;
	while(start<=end){
		mid=start+((end-start)>>1);
		if(arr[mid]>key){
			end=mid-1;
		}else if(arr[mid]<key){
			start=mid+1;
		}else{//arr[mid]==key
			if(mid==oend||arr[mid+1]!=key){
				ret= mid;
			}
			start=mid+1;
		}
	}
	return ret;
}
//1 3 5 7 9
int bts(int start, int end, int key){
	int ostart=start, mid,ret=-1;;
	while(start<=end){
		mid=start+((end-start)>>1);
		if(arr[mid]>key&&arr[mid-1]>key){
			end=mid-1;
		}else if(arr[mid]<key&&arr[mid+1]<key){
			start=mid+1;
		}else{
				ret= mid;
		}
	}
	return ret;
}
//1 2 3 4 5 6
int bts2(int start,int end, int key){
	int mid,retidx=-1;
	while(start<end){
		mid=start+((end-start)>>1);
		if(arr[mid]>key){
			end=mid-1;
		}else if(arr[mid]<key){
			start=mid+1;
		}
	}
	return mid;
}

int main(){
	srand((unsigned)time(NULL));
	for(int i=0;i<MAXSIZE;++i){
		arr[i]=rand()%1000;
	}
//	arr[32]=arr[33]=arr[34];
	int key=arr[33]+1;
	sort(arr,arr+MAXSIZE);	
	for(int i=0;i<MAXSIZE;++i){
		if(i%5==0){
			putchar('\n');
		}
		printf("%3d:%4d  ",i,arr[i]);
	}
	cout<<"\n----------------------\n";
//	printf("left  %d in idx:",key);
//	printf("%d\n",bls(0,MAXSIZE-1,key));
//	printf("right %d in idx:",key);
//	printf("%d\n",brs(0,MAXSIZE-1,key));
	printf("%d between %d and %d",key,bts2(0,MAXSIZE-1,key),bts2(0,MAXSIZE-1,key)+1);
	
	return 0;
}