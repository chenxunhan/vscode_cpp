#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 5;
int t, n,tp;
int arr[SIZE];
int dignum[SIZE] = {0};

int main(){
    scanf("%d",&t);
    while (t--) 
    {
        scanf("%d", &n);
        memset(dignum, 0, sizeof(n)*n/SIZE);
        arr[0] = -1;
        for(int i=1; i<=n; ++i){
            scanf("%d", arr+i);
        }
        sort(arr + 1, arr + n + 1);
        int pos=0;
        for(int i=1; i<=n; ++i){
            if(arr[i]!=arr[i-1]){
                ++pos;
                ++dignum[pos];
            }
        }

        sort(dignum,dignum+SIZE);
    }
    
    return 0;
}

100 100 4 100
nlgn 1e5
4 100 100 100
n 1e5
1 3 
nlgn
1 3  xx
n
1:=2
3:=1


xx: 1 3 5 6 8 9


#include <bits/stdc++.h>

int number[200005];

using namespace std;

int main()
{
    
    int cases;
    cin>>cases;
    
    while(cases--)
    {
        int n;
        cin>>n;
        
        for(int i(1);i<=n;++i)
        {
            cin>>number[i];
        }
        
        sort(number+1, number+n+1);
        
        int posit(0), counts(0);
        number[0] = -1;
        for(int i(1);i<=n;++i)
        {
            if(number[i] != number[i-1])
            {
                number[posit] = counts;
                posit++;
                counts = 0;
            }
            ++counts;
        }
        number[posit++] = counts;
        
        sort(number, number+posit);
        
        int maxS(0);
        for(int i(0),j(posit);i<posit;++i,--j)
        {
            if(number[i] * j > maxS)
                maxS = number[i]*j;
        }
        
        cout<<n - maxS<<'\n';
    }
    
    return 0;
}