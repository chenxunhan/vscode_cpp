#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, a[MAXN], belong[MAXN];
int S, C = 0, st[MAXN], ed[MAXN];
int sum[MAXN], ma_x[MAXN], mi_n[MAXN];
/*
n:Ԫ�ظ�����a[]��Ԫ�أ�belong[]:ÿ��Ԫ�������Ŀ�ı�� 
S:ÿ�����ж���Ԫ�� C:�ֿ���� st/ed:ÿ�������߽硢�ұ߽� 
sum[MAXN]/ma_x[MAXN]/mi_n[MAXN]���ڼ�¼������Ϣ 
*/
void pretreat() {
    S = int(sqrt(double(n)));
    for (int i = 1; i <= n; i += S) {
        st[++C] = i;
        ed[C] = min(i + S - 1, n); //�п��ܻ�Խ�磨sqrt��Ȼ�о�����
    }
    for (int i = 1; i <= C; i++)
        for (int j = st[i]; j <= ed[i]; j++) {
            belong[j] = i; //��ʼ��belong
            //�������
            sum[i] += a[j];
            ma_x[i] = max(ma_x[i], j);
        }
}

//���䵥���޸� ���˴����������Ϊ��
inline void updata_single(int x, int k) {
    a[x] += k;
    sum[belong[x]] += k;
}

//�����޸ģ�ͬ��
int delta[MAXN]; //���ڼ�¼һ����������������޸�
void updata_range(int x, int y, int k) {
    int l = belong[x], r = belong[y];
    if (l == r && st[l] == x && st[r] == y) {
        delta[l] = k;
        return;
    } //ma_x[]
    //���if������Ϊ�˼��ٵ��µ����㣬�Ͼ��ж�ֻ��O(1) qwq
    else {
        for (int i = x; i <= ed[l]; i++)
            updata_single(i, k); //��������������䣬�͵����޸�
        if (st[l] > x && st[r] < y) return;
        //�����ѯ���䱻ĳ������ȫ�����Ҳ���ȣ�
        //����Ҫ�������²���
        for (int i = st[r]; i <= y; i++)
            updata_single(i, k);
        //�������ѯ��������н����Ҳ����
        //����������²���
        for (int i = l + 1; i < r; i++)
            delta[i] += k;
        ;
    }
}

int query(int x, int y) //��ȻΪ�����
{
    int l = belong[x], r = belong[y], ans = 0;
    if (l == r) {
        for (int i = x; i <= y; i++)
            ans += a[i] + delta[belong[i]];
    } else {
        for (int i = x; i <= ed[l]; i++)
            ans += a[i] + delta[belong[i]];
        for (int i = l + 1; i < r; i++)
            ans += sum[i] + delta[i] * (ed[i] - st[i] + 1);
        //����ÿ�������O(1)����
        for (int i = st[r]; i <= y; i++)
            ans += a[i] + delta[belong[i]];
    }
    return ans;
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    pretreat();
    for (int i = 1, tp, x, y; i <= m; ++i) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 1) {
            updata_single(x, y);
        } else { //tp==2
            printf("%d\n", query(x, y));
        }
    }
    return 0;
}