#include<bits/stdc++.h>

using namespace std;

int a[10]={0,1,2,3,4,5,6,7,8,9};
int main(){
	vector<int> v;
	for(int i:a){
		v.push_back(i);
	}
	for(int i:v){
		cout<<i<<endl;
	}
    return 0;
}