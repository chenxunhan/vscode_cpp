#include<bits/stdc++.h>
using namespace std;

const int MAXNODENUM = 20;

struct{
    //int no;
    int weight;
    int dadNodeNo;
    int linkDadDis;
} treeNode[MAXNODENUM];

int edgeNum, serviceNum;
int sonDadDis[MAXNODENUM][MAXNODENUM];

int main(int argc, char **argv){

    scanf("%d%d",&edgeNum,&serviceNum);
    // int weight, dadNodeNo, linkDadDis;
    for (int i = 1;i<edgeNum; ++i){
        scanf("%d%d%d",&treeNode[i].weight,&treeNode[i].dadNodeNo,&treeNode[i].linkDadDis);
        
    }

    for (int selectedNodeNum = 1;selectedNodeNum <=edgeNum+1; ++selectedNodeNum){
        for (int setServiceNum = 0;setServiceNum <=serviceNum; ++setServiceNum){

        }
    }

        return 0;
}