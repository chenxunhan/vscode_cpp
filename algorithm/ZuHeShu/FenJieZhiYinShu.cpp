#include<bits/stdc++.h>
using namespace std;

const int N=1000000;
int primes[N], cnt;     // 存储所有质数, cnt代表有多少质数
int sum[N];     // 存储每个质数的次数
bool st[N];     // 存储每个数是否已被筛掉
vector<int> res;// 存储C(a,b)各位数字, 数字位逆反

void get_primes(int n)      // 线性筛法求素数
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int get(int n, int p)       // 求n！中的次数
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b)       // 高精度乘低精度模板
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

void printRes(int a,int b){ //求C(a,b), 并输出
//    get_primes(a);  // 预处理范围内的所有质数
    //ps: 若数据有多组, 还需要 get_primes(a)处理首次, 每次输入a更新cnt, 
    for (int i = 0,p; i < cnt; ++i)     // 求每个质因数的次数, cnt代表[1,a]中质数个数
    {
        p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p); //  a!/b!/(a-b)! 上面除以下面的，就是上面的p因数的个数 - 下面p因数的个数
    }
    res.clear();//清空
    res.push_back(1);
    for (int i = 0; i < cnt; i ++ )     // 用高精度乘法将所有质因子相乘
        for (int j = 0; j < sum[i]; j ++ )
            res = mul(res, primes[i]);

    for(int i=res.size()-1;i>=0;--i){
        printf("%d",res[i]);
    }
    puts("");//有换行
}

int main(){
	get_primes(1000);  // 预处理范围内的所有质数
	cnt=0;
	while(primes[cnt]<=100){
		++cnt;
	}
	printRes(100,60);
	
	printRes(100,60);
	return 0;
}