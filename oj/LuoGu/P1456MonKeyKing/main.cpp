#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

/*
��ƫ��:
�ϲ���,
ȡ��С���Ѷ�,
pop�Ѷ�,
�޸ĵ�i�����Ȩֵ
*/

/*��ƫ��Y��: 
���x,
��ֵ,��=-1,�h�����c�фh��
���҃��ӵ�id,
�����cid,�Á��鼯ʹ��
*/
struct Tree {
    bool ext = 1;
    int dis = 0, val = 0, ls = 0, rs = 0, rt = 0;
} tr[MAXN];

void reset(int i, int val_) {
    tr[i].dis = tr[i].ls = tr[i].rs = 0;
    tr[i].val = val_, tr[i].rt = i;
}
int n, m; //n��ʼ�т���,m������

//�ϲ�x y,x y Ҫ���Ƕ��,����merge��Ķ��
//�ϲ�������ƫ���������������ĸ��ڵ�
int merge(int x, int y) {
    if (!x || !y) { //�����һ�ô��ϲ�����Ϊ��������ϲ����Ϊ��һ����
        return x | y;
    }
    //'>/<':'С/��'����    '>/<':��ɂ����cval==,'��/��'ݔ��ĵ����ڶ���̖�^'��/С'�����Ϸ�,���ӿ������
    if (tr[x].val < tr[y].val)
        swap(x, y);
    tr[x].rs = merge(tr[x].rs, y);
    if (tr[tr[x].ls].dis < tr[tr[x].rs].dis)
        swap(tr[x].ls, tr[x].rs);
    tr[tr[x].ls].rt = tr[tr[x].rs].rt = tr[x].rt = x;//˳�㲢��
    tr[x].dis = tr[tr[x].rs].dis + 1;
    return x;
}

//���鼯������(���)
int get(int x) {
    return tr[x].rt == x ? x : tr[x].rt = get(tr[x].rt);
}

//�Ѷ��x POP��
void pop(int x) {
    tr[x].ext = 0;
    tr[x].val = -1; //�չ��cval=-1
    tr[tr[x].ls].rt = tr[x].ls, tr[tr[x].rs].rt = tr[x].rs;
}

int modify(int i, int v) {
     int nrt = merge(tr[i].ls, tr[i].rs);
    reset(i, v);
    return tr[nrt].rt = tr[i].rt = merge(nrt, i);
}

int main() {
    while (~scanf("%d", &n)) {
        tr[0].dis = -1;
        for (int i = 1, v; i <= n; ++i) {
            scanf("%d", &v);
            reset(i, v);
        }
        scanf("%d", &m);
        for (int i = 1, x, y; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            x = get(x), y = get(y);
            if (x == y) {
                puts("-1");
                continue;
            }

            int xrt, yrt;
            xrt = modify(x, tr[x].val / 2);
            yrt = modify(y, tr[y].val / 2);

            printf("%d\n", tr[merge(xrt, yrt)].val);
        }
    }
    return 0;
}