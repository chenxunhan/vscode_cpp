#include <bits/stdc++.h>
using namespace std;

//���浱ǰѡ�������������ʽ�ĸ���������
// int a = 0, b = 0;
int res[100];
string restr;
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

void savestr(int len) {
    if (isanother == 1) { //�Ƿ��Ѿ�׼������µ�һ��
        // printf("%d=", n);
        restr += to_string(n) + "=";
        isanother = 0;
    }
    for (int i = 0; i < len - 1; ++i) { //�����������������
        // printf("%d+", res[i]);
        restr += to_string(res[i]) + "+";
    }
    // printf("%d", res[len - 1]);
    restr += to_string(res[len - 1]);
    ++sum;
    if (res[1] == 1 || len == 1) { //������Ӧ����һ�еĴ�ʽ���Ѿ�ȫ�����
        if (res[0] == 1)
            // printf(".\n");
            restr += ".\n";
        else
            // printf(";\n");
            restr += ";\n";
        isanother = 1;
        return;
    }
    // printf(","); //������Ӧ����һ�еĴ�ʽ�ӻ�δȫ�����
    restr += ",";
}

void IntDiv2(int rest, int len, int mindiv) {
    if (rest == 0) {  //��������Ѿ��������
        savestr(len); //���ʽ��
        return;
    }
    // ++a;
    for (int i = min(rest, mindiv); i >= 1; --i) { //�����ɻ��ֵ����ֵ��������
        res[len] = i;                              //�����ֽ�ջres
        // ++b;
        IntDiv2(rest - i, len + 1, i); //���ݽ�����һ��
        //��һ����������˵��(ʣ������ֵ���,���ֽ�ջ�󳤶�+1,�ٻ��ֵ������е����������)
        res[len] = 0; //�����˳���ѡ������ֳ�ջ
    }
}

int main() {
    while (1) {
        printf("�����������:");
        sum = 0; //��������������
        // a = b = 0;
        if (!(~scanf("%d", &n)))
            break;
        double time0 = clock();
        IntDiv2(n, 0, n);
        printf("%s", restr.c_str());
        printf("�������ɻ��ֵ�ʽ���������:%d\n", sum);

        printf("%lf\n", (double) ((clock() - time0) / CLOCKS_PER_SEC));
        // cout << a << "+" << b;
        putchar('\n');
    }

    return 0;
}