#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=10000+5;

class Node{
	public:
	int dadId;
	int value;
	bool hasLeft=0;
	bool hasRight=0;
}node[MAXSIZE];

int nodeNum,kId;
int kLeftNum=0,kRightNum=0;
int kmaxv,kminv,ans=0;
bool inf=0;
int main(){
	scanf("%d%d",&nodeNum,&kId);
	for(int i=1;i<=nodeNum;++i){
		scanf("%d%d",&node[i].dadId,&node[i].value);
		if(node[node[i].dadId].value>node[i].value){
			node[node[i].dadId].hasLeft=1;
		}else{
			node[node[i].dadId].hasRight=1;
		}
	}
	int tId=kId;
	if(!node[tId].hasLeft){
		kmaxv=node[tId].value;
		while(inf==0){
			if(tId==0){
				inf=1;
				break;
			}
			if(node[node[tId].dadId].value<node[tId].value){
				kminv=node[node[tId].dadId].value;
				ans+=kmaxv-kminv-1;
				break;
			}
			tId=node[tId].dadId;
		}
	}
	if(!node[kId].hasRight){
		
		kminv=node[tId].value;
		while(inf==0){
			if(tId==0){
				inf=1;
				break;
			}
			if(node[node[tId].dadId].value>node[tId].value){
				kmaxv=node[node[tId].dadId].value;
				ans+=kmaxv-kminv-1;
				break;
			}
			tId=node[tId].dadId;
		}
	}
	if(inf){
		printf("-1");
	}else{
		printf("%d",ans);
	}
	return 0;
}
/*
4 2
0 10
1 0
1 20
3 30
*/