#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=2e5+5;

int m,n,addi=0;
int a[MAXSIZE];

class{
    private:
    int nowi=0;    
priority_queue<int,vector<int>,less<int> > greaterHeap; //da
priority_queue<int,vector<int>,greater<int> > lessHeap; //xiao
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
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        scanf("%d",a+i);
    }
    for(int i=1,order;i<=n;++i){
        scanf("%d",&order);
        while(addi<order){
            speheap.push(a[++addi]);
        }
            printf("%d\n",speheap.get_nowi_num());
        
    }
    return 0;
}