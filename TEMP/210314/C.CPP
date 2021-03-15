#include <iostream>

int pow10(int n)
{
    int ans = 1;
    while(n--)
    {
        ans*=10;
    }
    return ans;
}
int getlen(int n)
{
    int len(0);
    while(n>0)
    {
        n/=10;
        ++len;
    }
    return len;
}
int reverse(int n,int len)
{
    int ans(0);
    while(n>0)
    {
        ans = ans*10 + n%10;
        n/=10;
    }
    return ans;
}
int toReversed(int n)
{
    int len = getlen(n);
    int length = len;
    len>>=1;

    int mark(pow10(len));
    if(length&1)
    {
        int right = n%mark;
        n/=mark;
        int m =n%10;
        n/=10;
        int &left = n;
        int rleft = reverse(left,len);
        if(right<=rleft)
            right = rleft ;
        else
        {
            if(m != 9)
            {
                m+=1;
                right = rleft;
            }
            else
            {
                left = left+1;
                m = 0;
                right = reverse(left,len);
            }
        }
        n = left*10 + m;
        n = n*mark + right;
    }
    else
    {
        int right = n%mark;
        n/=mark;
        int left = n;
        int rleft = reverse(left,len);
        if(right <= rleft)
            right = rleft;
        else
        {
            left+=1;
            right = reverse(left,len);
        }
        n = left*mark + right;
    }
    return n;
}

int main()
{
    int cases;
    std::cin>>cases;

    while(cases--)
    {
        int coins;
        std::cin>>coins;
        int tipAmounts(coins/5);
        tipAmounts*5 != coins && ++tipAmounts;
        int  &rcoins(tipAmounts);
        rcoins+=coins;
        rcoins = toReversed(rcoins);
        std::cout<<"Input cost: "<<coins<<'\n'<<rcoins - coins<<' '<<rcoins<<'\n'<<std::endl;
    }

    return 0;
}