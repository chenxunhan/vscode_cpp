#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int a[MAXN];//ԭ����

int head, tail;
struct {int val,id;}que[MAXN];//��������,һ����val,һ����id

int n, k;//���鳤��, ���ڴ�С

void get_k_min() {//�󴰿�����Сֵ
    head = 1, tail = 0;//head�ϸ��Ӧ��Ԫ��tail�ϸ��ӦβԪ�����Ե�tail>=headʱ��˵����Ԫ�ء���һ��ʼ����Ϊ�գ�soҪ������ֵ����ʵ�����ͨ����һ����
    for (int i = 1; i < n; ++i) { //a[i]��ʾ��ǰҪ�����ֵ
        while (head <= tail && que[tail].val >= a[i]) --tail;/*ֻҪ��������Ԫ�أ�����
        βԪ�رȴ�����ֵ�󣬼���ʾβԪ���Ѿ������ܳ�����so���ӡ�
        ֱ��βԪ��<������ֵ������"����"��  */ 

        que[++tail].val = a[i]; //������ֵ���
        que[tail].id = i;      //ͬʱ��������
        while (que[head].id <= i - k) ++head;//�������Ԫ���Ѿ�"��ʱ"������
        printf("%d\n",que[head].val); //�����ֵ��������Ԫ�ء�i>=k��ʾ�����, �ܹ����n-(k-1)=n+1-k����//a[i-k+1 ~ i]�����minֵ
    }
}


int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    int t=(k-1);
    puts("0");
    get_k_min();

    return 0;
}