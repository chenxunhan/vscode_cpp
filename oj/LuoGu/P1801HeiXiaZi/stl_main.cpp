#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=2e5+5;

int addNum,orderNum,addi=0;
int addEle[MAXSIZE];

class{
    private:
    int nowi=0;    
priority_queue<int,vector<int>,less<int>> greaterHeap; //da
priority_queue<int,vector<int>,greater<int>> lessHeap; //xiao
    void adjust(){
            while(greaterHeap.size()>nowi){
                lessHeap.push(greaterHeap.top());
                greaterHeap.pop();
            }
            while(greaterHeap.size()<nowi){
                greaterHeap.push(lessHeap.top());
                lessHeap.pop();       
        }
    }
    public:
    void push(int e){
        if(!greaterHeap.size()||e<=greaterHeap.top()){
            greaterHeap.push(e);
        }else{
            lessHeap.push(e);
        }
    }
    int get_nowi_num(){
        ++nowi;
        adjust();
        return greaterHeap.top();
    }
}speheap;


int main(){
    scanf("%d%d",&addNum,&orderNum);
    for(int i=1;i<=addNum;++i){
        scanf("%d",addEle+i);
    }
    for(int i=1,order;i<=orderNum;++i){
        scanf("%d",&order);
        while(addi<order){
            speheap.push(addEle[++addi]);
        }
            printf("%d\n",speheap.get_nowi_num());
        
    }
    return 0;
}