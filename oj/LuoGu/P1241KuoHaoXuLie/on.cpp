#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE=100+5;

int alen;
char a[MAXSIZE];
bool fix[MAXSIZE];//a[i]需不需要修正

int s[MAXSIZE],top=-1;


int main(){
    scanf("%s",a);
    alen=strlen(a);

    for(int i=0;i<alen;++i){
        //左括号位置进栈
        if(a[i]=='(' or a[i]=='['){
            s[++top]=i;
            fix[i]=1;//假设需要修正
        }else{//新来右括号
            //判断有无左括号匹配
            if(top==-1/*是空栈*/ or a[s[top]]!=(a[i]==')'?'(':'[')/*匹配不对*/){
                fix[i]=1;//修理
            }else{//匹配对了
                fix[s[top]]=0;//匹配的那个重置不用修理
                --top;//被匹配了的左括号出栈
                // fix[i]=0;本身不用修理
            }
        }
    }    
    for(int i=0;i<alen;++i){
        if(a[i]=='(' or a[i]=='['){
            printf("%c",a[i]);
            fix[i] and printf("%c",a[i]=='('?')':']');
        }else{
            fix[i] and printf("%c",a[i]==')'?'(':'[');
            printf("%c",a[i]);
        }
    }
    
    return 0;
}