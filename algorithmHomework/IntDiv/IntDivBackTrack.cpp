#include <bits/stdc++.h>
using namespace std;

//���浱ǰѡ�������������ʽ�ĸ���������
int res[100];
//�����ֵ�����,���ֵ������
int n, sum;
//���������Ƿ�Ҫ��ʽ����������ʽ
bool isanother = 1;

//���res[]�кϷ�����������ʽ,len��ʽ�ӵĳ���
void print(int len) {
    if (isanother == 1) { //�Ƿ��Ѿ�׼������µ�һ��
        printf("%d=", n);
        isanother = 0;
    }
    for (int i = 0; i < len - 1; ++i) { //�����������������
        printf("%d+", res[i]);
    }
    printf("%d", res[len - 1]);
    ++sum;
    if (res[1] == 1 || len == 1) { //������Ӧ����һ�еĴ�ʽ���Ѿ�ȫ�����
        if (res[0] == 1)
            printf(".\n");
        else
            printf(";\n");
        isanother = 1;
        return;
    }
    printf(","); //������Ӧ����һ�еĴ�ʽ�ӻ�δȫ�����
}

//�������ֺ���
//rest�ǵ�ǰ�����ֵ���
//len��res���������ֵĳ���+1
//mindiv���ٻ��ֵ������е����������
void IntDiv(int rest, int len, int mindiv) {
    if (rest == 0) { //��������Ѿ��������
        print(len);  //���ʽ��
        return;
    }
    for (int i = min(rest, mindiv); i >= 1; --i) {   //�����ɻ��ֵ����ֵ��������
        res[len] = i;                                //�����ֽ�ջres
        IntDiv(rest - i, len + 1, min(rest - i, i)); //���ݽ�����һ��
        //��һ����������˵��(ʣ������ֵ���,���ֽ�ջ�󳤶�+1,�ٻ��ֵ������е����������)
        res[len] = 0; //�����˳���ѡ������ֳ�ջ
    }
}

int main() {
    while (1) {
        printf("�����������:");
        sum = 0; //��������������
        if (!(~scanf("%d", &n)))
            break;
        double time0 = clock();
        IntDiv(n, 0, n);
        printf("�������ɻ��ֵ�ʽ���������:%d\n", sum);
        printf("%lf", (double) ((clock() - time0) / CLOCKS_PER_SEC));
        putchar('\n');
    }

    return 0;
}