#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int arr[MAXN], tr[MAXN]; //ԭ�������״����, ��Сһ��+5
int n, m;
int lowbit(int x) {
    return x & -x;
}
void updata(int i, int c) //�޸���״����iλ�õ�ֵ+c
{
    for (; i <= n; i += lowbit(i))
        tr[i] += c;
}
void build() {
    for (int i = 1; i <= n; i++) {
        //cin>>arr[i];
        updata(i, arr[i]); //ע�ⲻ��arr[i]
    }                      //һ��ʼ�ȸ���ֵ
}
int query(int i) //��ѯ����[1~i]������ͣ�
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main() {
    //build
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
    }
    build();
    int tp, x, y;
    while (m--) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 2) { //tp==2
            printf("%d\n", query(y) - query(x - 1));
            continue;
        }
        updata(x, y);
    }

    return 0;
}