#include <cassert>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MAXLEN = 1000000, MAXM = 26;
int N;
char s[MAXLEN + 1];
unordered_map<int, int> HashMap;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        int temp = 0;
        //将26位bool 转成 temp特征值
        //a  b  c  d ... z
        //25 24 23 22    0
        //0代表偶数个，1代表奇数个
        for (int j = 0; j < len; ++j)
            temp ^= 1 << (s[j] - 'a');
        ++HashMap[temp];
    }
    long long ans = 0;
    for (const auto &x : HashMap) {
        int cur = x.first;        //key
        long long num = x.second; //value
        //相同特征值自个人自己拼接for(num-1 for(num))==num*(num-1)
        ans += num * (num - 1);
        for (int i = 0; i < MAXM; ++i) {
            int temp = cur ^ (1 << i);      //枚举所有only one 奇数的特征值
            if (HashMap.count(temp) > 0)    //存在HashMap[temp]
                ans += HashMap[temp] * num; //
        }
    }
    printf("%lld\n", ans >> 1);
    return 0;
}