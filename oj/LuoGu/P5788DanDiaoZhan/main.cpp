#include<bits/stdc++.h>
using namespace std;

//����ջ����ģ�ͣ��ҳ� ÿ ���� �� ������ ��� �ı�����/С(ĳ����ϵ<?>)����
const int MAXN=;
//ջ��С,ԭ����,������
int n, a[MAXN],r[MAXN];
//ջ����,ջ��id(=0Ϊ��,����=-1)
int ddstk[MAXN],tp=0;
//����ջ��,��ջ����-1
int top(){return !tp?-1:ddstk[tp];}
//��ջ,��ջ����-1
int pop(){return !tp?-1:ddstk[tp--];}
//x��ջ,�����Լ�
int push(int x){return ddstk[++tp]=x;}
//�ж�ջ�Ƿ��
bool empty(){return !tp;}
//���ص�ǰԪ����ߵ�һ���������� ���Ԫ�� <��ϵ> ��ǰԪ�� �����Ԫ�ص��±� eg.��ϵ:���Ԫ�� > ��ǰԪ��,�� >
bool check(int e){
    return a[top()] <?> e;
}
usage:
    //��ʼ��ԭ����...
    //��ߵ�һ��,������ұߵ�һ��,ɨ���������ȥ
    for(int i=1;i<=n;++i){
        while(!empty()&&!check(a[i])) pop();
        r[i]=empty()?0:top();
        push(i);
    }
    //���������...