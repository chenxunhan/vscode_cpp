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
        //��26λbool ת�� temp����ֵ
        //a  b  c  d ... z
        //25 24 23 22    0
        //0����ż������1����������
        for (int j = 0; j < len; ++j)
            temp ^= 1 << (s[j] - 'a');
        ++HashMap[temp];
    }
    long long ans = 0;
    for (const auto &x : HashMap) {
        int cur = x.first;        //key
        long long num = x.second; //value
        //��ͬ����ֵ�Ը����Լ�ƴ��for(num-1 for(num))==num*(num-1)
        ans += num * (num - 1);
        for (int i = 0; i < MAXM; ++i) {
            int temp = cur ^ (1 << i);      //ö������only one ����������ֵ
            if (HashMap.count(temp) > 0)    //����HashMap[temp]
                ans += HashMap[temp] * num; //
        }
    }
    printf("%lld\n", ans >> 1);
    return 0;
}