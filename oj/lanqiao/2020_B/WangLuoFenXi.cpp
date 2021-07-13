#include<bits/stdc++.h>

using namespace std;

const int MAXNODENUM=10000+5;
int nodeNum,cmdNum;
class Node{
    public:
        // int id;
        int dadId;
        int value=0;
        int dis=0;
}node[MAXNODENUM];

int findDadId(int nid){
    // int t=nid;
    // while(node[nid].dadId!=t){
    //     t=node[nid].dadId;
    //     node[nid].dadId=findDadId(t);
    //     node[nid].dis+=node[t].dis;//
    // }
    // return t;

    if(node[nid].dadId!=nid){
        int root=findDadId(node[nid].dadId);//已经保证node[node[nid].dadId].dis正确地把他前面的dis都加了
        node[nid].dis+=node[node[nid].dadId].dis;
        node[nid].dadId=root;
    }
    return node[nid].dadId;
}

bool setUnion(int aid,int bid){
    int afid=findDadId(aid),bfid=findDadId(bid);
    if(afid!=bfid){
        node[bfid].dadId=afid;
        node[bfid].dis=node[bfid].value-node[afid].value;
    }
}

int realValue(int nid){
    return node[findDadId(nid)].value+node[nid].dis;
}

int main(){
    scanf("%d%d",&nodeNum,&cmdNum);
    for(int i=1;i<=nodeNum;++i)
        node[i].dadId=i;
    for(int i=1,t,a,b;i<=cmdNum;++i){
        scanf("%d%d%d",&t,&a,&b);
        (--t)?node[findDadId(a)].value+=b:setUnion(a,b);
    }
    for(int i=1;i<=nodeNum;++i)
        printf("%d ",realValue(i));
    return 0;
}