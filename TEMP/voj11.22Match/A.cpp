#include<cstdio>
#include<stack>
using namespace std;

typedef struct Fraction
{
    int a;
    int b;
};


void trans(char *exp,char postexp[]){
    char e;
    stack<char> Optr;
    int i = 0;
    while (*exp!=0)
    {
        switch (*exp)
        {
        case '(':
            Optr.push('(');
            ++exp;
            break;
        case ')':
            Optr.push
        default:
            break;
        }
    }
    
}

int main(){

    return 0;
}