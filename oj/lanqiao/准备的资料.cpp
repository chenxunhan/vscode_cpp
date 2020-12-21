

// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

// 先写出算法出来，不用优化
// 所以不变参数const优化
// 快速卡常优化
// hash分类减少枚举次数
// hashmap减少内存，使用查询

// int qpow(int a, int n, int mod) {
//     int ans = 1;
//     while (n) {
//         ((n & 1) && (ans = ans * a % mod));
//         a = a * a % mod, n >>= 1;
//     }
//     return ans;
// }