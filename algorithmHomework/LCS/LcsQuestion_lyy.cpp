#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char x[] = "_ABCBDAB", y[] = "_BDCABA";
int max(int a, int b) {
    //���Ϊ1����ȡ�������ֵ�����Ϊ2����ȡ����� ��
    //����a�������ֵ��b���ϱߵ�ֵ

    return (a > b ? a : b);
}

//�жϲ��ó������
void Consequence(int **a, int i, int j) //��mem���鴫��ȥ,��һ�δ���ȥ�Ĳ���i��j �ֱ���xl-1��yl-1.
{
    int m = i, n = j;
    if (a[m][n] == 0) {
        return;
    }

    if (a[m][n] == 1) //����
    {
        m = m - 1; //�м�һ���в���
        n = n;
        Consequence(a, m, n); //�ݹ�
    } else if (a[m][n] == 2)  //����
    {
        m = m;
        n = n - 1;
        Consequence(a, m, n); //�ݹ�
    } else if (a[m][n] == 3)  //б����
    {
        m = m - 1;
        n = n - 1;
        Consequence(a, m, n); //�ݹ� S
        //����б���ϵ�Ҫ�������
        printf("%c", x[m - 1]);
    } else {
        Consequence(a, m, n);
    }
}

int main() {
    //���㴦���������ݣ������x[0]��y[0]�á�_�����»��ߣ������

    int x_len = sizeof(x); //ȡ���鳤��
    int y_len = sizeof(y);

    int i, j; //��������±�

    int c[x_len][y_len], mem[x_len][y_len];
    for (i = 0; i <= x_len; i++)
        for (j = 0; j <= y_len; j++) {
            c[i][j] = 0;
            mem[i][j] = 0;
        } //��ʼ������

    //!!!!!!?Ϊʲôֱ�� int c[x_len][y_len],mem[x_len][y_len]������������������⡣

    //ֱ�ӳ�ʼ��Ϊ0���򷽱��˲��ÿ���i=0 or j=0 ʱ��c[i][j]=0������ˡ�
    //�����������������

    for (i = 1; i < x_len - 1; i++) {
        for (j = 1; j < y_len - 1; j++) {
            if (x[i] == y[j]) //ֱ�Ӵӵڶ��������ʼ���ǡ�
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                mem[i][j] = 3;
                //��¼�������飬��ʱ��¼��3��Ϊȡ�˶ԽǱ��ϵ�ֵ ��

            } else if (x[i] != y[j]) {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]); //����ĸ�������ֲ���ͬʱ��ȡ�������󷽺��Ϸ������ֵ����һ��max����
                if (c[i][j] == c[i][j - 1])              //���ȡ����ߣ������
                {
                    mem[i][j] = 1;
                    //��¼�������飬��ʱ��¼��2��Ϊȡ�����ֵ ��
                } else { //ȡ���Ϸ������
                    mem[i][j] = 2;
                    //��¼�������飬��ʱ��¼��1��Ϊȡ���ϱ�ֵ ��
                }
            }
        }
    }
    //		Printfmem();��ӡ��Ǻ���
    printf("\n");
    printf("*************************************************\n");
    printf("\n");
    printf("���Ǳ�Ǻ�����\n");
    printf("���У�3����ȡ�Խ��ߵ�ֵ��2����ȡ��ߵ�ֵ��1����ȡ�Ϸ���ֵ\n");
    for (i = 0; i < x_len - 1; i++) {
        for (j = 0; j < y_len - 1; j++) {
            printf("%4d", mem[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("*************************************************\n");

    //	PrintfC();��ӡ�洢����
    printf("*************************************************\n");
    printf("\n");
    printf("���Ǵ��溯����\n");

    for (i = 0; i < x_len - 1; i++) {
        for (j = 0; j < y_len - 1; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("*************************************************\n");
    printf("\n");

    //���������Ա�Ǻ��������жϡ�
    printf("��������\n");
    //Consequence(int **a,int i,int j)
    Consequence((int **) mem, x_len, y_len);

    return 0;
}
