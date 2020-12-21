#include <bits/stdc++.h>
using namespace std;

const int END = 2019 + 5;

int prime[END]; //���ŵ�i������
// int *primet = prime - 1;
int prime_number; //����������Ҳ���±�

bool isprime[END]; //�ǲ�������

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

//ŷ��ɸ
void eulerSieve(int end) {
    prime_number = 0;                                //�±�����˳�ʼ��
    memset(isprime, 1, sizeof(isprime));             //�����޷�ֱ��{1}��ʼ��ȫ��1
    for (int i = 2; i <= end; ++i) {                 //����[i~ָ����end]
        (isprime[i]) && (prime[prime_number++] = i); //���û��ɸ��,������������¼��ȥ
        for (int j = 0; j < prime_number; ++j) {     //�������е�prime
            if (i * prime[j] > end) {                //�������Խ����
                break;
            }
            isprime[i * prime[j]] = 0; //i���ڵ�һ��for++�ģ�����Ǵӵ�����,����ÿһ������prime���������ʼ���ն��Ǵӵ�����ɸ���������б�����

            /*ŷ��ɸ���ѵ�����ڶ�if (i % prime[j] == 0)�ⲽ����⣬��i��prime[j]��������ʱ��
            �� m = i / prime[j]����ô i * prime[j+1] �Ϳ��Ա�Ϊ 
            (    m     * prime[j+1]) * prime[j]��
            (i/prime[j]* prime[j+1]) * prime[j],
            ��˵�� i * prime[j+1] �� prime[j] ��������������Ҫ�ٽ��б��(��֮��ᱻ prime[j] * ĳ���� ���)������ prime[j+2] ��֮�������ͬ��ֱ������ѭ���������ͱ������ظ����*/
            if (i % prime[j] == 0) { //���ظ���ǣ������������
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