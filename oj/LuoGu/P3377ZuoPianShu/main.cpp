#include <bits/stdc++.h>
using namespace std;

#define MAXN 150010

/*
��ƫ��:

*/

/*��ƫ��Y��: 
���x,
��ֵ,��=-1,�h�����c�фh��
���҃��ӵ�id,
�����cid,�Á��鼯ʹ��
*/
struct Tree {
    int dis, val, ls,rs, rt;
} S[MAXN];

int n, m;//n��ʼ�т���,m������

//�ϲ�x y,x y Ҫ���Ƕ��,����merge��Ķ��
inline int Merge(int x, int y) {
    if(x==0||y==0){
        return x+y;
    }
    //'>/<':'С/��'����    '>/<':��ɂ����cval==,'��/��'ݔ��ĵ����ڶ���̖�^'��/С'�����Ϸ�,���ӿ������
    if (S[x].val > S[y].val || (S[x].val == S[y].val && x > y))
        swap(x, y);
    S[x].rs = Merge(S[x].rs, y);
    if (S[S[x].ls].dis < S[S[x].rs].dis) 
        swap(S[x].ls, S[x].rs);
    S[S[x].ls].rt = S[S[x].rs].rt = S[x].rt = x; 
    S[x].dis = S[S[x].rs].dis + 1;
    return x;
}

//���鼯������(���)
inline int Get(int x) {
    return S[x].rt == x ? x : S[x].rt = Get(S[x].rt);
}

//�Ѷ��x POP��
inline void Pop(int x) {
    S[x].val = -1;//�չ��cval=-1
    S[S[x].ls].rt = S[x].ls, S[S[x].rs].rt = S[x].rs;
    S[x].rt = Merge(S[x].ls, S[x].rs);
}


int main() {
    scanf("%d%d",&n,&m);
    S[0].dis = -1;////�չ��cdis=-1

    for (int i = 1; i <= n; ++i){
        S[i].rt = i; //��ʼ�������c�ĸ����c���Լ�
        scanf("%d", &S[i].val);//���낀���c�ę�ֵ
    }

    for (int i = 1,ctp,x,y,f1,f2; i <= m; ++i) {
        scanf("%d", &ctp);
        if (ctp == 1) {
            scanf("%d%d", &x,&y);
            if (S[x].val == -1 || S[y].val == -1) //�������һ���фh��
                continue;
            f1 = Get(x), f2 = Get(y);//�ҵ�x,y������f1,f2
            if (f1 != f2) //���x y����f1 f2��һ��,�_ʼ�ϲ�
                S[f1].rt = S[f2].rt = Merge(f1, f2);
        } else {
            scanf("%d",&x);
            if (S[x].val == -1)
                printf("-1\n");
            else
                printf("%d\n", S[Get(x)].val), Pop(Get(x));
        }
    }
    return 0;
}