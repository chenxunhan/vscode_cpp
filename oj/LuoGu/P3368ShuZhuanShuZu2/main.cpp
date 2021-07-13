#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 5;
int arr[MAXN], tr[MAXN]; //ԭ�������״����, ��Сһ��+5
//��״�����ŵ���arr[]�Ĳ�֣�tr[1]=arr[1]
int n;
int lowbit(int x) {
    return x & -x;
}
void updata(int i, int c) //�޸���״����iλ�õ�ֵ+c
{
    for (; i <= n; i += lowbit(i))
        tr[i] += c;
}
//�����޸�
//��ԭ����arr[a~b]֮�䶼+c���൱����tr[]ά���Ĳ������arr[a]+=c,arr[b+1]-=c
void uprange(int a, int b, int c) {
    updata(a, c);
    updata(b + 1, -c);
}

int query(int i) //��ѯ�����������[1~i]������ͣ����൱���޸ĺ��arr[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}
// usage:
//     ��֮ǰ�� build();
//     //����arr[i]��ѯ����tr[]ά���Ĳ�������[1~i]���ܺ�=query(i)
int main() {
    int m;
    scanf("%d%d", &n, &m);
    //���������״����
    arr[0] = 0; //ע��
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);           //Ҫ��arr[i]��ȷ ���Ժϲ���main��
        updata(i, arr[i] - arr[i - 1]); //ʹ��updata����
    }                                   //һ��ʼ�ȸ���ֵ
    int tp;
    int x, y, k;
    while (m--) {
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d%d", &x, &y, &k);
            uprange(x, y, k);
            continue;
        }
        //tp==2
        scanf("%d", &x);
        printf("%d\n", query(x));
    }
    return 0;
}