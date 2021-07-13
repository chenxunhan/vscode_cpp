#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=2e5+5;
const int OB=0;
int m,n,addi=0;
int oi=0;
int a[MAXSIZE];

class{
    private:
    int oi=0;  //��oi��  
    bool ob;//  0:���oi��С�� 1:���oi�����,�ɸ�������ʡ��, ���·���ֵ
    priority_queue<int,vector<int>,less<int> > hgt; //da
    priority_queue<int,vector<int>,greater<int> > hls; //xiao
    void adjust(){
        if(ob){//1:��oi�����, hls<->hgt ,hls.size()=oi, hls.top 
            while(hls.size()>oi)
                hgt.push(hls.top()),hls.pop();
            while(hls.size()<oi)
                hls.push(hgt.top()),hgt.pop();
        }else{//1:��oi��С��, hgt<->hls ,hgt.size()=oi, hgt.top
            while(hgt.size()>oi)
                hls.push(hgt.top()),hgt.pop();
            while(hgt.size()<oi)
                hgt.push(hls.top()),hls.pop();       
        }
    }
    public:
    void push(int e,bool ob_){//ֱ���������ƶ���
        if(ob_){
            if(!hls.size()||e>=hls.top()) hls.push(e);
            else hgt.push(e);
        }else{
            if(!hgt.size()||e<=hgt.top()) hgt.push(e);
            else hls.push(e);
        }
    }
    int iTop(int oi_,bool ob_){//0:���oi��С�� 1:���oi�����
        oi=oi_,ob=ob_;
        adjust();//�ȵ���
        return ob?hls.top():hgt.top(); 
    }
}ddheap;//�Զ���


int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)
        scanf("%d",a+i);
    
    for(int i=1,u;i<=n;++i){
        scanf("%d",&u);
        while(addi<u){
            ddheap.push(a[++addi],OB);
        }
        printf("%d\n",ddheap.iTop(++oi,OB));
    }
    return 0;
}