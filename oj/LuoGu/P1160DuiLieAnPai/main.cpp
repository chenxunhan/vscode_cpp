#include<list>
#include<cstdio>
using namespace std;
using It=list<int>::iterator;
const int MAXN=1e5+5;

It pos[MAXN];
list<int> q;
bool erased[MAXN];
int n,m;

int main(){
    scanf("%d",&n);
    
    q.push_front(1);//第一个进链表
    pos[1]=q.begin();//第一个的指针存起来
    for(int i=2,k,p;i<=n;++i){
        scanf("%d%d",&k,&p);
        if(!p){//放在左边
            pos[i]=q.insert(pos[k],i);//insert插在指针左边，返回插入之后的位置
        }else{//放在右边
        // auto t=next(pos[k]);
            pos[i]=q.insert(next(pos[k]),i);//next()和prev()指针的下一个或前一个
        }
    }
    scanf("%d",&m);
    for(int i=1,x;i<=m;++i){
        scanf("%d",&x);
        if(!erased[x]){//这家伙还活着
            q.erase(pos[x]);//把某个位置踢了（不复存在），两边的家伙接起来
        }
        erased[x]=1;//这
	}
    printf("%d",*q.begin());
    for(It it=next(q.begin());it!=q.end();++it){
        printf(" %d",*it);
    }
    puts("");
    return 0;
}
