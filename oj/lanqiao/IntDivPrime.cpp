#include <bits/stdc++.h>
using namespace std;

const int END = 2019 + 5;

int prime[END]; //放着第i个素数
// int *primet = prime - 1;
int prime_number; //素数个数，也是下标

bool isprime[END]; //是不是素数

long long res = 0;
long long table[END][END] = {0};
bool used[END][END] = {0};

//df
void dfs(int remain, int lastprime_index) {

    // if (table[remain][lastprime_index]) {
    if (used[remain][lastprime_index] || (!prime[lastprime_index])) {
        return;
    }
    // if (remain == 0) {
    //     // table[remain + prime[lastprime_index - 1]][] += 1;
    //     table[remain][lastprime_index] = 1;
    //     return;
    // }
    for (int idx = lastprime_index; prime[idx] <= remain; ++idx) {
        dfs(remain - prime[idx], idx + 1);
        table[remain][lastprime_index] += table[remain - prime[idx]][idx + 1];
        used[remain][lastprime_index] = 1;
    }
    return;
}

//欧拉筛
void eulerSieve(int end) {
    prime_number = 0;                                //下标别忘了初始化
    memset(isprime, 1, sizeof(isprime));             //数组无法直接{1}初始化全部1
    for (int i = 2; i <= end; ++i) {                 //遍历[i~指定的end]
        (isprime[i]) && (prime[prime_number++] = i); //如果没被筛到,就是素数，记录进去
        for (int j = 0; j < prime_number; ++j) {     //遍历所有的prime
            if (i * prime[j] > end) {                //如果他妈越界了
                break;
            }
            isprime[i * prime[j]] = 0; //i是在第一层for++的，因此是从地向上,对以每一个放在prime里的素数自始至终都是从底向上筛掉他的所有倍数的

            /*欧拉筛的难点就在于对if (i % prime[j] == 0)这步的理解，当i是prime[j]的整数倍时，
            记 m = i / prime[j]，那么 i * prime[j+1] 就可以变为 
            (    m     * prime[j+1]) * prime[j]，
            (i/prime[j]* prime[j+1]) * prime[j],
            这说明 i * prime[j+1] 是 prime[j] 的整数倍，不需要再进行标记(在之后会被 prime[j] * 某个数 标记)，对于 prime[j+2] 及之后的素数同理，直接跳出循环，这样就避免了重复标记*/
            if (i % prime[j] == 0) { //不重复标记，后面再来标记
                break;
            }
        }
    }
}

int main() {
    int test = 2019;
    for (int i = 0; i <= test; ++i) {
        table[0][i]used[0][i] = 1;
         = 1;
    }
    eulerSieve(test);
    dfs(test, 0);
    // cout << res;
    cout << table[test][0];
    return 0;
}