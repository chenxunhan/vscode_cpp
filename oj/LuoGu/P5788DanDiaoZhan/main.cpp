#include<bits/stdc++.h>
using namespace std;

//单调栈常见模型：找出 每 个数 左 边离它 最近 的比它大/小(某个关系<?>)的数
const int MAXN=;
//栈大小,原数组,答案数组
int n, a[MAXN],r[MAXN];
//栈数组,栈顶id(=0为空,不是=-1)
int ddstk[MAXN],tp=0;
//返回栈顶,空栈返回-1
int top(){return !tp?-1:ddstk[tp];}
//出栈,空栈返回-1
int pop(){return !tp?-1:ddstk[tp--];}
//x进栈,返回自己
int push(int x){return ddstk[++tp]=x;}
//判断栈是否空
bool empty(){return !tp;}
//返回当前元素左边第一个满足性质 左边元素 <关系> 当前元素 的左边元素的下标 eg.关系:左边元素 > 当前元素,填 >
bool check(int e){
    return a[top()] <?> e;
}
usage:
    //初始化原数组...
    //左边第一个,如果是右边第一个,扫过来后逆过去
    for(int i=1;i<=n;++i){
        while(!empty()&&!check(a[i])) pop();
        r[i]=empty()?0:top();
        push(i);
    }
    //遍历输出答案...