#include <iostream>

int TakeUpPowOf2(int num)
{
    if(num & num - 1)
    {
        num |= num>>1;
        num |= num>>2;
        num |= num>>4;
        num |= num>>8;
        num |= num>>16;
        num |= num>>32;
        return num + 1;
    }
    return num;
}

int main()
{
    int cases;
    std::cin>>cases;
    while(cases--)
    {
        int n;
        std::cin>>n;
        std::cout<<"Input value: "<<n<<'\n'<<TakeUpPowOf2(n)<<'\n'<<std::endl;
    }
    
    return 0;
}