/*
��������
����2015�꣬ȫ�й�ʵ���˻���ͨ�硣��Ϊһ�����������ߣ�С�����ڰ���һ��һ·�ϵĹ���ͨ�硣
������һ�Σ�С��Ҫ���� n ����ׯͨ�磬���� 1 �Ŵ�ׯ���ÿ��Խ���һ������վ�������ĵ��㹻���д�ׯʹ�á�
�������ڣ��� n ����ׯ֮�䶼û�е���������С����ҪҪ�����Ǽ������������Щ��ׯ��ʹ�����д�ׯ��ֱ�ӻ��ӵ��뷢��վ��ͨ��
����С�����������д�ׯ��λ�ã����꣩�͸߶ȣ����Ҫ����������ׯ��С����Ҫ����������ׯ֮������������ϸ߶Ȳ��ƽ������ʽ������Ϊ����Ϊ (x_1, y_1) �߶�Ϊ h_1 �Ĵ�ׯ������Ϊ (x_2, y_2) �߶�Ϊ h_2 �Ĵ�ׯ֮�����ӵķ���Ϊ
����sqrt((x_1-x_2)(x_1-x_2)+(y_1-y_2)(y_1-y_2))+(h_1-h_2)*(h_1-h_2)��
��������ʽ�� sqrt ��ʾȡ�����ڵ�ƽ��������ע�����ŵ�λ�ã��߶ȵļ��㷽ʽ���������ļ��㷽ʽ��ͬ��
�������ھ������ޣ������С������������Ҫ���Ѷ��ٷ��ò���ʹ�� n ����ׯ��ͨ�硣
�����ʽ
��������ĵ�һ�а���һ������ n ����ʾ��ׯ��������
���������� n �У�ÿ���������� x, y, h���ֱ��ʾһ����ׯ�ĺᡢ������͸߶ȣ����е�һ����ׯ���Խ�������վ��
�����ʽ
�������һ�У�����һ��ʵ�����������뱣�� 2 λС������ʾ�𰸡�
��������
4
1 1 3
9 9 7
8 8 6
4 5 4
�������
17.41
����������ģ��Լ��
�������� 30% ������������1 <= n <= 10��
�������� 60% ������������1 <= n <= 100��
����������������������1 <= n <= 1000��0 <= x, y, h <= 10000��
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

struct country {
    double x, y, h;
};

int n;
country ct[N];
double table[N][N] = {0};
double pay;

double price(country a, country b) {
    return sqrt((a.x - b.x) * (a.x - b.x)     //
                + (a.y - b.y) * (a.y - b.y)   //
                + (a.h - b.h) * (a.h - b.h)); //
}

void inittable() {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            table[j][i] = table[i][j] = price(ct[i], ct[j]);
        }
    }
}

void prim() {
    pay = 0;
    int closet[n], minwei[n];
    for (int i = 0; i < n; ++i) {
        closet[i] = 0; //��0����ׯ
        minwei[i] = table[i][0];
    }
    double c_minwei;
    int c_closet;
    for (int added = 1; added < n; ++added) {
        c_minwei = __DBL_MAX__;
        for (int i = 0; i < n; ++i) {
            if (minwei[i] != 0) {
                if (minwei[i] < c_minwei) {
                    c_minwei = minwei[i];
                    c_closet = i;
                }
            }
        }
        pay += c_minwei;
        minwei[c_closet] = 0;
        closet[c_closet] = c_closet;
        for (int i = 0; i < n; ++i) {
            if (minwei[i] > table[c_closet][i]) {
                minwei[i] = table[c_closet][i];
                closet[i] = c_closet;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &ct[i].x, &ct[i].y, &ct[i].h);
    }
    inittable();
    prim();
    printf("%.2lf", pay);
    return 0;
}
//ɨ�����д�ׯ
//��ʼ����λ��ׯ��ͨ��
//table[i][j]==��ׯi�ʹ�ׯj�����Ӽ۸�
//prim(���ӱ�,1)
/*
closet[]
minweight[]
��ʼ������������
����n-1�μӴ�ׯ
    ����u-v��������Ľڵ㣬�ӽ�ȥ
        �Լ����Լ���minwei=0
    ������������
        ���ԭ��>�¼���Ķ���
            �޸�
*/
