#include<bits/stdc++.h>
using namespace std;

bool people[200]={0,1};

int nd(int k){
    return 100/k+k;
}
int main()
{
    int m=100;//自行假设人数
    int minn=9999999;
    int k,sum,ans;
    for(k=1;k<=100;k++)
    {
        if(100%k==0)
        {
            sum=100/k+k;
        }
        else
            sum=100/k+k+1;
        if(sum<minn)//所需的试剂盒数量比较取小的
        {
            minn=sum;
            ans=k;
        }
    }
    cout<<ans<<endl;
}
