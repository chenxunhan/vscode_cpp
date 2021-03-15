#include <iostream>
#include <cstring>
bool hasSon[1005];
bool hasCic[1005];
int  father[1005];

int getFather(int p)
{
    if(father[father[p]] == father[p]){
        return father[p];
    }
    return father[p] = getFather(father[p]);
}

int main()
{
    int cases;
    std::cin>>cases;
    for(int t(1);t<=cases;++t)
    {
        int pNumber,sNumber;
        std::cin>>pNumber>>sNumber;

        for(int i(1);i<=pNumber;++i)father[i] = i;
        memset(hasSon,0,sizeof(bool)*(pNumber+1));
        memset(hasCic,0,sizeof(bool)*(pNumber+1));
        int cntCircle(0);

        for(int i(1),son,fat;i<=sNumber;++i)
        {
            std::cin>>son>>fat;
            if(son<fat)
            {
                son ^= fat;
                fat ^= son;
                son ^= fat;
                
            }
            if(father[son] != father[fat])
            {
                if(hasSon[son])hasSon[son]=false;

                father[son] = getFather(fat);

                hasSon[fat] = true;
            }
            else{
                hasCic[father[son]] = true;
            }
        }

        int cntSon(0);
        for(int i(1);i<=pNumber;++i)
        {
            hasSon[i] && ++cntSon;
        }
        for(int i(1);i<=pNumber;++i)
        {
            hasCic[i] && ++cntCircle;
        }
        std::cout<<"Night sky #"<<t<<": "<<cntSon<<" constellations, of which "<<cntCircle<<" need to be fixed.\n"<<std::endl;
    }

    return 0;
}

/*
 * 链接：https://ac.nowcoder.com/acm/contest/12794/F
来源：牛客网

3
5 4
1 2
1 3
2 3
4 5
8 5
1 2
3 4
6 7
6 8
8 7
3 2
1 2
1 3
 * */