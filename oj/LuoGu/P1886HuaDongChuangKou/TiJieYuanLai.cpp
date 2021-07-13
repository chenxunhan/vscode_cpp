#include <cstdio>
#include <cstring>
using namespace std;

struct Monotone_queue {
    static const int MAXN = 1000001;
    int n, k, a[MAXN];
    int q[MAXN], head, tail, p[MAXN]; //ͬ��Ŀ����һ����q�ǵ������У�p�Ƕ�Ӧ��š�

    void read() {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
    } //���벻��˵��

    void monotone_max() //�������ֵ
    {
        head = 1;
        tail = 0;
        for (int i = 1; i <= n; ++i) {
            while (head <= tail && q[tail] <= a[i])
                tail--;
            q[++tail] = a[i];
            p[tail] = i;
            while (p[head] <= i - k)
                head++;
            if (i >= k) printf("%d ", q[head]);
        }
        printf("\n");
    }

    void monotone_min() {//�󴰿�����Сֵ
        head = 1, tail = 0;//head�ϸ��Ӧ��Ԫ��tail�ϸ��ӦβԪ�����Ե�tail>=headʱ��˵����Ԫ�ء���һ��ʼ����Ϊ�գ�soҪ������ֵ����ʵ�����ͨ����һ����
        for (int i = 1; i <= n; ++i) { //a[i]��ʾ��ǰҪ�����ֵ

            while (head <= tail && q[tail] >= a[i]) --tail;/*ֻҪ��������Ԫ�أ�����
            βԪ�رȴ�����ֵ�󣬼���ʾβԪ���Ѿ������ܳ�����so���ӡ�
            ֱ��βԪ��<������ֵ������"����"��  */ 

            q[++tail] = a[i]; //������ֵ���
            p[tail] = i;      //ͬʱ��������
            while (p[head] <= i - k) ++head;//�������Ԫ���Ѿ�"��ʱ"������
            if (i >= k) printf("%d ", q[head]); //�����ֵ��������Ԫ�ء�i>=k��ʾ�����������why���Լ�����Ŀ
        }
        printf("\n");
    }
} worker;

int main() {
    worker.read();
    worker.monotone_min();
    worker.monotone_max();
    return 0;
}