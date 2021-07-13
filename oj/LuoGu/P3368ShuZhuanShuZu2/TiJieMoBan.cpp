
//区间修改，单点查询
// 原理：来介绍一下差分
// 设数组a[]={1,6,8,5,10}，那么差分数组b[]={1,5,2,-3,5}
// 也就是说b[i]=a[i]-a[i-1];(a[0]=0;)，那么a[i]=b[1]+....+b[i];(这个很好证的)。
// 假如区间[2,4]都加上2的话
// a数组变为a[]={1,8,10,7,10}，b数组变为b={1,7,2,-3,3};
// 发现了没有，b数组只有b[2]和b[5]变了，因为区间[2,4]是同时加上2的,所以在区间内b[i]-b[i-1]是不变的.
// 所以对区间[x,y]进行修改,只用修改b[x]与b[y+1]:
// b[x]=b[x]+k;b[y+1]=b[y+1]-k;

// 是树状数组的一个拓展,在树状数组中可以用前 i 项的和来表示第 i 个数.
// 那么当对 x ~ y 的区间进行修改的时候需要在树状数组中的第 x 个位置 + k, 第 y + 1 个位置 -k
// 这样便维护了这个树状数组
// 输出时候直接输出查询即可

int arr[],tr[];//原数组和树状数组, 大小一样+5
//树状数组存放的是arr[]的差分，tr[1]=arr[1]
int n;
int lowbit(int x) {
	return x&-x;
}
void updata(int i,int c)//修改树状数组i位置的值+c
{
	for(;i<=n;i+=lowbit(i)) tr[i]+=c;
}
//区间修改
//将原数组arr[a~b]之间都+c，相当于在tr[]维护的差分数组arr[a]+=c,arr[b+1]-=c
void uprange(int a,int b,int c){
    updata(a, c);
    updata(b + 1, -c);
}
//建立差分树状数组
void build() {
    arr[0] = 0;//注意
    for(int i=1;i<=n;i++){
        //cin>>arr[i]; 要求arr[i]正确 可以合并在main中就不用存在build了
        updata(i,arr[i]-arr[i-1]);//使用updata建树
    }//一开始先赋初值
}
int 'getdata/query'(int i)//查询差分数组区间[1~i]的区间和；就相当于修改后的arr[i]
{
	int res=0;
	for(;i>0;i-=lowbit(i)) res+=tr[i];
	return res; 
}
usage:
    用之前先 build();
    //单点arr[i]查询就是tr[]维护的差分数组的[1~i]的总和=query(i)