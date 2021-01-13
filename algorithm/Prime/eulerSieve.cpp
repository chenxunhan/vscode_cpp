#include <bits/stdc++.h>
using namespace std;

const int END = 100;

int prime[END + 1];//放着第i个素数
int prime_number;//素数个数，也是下标

bool isprime[END];//是不是素数

/*
初始倍数2到n
是素放入里for素
倍素一积大n跳
标记倍素积非素
若倍是素倍又跳

建三娃，初始化，
倍2n，素数放，
素遍历，积大跨
标倍素，余0跳


第0个素数是2
欧拉筛(n)需要3个东西：prime[]放第i个素数，primeNumber代表有多少个素数已经放进去了，一个bool数组isPrime[]放第i个数(i属于[0,n])是不是素数
初始化素数个数和isprime全是素数
从2开始遍历到n，这个遍历数也做倍数
这个数如果是素数那就放进去prime[]
	里遍历整个prime[]，要求倍数*素数要<n
	标记倍数*素数不是素数
	如果外遍历倍数是素数的倍数，那么外遍历倍数*下一个素数将会是当前素数的倍数，后面再标记，要跳出循环
*/


//欧拉筛
void eulerSieve(int end) {
    prime_number = 0;//下标别忘了初始化
    memset(isprime, 1, sizeof(isprime));//数组无法直接{1}初始化全部1
    for (int i = 2; i <= end; ++i) {//遍历[i~指定的end]
        (isprime[i]) && (prime[prime_number++] = i);//如果没被筛到,就是素数，记录进去
        for (int j = 0; j < prime_number&&i * prime[j]<=end; ++j) {//遍历所有的prime 且 在end筛选范围内
            isprime[i * prime[j]] = 0;//i是在第一层for++的，因此是从地向上,对以每一个放在prime里的素数自始至终都是从底向上筛掉他的所有倍数的

            /*欧拉筛的难点就在于对if (i % prime[j] == 0)这步的理解，当i是prime[j]的整数倍时，
            记 m = i / prime[j]，那么 i * prime[j+1] 就可以变为 
            (    m     * prime[j+1]) * prime[j]，
            (i/prime[j]* prime[j+1]) * prime[j],
            这说明 i * prime[j+1] 是 prime[j] 的整数倍，不需要再进行标记(在之后会被 prime[j] * 某个数 标记)，对于 prime[j+2] 及之后的素数同理，直接跳出循环，这样就避免了重复标记*/
            if (i % prime[j]==0) {//不重复标记，后面再来标记
                break;
            }
        }
    }
}

int main() {
    eulerSieve(END);
    for (int i = 0; i <= END; ++i) {
        if (isprime[i]) {
            cout << i << "素数" << endl;
        } else {
            cout << i << "合数" << endl;
        }
    }
    return 0;
}