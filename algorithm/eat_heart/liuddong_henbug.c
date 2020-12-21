#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UP 5000001

int maxList[UP],minList[UP],num[UP-1];//为了方便初始化没有使用结构体
static int room=sizeof(int);

int main()
{
    int bukkit(int n);
    int resort(int n);
    
    int i,j,n,distant_1,diatant_2;
    for(j=0;j<1000;j++)
    {
        srand(j);
        n=rand()%5000000;
        
        for(i=0;i<n;i++)
        {
            num[j]=rand();
        }
        distant_1=bukkit(n);
        diatant_2=resort(n);
        if(distant_1!=diatant_2)break;
        printf("√ ");
    }
    
    if(j>=1000)printf("Error!\n%d\t%d",distant_1,diatant_2);
    
    return 0;
}

int bukkit(int n)
{
    int plusN,max,min,weigh;
    int j;
    long long posit;
    memset(minList,127,UP*room);
    memset(maxList,-1,UP*room);//初始化
    
        //偷懒用，代替n+1
        plusN=n+1;
        
        //更新最大最小值
    max=min=num[0];
    for(j=1;j<n;j++)
    {
        if(num[j]>max)max=num[j];
        else if(num[j]<min)min=num[j];
    }
        
        //若最大最小值不同
        if(max-min)
        {
            
            weigh=max-min+1;//数据范围大小
            
                //放入桶内并更新最大最小值
                for(j=0;j<n;j++)
                {
                    posit=(long long)(num[j]-min)*plusN/weigh;
                    
                    if(num[j]>maxList[posit])maxList[posit]=num[j];
                    if(num[j]<minList[posit])minList[posit]=num[j];
                }
                
                if(weigh<=n)
                {
                    maxList[plusN-1]=minList[plusN-1]=max;
                    maxList[(long long)(weigh-1)*plusN/weigh]=-1;
                }
            
                //更新最大相邻差，用max存储
                max=0;
                for (j=0;j<plusN;j++)
                {
                    while(j<plusN&&~maxList[j])j++;//寻找第一个空桶，获取其左边的桶的最大值放入posit
                    posit=maxList[j-1];
                    if(j>=plusN)break;
                    while(!~maxList[j])j++;//寻找第一个非空桶，获取其最小值与posit的差放入posit
                    posit=minList[j]-posit;
                    if(posit>max)max=posit;//尝试更新最大差值
                }
        }
        //若相同
        else
            max=0;
        
        memset(minList,127,plusN*room);
        memset(maxList,-1,plusN*room);
    
    return max;
}
int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}
int resort(int n)
{
    int max,i,distant;
    for(i=0;i<n;i++)
    {
        maxList[i]=num[i];
    }
    qsort(maxList,n,sizeof(int),comp);
    max=0;
    for(i=1;i<n;i++)
    {
        distant=maxList[i]-maxList[i-1];
        if(distant>max)max=distant;
    }
    memset(maxList,-1,UP*room);
    return max;
}
