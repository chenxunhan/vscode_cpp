#include <bits/stdc++.h>
using namespace std;
int n = 2019;
int prime[2019], primeNum = 0;
long long ans[2019 + 5];
void suShu() {
    for (int i = 2; i <= 2019; ++i) {
        bool isP = 1;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isP = 0;
                break;
            }
        }
        if (isP) {
            prime[primeNum++] = i;
        }
    }
}

int main() {
    suShu();
    ans[0] = 1;
    for (int i = 0; i < primeNum; ++i) {
        int nowPrime = prime[i];
        for (int j = 2019 - nowPrime; j >= 0; --j) {
            // for (int j = 0; j + nowPrime <= 2019;++j){
            // ans[j + nowPrime] += ans[j];
            (j + nowPrime)[ans] += j[ans];
        }
    }
    printf("%lld", ans[2019]);
    return 0;
}

// const int END = 2019;

// int prime[END + 1]; //放着第i个素数
// int prime_number;   //素数个数，也是下标

// bool isprime[END]; //是不是素数

// //欧拉筛
// void eulerSieve(int end) {
//     prime_number = 0; //下标别忘了初始化
//     memset(isprime, 1, sizeof(isprime));
//     for (int i = 2; i <= end; ++i) { //遍历[i~指定的end]
//         (isprime[i]) && (prime[prime_number++] = i);
//         for (int j = 0; j < prime_number && i * prime[j] <= end; ++j) {
//             isprime[i * prime[j]] = 0;
//             if (i % prime[j] == 0) { //不重复标记，后面再来标记
//                 break;
//             }
//         }
//     }
// }

// const int MAXN = 2050;
// int n, m;
// int ans[MAXN];
// set<int> s;
// int main() {
// eulerSieve(2019);
// n = 2019, m = 0;
// ans[0] = ans[prime[0]] = 1;
// s.insert(0);
// s.insert(prime[0]);
// // for (auto i = s.begin(); i != s.end(); ++i)
// //     printf("%d,", (*i));
// for (int ni = 1; ni < prime_number; ++ni) {
//     // for (int ni = 1; ni <= n; ++ni) {
//     auto it = s.end();
//     do {
//         --it;
//     } while (*it > prime[ni]);
//     for (; it != s.begin(); --it) {
//         // for (int i = min(m, n - m); i >= 0; --i) {
//         ans[prime[ni] + (*it)] += ans[*it];
//         s.insert(prime[ni] + (*it));
//     }
//     ans[prime[ni] + (*it)] += ans[*it];
//     s.insert(prime[ni] + (*it));
//     // m += ni;
// }
// for (auto it = s.begin(); it != s.end(); ++it)
//     printf("%d:%d\n", *it, ans[*it]);

// return 0;
// }
