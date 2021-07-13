//#include<cstdio>
//#include<queue>
#include<bits/stdc++.h>
using namespace std;
priority_queue;

const int MAXSIZE=100;
//father:n/2 lson:n*2 rson:n*2+1
class Hgt {
	public:
		int ele[MAXSIZE]={0};
		int size() {
			return &ele[0];
		}
		void up(int idx) {
			while(idx>1&&ele[idx]>ele[idx/2]){
				swap(ele[idx],ele[idx/2]);
				idx/=2;
			}
		}
		void down(int idx){
			int maxidx;
			while(idx<=size()&&(maxidx=idx*2)&&(ele[idx]<ele[maxidx]||ele<ele[maxidx+1])){
				(ele[maxidx]<ele[maxidx+1]&&(++maxidx));
				if(maxidx>size()){
					return ;
				}
				swap(ele[idx],ele[maxidx]);
				idx=maxidx;
			}
		}
		void push(int x) {
			ele[++size()]=x;
			up(eNum);
		}
		void pop(int x) {
			swap(ele[1],ele[size()]);
			--size();
			down(1);
		}
		int top(){
			return ele[1];
		}

};

int main() {
	srand(time(NULL));
	for(int i=0; i<MAXSIZE; ++i) {

	}
	return 0;
}