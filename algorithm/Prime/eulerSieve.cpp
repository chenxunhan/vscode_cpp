#include <bits/stdc++.h>
using namespace std;

const int END = 100;

int prime[END + 1];//���ŵ�i������
int prime_number;//����������Ҳ���±�

bool isprime[END];//�ǲ�������

/*
��ʼ����2��n
���ط�����for��
����һ����n��
��Ǳ��ػ�����
�������ر�����

�����ޣ���ʼ����
��2n�������ţ�
�ر����������
�걶�أ���0��


��0��������2
ŷ��ɸ(n)��Ҫ3��������prime[]�ŵ�i��������primeNumber�����ж��ٸ������Ѿ��Ž�ȥ�ˣ�һ��bool����isPrime[]�ŵ�i����(i����[0,n])�ǲ�������
��ʼ������������isprimeȫ������
��2��ʼ������n�����������Ҳ������
���������������ǾͷŽ�ȥprime[]
	���������prime[]��Ҫ����*����Ҫ<n
	��Ǳ���*������������
	�������������������ı�������ô���������*��һ�����������ǵ�ǰ�����ı����������ٱ�ǣ�Ҫ����ѭ��
*/


//ŷ��ɸ
void eulerSieve(int end) {
    prime_number = 0;//�±�����˳�ʼ��
    memset(isprime, 1, sizeof(isprime));//�����޷�ֱ��{1}��ʼ��ȫ��1
    for (int i = 2; i <= end; ++i) {//����[i~ָ����end]
        (isprime[i]) && (prime[prime_number++] = i);//���û��ɸ��,������������¼��ȥ
        for (int j = 0; j < prime_number&&i * prime[j]<=end; ++j) {//�������е�prime �� ��endɸѡ��Χ��
            isprime[i * prime[j]] = 0;//i���ڵ�һ��for++�ģ�����Ǵӵ�����,����ÿһ������prime���������ʼ���ն��Ǵӵ�����ɸ���������б�����

            /*ŷ��ɸ���ѵ�����ڶ�if (i % prime[j] == 0)�ⲽ����⣬��i��prime[j]��������ʱ��
            �� m = i / prime[j]����ô i * prime[j+1] �Ϳ��Ա�Ϊ 
            (    m     * prime[j+1]) * prime[j]��
            (i/prime[j]* prime[j+1]) * prime[j],
            ��˵�� i * prime[j+1] �� prime[j] ��������������Ҫ�ٽ��б��(��֮��ᱻ prime[j] * ĳ���� ���)������ prime[j+2] ��֮�������ͬ��ֱ������ѭ���������ͱ������ظ����*/
            if (i % prime[j]==0) {//���ظ���ǣ������������
                break;
            }
        }
    }
}

int main() {
    eulerSieve(END);
    for (int i = 0; i <= END; ++i) {
        if (isprime[i]) {
            cout << i << "����" << endl;
        } else {
            cout << i << "����" << endl;
        }
    }
    return 0;
}