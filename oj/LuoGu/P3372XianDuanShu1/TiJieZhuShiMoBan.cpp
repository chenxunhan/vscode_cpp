//�����޸Ĳ�ѯ
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

const int MAXN= 1e5+5;
int n, m;
ll  a[MAXN], ans_sum[4 * MAXN], tag[MAXN << 2];

//�����
inline int ls(int p) { return p << 1; }     
//�Ҷ���
inline int rs(int p) { return p << 1 | 1; } 

 //	���ϲ���ά���������
void push_up_sum(int p) {
    ans_sum[p] = ans_sum[ls(p)] + ans_sum[rs(p)];
}
void push_up_min(int p) { //max
    // ans_min[p] = min(ans_min[ls(p)], ans_min[rs(p)]);
}

void push_up_max(int p) { //max
    // ans_max[p] = max(ans_max[ls(p)], ans_max[rs(p)]);
}

// �� [l,r] ���佨���߶���,��ǰ���ı��Ϊ p
void build(int p=1, int l=1, int r=n) {
    //�������������ͬ����ô��Ȼ��Ҷ�ӽڵ�����ֻ��Ҷ�ӽڵ��Ǳ���ʵ��ֵ��
    if (l == r) {
        ans_sum[p] = a[l];
        return;
    }
    // �ݹ���������佨��
    int mid = l + (r-l >> 1);
    //�˴��������ǲ��õ��Ƕ����������Զ��������ṹ��˵�������ö��������͸��Ӷȣ��������νṹ��û��ʲô���Ե��Ż�
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    //�˴�����������Ҫͨ���ӽڵ���ά�����׽ڵ㣬����pushup��λ��Ӧ�����ڻ���ʱ
    push_up_sum(p);
}

inline void f(int p, int l, int r, ll k) {
    tag[p] = tag[p] + k;
    //�������������ͳһ�ı䣬����ans_sum����Ҫ��Ԫ�ظ�������
    ans_sum[p] = ans_sum[p] + k * (r - l + 1);
}

//���ǿ�����ʶ����f������ΨһĿ�ģ����Ǽ�¼��ǰ�ڵ������������
inline void push_down(int p, int l, int r) {
    //ÿ�θ����������ӽڵ㡣�Դ˲������´���
    int mid = l + (r-l >> 1);
    f(ls(p), l, mid, tag[p]);
    f(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}
//nl,nrΪҪ�޸ĵ�����
//l,r,pΪ��ǰ�ڵ����洢�������Լ��ڵ�ı��
inline void update(int nl, int nr, ll k, int p=1, int l=1, int r=n) {
    if (nl <= l && r <= nr) {
        ans_sum[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    //����֮ǰ��Ҳ����˵����һ�εݹ�֮ǰ����Ϊû�еݹ��û�л��ݣ�
    //�������ڻ���֮ǰ�������´��ݣ�������Ȼÿ���ڵ㶼���Ը��µ�
    push_down(p, l, r);
    int mid = l+( r-l >> 1);
    if (nl <= mid) update(nl, nr, k, ls(p), l, mid);
    if (nr > mid) update(nl, nr, k, rs(p), mid + 1, r);
    //����֮��
    push_up_sum(p);
}

// [q_x,q_x] Ϊ��ѯ����, [l,r] Ϊ��ǰ�ڵ����������, pΪ��ǰ�ڵ�ı��
ll query_sum(int q_x, int q_y, int p=1, int l=1, int r=n) {
    ll res = 0;
    if (q_x <= l && r <= q_y) return ans_sum[p];
    int mid = l+( r-l >> 1);
    push_down(p, l, r);
    if (q_x <= mid) res += query_sum(q_x, q_y, ls(p), l, mid);
    if (q_y > mid) res += query_sum(q_x, q_y, rs(p), mid + 1, r);
    return res;
}

int main() {
    int x, y;
    ll k;//ע��k��ll 

    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);

    //һ��ʼ����,1Ϊ���ڵ�,����[1~n]
    build();
    while (m--) {
        scanf("%d", &tp);
        switch (tp) {
        case 1: {
            scanf("%d%d%lld", &x, &y, &k);
            update(x, y, k);
            break;
        }
        case 2: {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query_sum(x, y));
            break;
        }
        }
    }
    return 0;
}