#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXTABLELENGTH = 15; //���巽������F�����߳�����

//fpin:�ļ�������,fpout:�ļ������
FILE *fpin, *fpout;
//tableLength:��������ķ�������F�ı߳�n
int tableLength;
//table[x][y]:��������ķ�������F�ĵ�x�е�y�з���λ�õ�������ֵ 1<=x,y<=tableLength
int table[MAXTABLELENGTH][MAXTABLELENGTH] = {0};
/*dpMaxValue[x1][y1][x2][y2]: ��x1+y1=x2+y2
Rob1 �ߵ��� x1�е� y1�� �� Rob2�ߵ��� x2�е� y2�� ���ռ������������ֵ,
dpMaxValue[tableLength][tableLength][tableLength][tableLength]�������յĴ�,
�����и�ע���: ��x1+y1!=x2+y2�����������Ϊ0, ������ȷ����*/
int dpMaxValue[MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH] = {0};

int main() {
    fpin = fopen("input.txt", "r");   //ֻ����ʽ�������ͬĿ¼�� input.txt �����ļ�
    fpout = fopen("output.txt", "w"); //ֻд��ʽ�������ͬĿ¼�� output.txt ����ļ�
    fscanf(fpin, "%d", &tableLength); //����tableLength:��������ķ�������F�ı߳�n
    int x, y, v;                      //x:�������λ��, y:�������λ��, v:��λ�õ�����ֵ

    /*�������������ļ��е�ÿһ�� x:�������λ��, y:�������λ��, v:��λ�õ�����ֵ����
    ֱ�����һ��3��0*/
    while (fscanf(fpin, "%d%d%d", &x, &y, &v) &&
           (x || y || v)) //(x||y||v) �ȼ��� !(x==0 && y==0 && v==0), ��δ��ֹ���������
        table[x][y] = v;  //��δ�����һ��0 0 0 ǰ��������λ�ø�ֵ
    fclose(fpin);         //�ļ��������, �ر��ļ�������
    for (int x1 = 1; x1 <= tableLength; ++x1) { //����ѭ���Ե����ϱ������е�״̬
        for (int y1 = 1; y1 <= tableLength; ++y1) {
            for (int x2 = 1; x2 <= tableLength; ++x2) {
                int y2 = x1 + y1 - x2;
                dpMaxValue[x1][y1][x2][y2] = 
                    max(//��¼�����е��ĸ��ϴ�״̬���ռ��������������ֵ, ����Ӹ�״̬ת�ƶ���
                        max(
                            dpMaxValue[x1][y1 - 1][x2 - 1][y2],  //Rob1�������������, Rob2���ϱ���������
                            dpMaxValue[x1][y1 - 1][x2][y2 - 1]), //Rob1�������������, Rob2�������������
                        max(
                            dpMaxValue[x1 - 1][y1][x2][y2 - 1],  //Rob1���ϱ���������, Rob2�������������
                            dpMaxValue[x1 - 1][y1][x2 - 1][y2])) //Rob1���ϱ���������, Rob2���ϱ���������
                    + table[x1][y1] + table[x2][y2];
                /*��Rob1��Rob2�ڴ˴�״̬�ߵ���ͬһ������, ��table[x1][y1] = table[x2][y2],
                �Ϸ�dpMaxValue[][][][]ȡ��ͬһ����������ֵ����, �����Ҫ����һ��*/
                if (x1 == x2 && y1 == y2)
                    dpMaxValue[x1][y2][x2][y2] -= table[x1][y1];
            }
        }
    }
    //����𰸿ɻ�õ��������ֵ��output.txt
    fprintf(fpout, "%d\n", dpMaxValue[tableLength][tableLength][tableLength][tableLength]);
    fclose(fpout);//�ļ�������, �ر��ļ������
    return 0;
}


    /*����:
    ��(x1,y1,x2,y2)ΪRob ��1�������ߵ���x1�е�y1�� �� ��2�������ߵ���x2�е�y2�е�״̬
    �������ת��Ϊ: ��2��Robͬʱ��A����, ÿ�ζ���һ��, ����2*(tableLength-1)��2��Robͬʱ�ߵ�B, ��ͬ�ռ������������ֵ
    ��ÿһ��2��Rob����һ���󶼻ᴦ�ڸ��Ե�λ��, 
    ��(x1,y1,x2,y2)��ת��ΪRob1�ߵ�[x1,y1], Rob2�ߵ�[x2,y2]ʱ��״̬
    ��Ϊ2��Robͬʱ�߲�ͣ��, x1+y1������x2+y2
    ��ʼ״̬AΪ(1,1,1,1), ����״̬BΪ(tableLength,tableLength,tableLength,tableLength),
    ��ÿһ��(x1,y1,x2,y2)״̬, ��dpMaxValue[x1][y1][x2][y2]��¼��Rob1��Rob2�ɹ�ͬ�ռ��������������ֵ
    ��ÿһ��״̬������һ��״̬ת��ʱ, ��4��ת�Ʒ�ʽ
    1.Rob1���ң�Rob2����
    2.Rob1���ң�Rob2����
    3.Rob1���£�Rob2����
    4.Rob1���£�Rob2����
    �������˼����֪ÿ��״̬(x1,y1,x2,y2)������״̬ת�ƶ���, 
    ���ϴ�״̬Ϊ(x'1,y'1,x'2,y'2),��ÿ��״̬ת��Rob1��Rob2������1���ϼ�2��, ���x1+y1+x2+y2 = x'1+y'1+x'2+y'2-2
    ��ÿһ��ת�ƶ�ѡ����һ��dpMaxValue[x'1][y'1][x'2][y'2]��¼�����������ֵ��״̬ת�ƶ���,
    ������dpMaxValue[x'1][y'1][x'2][y'2]�ʹ˴�״̬�ߵ����¸���table[x1][y1]��table[x2][y2]�ĺ���
    ����dpMaxValue[x1][y1][x2][y2],
    ��ô��ת�Ƶ�����״̬B(tableLength,tableLength,tableLength,tableLength)ʱ,
    dpMaxValue[tableLength][tableLength][tableLength][tableLength]�ͼ�¼��
    Rob1��Rob2ͬʱ��A����һ���ߵ�Bʱ��ͬ�ռ������������ֵ, Ҳ�������մ�,
    �������������˶�̬�滮��˼��
    */