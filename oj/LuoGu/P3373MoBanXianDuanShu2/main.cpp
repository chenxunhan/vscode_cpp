#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int w[N];    //���������
int n, m, p; //

struct node {
    ll l, r; //��ǰ�����������
    ll sum;  //��ǰ�����Ȩֵ��
    ll add;  //��ǰ���������м�Ȩֵ�������
    ll mul;  //��ǰ���������б���Ȩֵ�������
} tr[N * 4]; //ע���������������������������Ҫ��4����

void eval(node &root, int add, int mul) {
    //���¹�ʽ�� ��root.mul * root.sum + root.add��*mul+add
    root.sum = (root.sum * mul + (root.r - root.l + 1) * add) % p;
    root.mul = root.mul * mul % p;
    root.add = (root.add * mul + add) % p;
}
void pushup(int u) // ���ӽڵ���¸��ڵ�
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}
void pushdown(int u) {
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1; //�ָ������
}
void build(int u = 1, int l = 1, int r = n) {
    if (l == r)
        tr[u] = {l, r, w[r], 0, 1}; //�������Ҷ����ˣ��ͱ���Ҷ������Ϣ
    else {
        tr[u] = {l, r, 0, 0, 1}; //���浱ǰ�ڵ����Ϣ
        int mid = l + r >> 1;
        build(u << 1, l, mid);         //�ݹ���ڵ�
        build(u << 1 | 1, mid + 1, r); //	�ݹ��ҽڵ�
        pushup(u);                     //ÿ�θ����ӽڵ���¸��ڵ�
    }
}

void modify(int u, int l, int r, int add, int mul) {
    if (tr[u].l >= l && tr[u].r <= r) {
        eval(tr[u], add, mul); //��ǰ�������䱻�������޸�����ʱ��ֱ���޸ļ��ɣ�
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;                //��ǰ�ڵ�������е�
        if (l <= mid) modify(u << 1, l, r, add, mul);    //���Ҫ�޸ĵĵط������е����ˣ���ݹ��������
        if (r > mid) modify(u << 1 | 1, l, r, add, mul); // ���Ҫ�޸ĵĵط������е���Ҷˣ���ݹ����Ҷ���
        pushup(u);                                       //�޸���֮�����ӽڵ���¸��ڵ����Ϣ
    }
}

node query(int u, int l, int r) //������l��r�����ѯ
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u]; // �����ǰ������l~r���棬��ֱ�ӷ�����Ҫ����Ϣ
    else {
        pushdown(u);
        node res;
        res.sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;                                   //ȡ��ǰ�ڵ�������е�
        if (l <= mid) res.sum += query(u << 1, l, r).sum % p, res.sum %= p; //��ѯ����ĺ͵�������������������ĺ�
        if (r > mid) res.sum += query(u << 1 | 1, l, r).sum % p, res.sum %= p;
        pushup(u);
        return res;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    build();
    node res;
    for (int i = 0, t, x, y, k; i < m; ++i) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &x, &y, &k);
            modify(1, x, y, 0, k);
            continue;
        }
        if (t == 2) {
            scanf("%d%d%d", &x, &y, &k);
            modify(1, x, y, k, 1);
            continue;
        }
        if (t == 3) {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, x, y).sum % p);
        }
    }
    return 0;
}