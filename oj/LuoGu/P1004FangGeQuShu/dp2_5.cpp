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
/*dpMaxValue[0 / 1][x1][x2]: ���ϸ��´���ŵ�ǰ����ʱ�̵�Rob1��Rob2������step(ż�� / ����)����
Rob1 �ߵ��� x1�е� step+2-x1�� �� Rob2�ߵ��� x2�е� step+2-x2�� ���ռ������������ֵ,
���һ��������³���dpMaxValue[0][tableLength][tableLength]ֵ�������յĴ�*/
int dpMaxValue[2][MAXTABLELENGTH][MAXTABLELENGTH];

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

    //�˴�step����Rob1��Rob2���߹��˵Ĳ���, һ��ʼ�߹�����Ϊ0ʱ, Rob���ڵ�1�е�1��, ���step��ʼֵΪ2
    for (int step = 2, stepLim = 2 * tableLength; step <= stepLim; ++step) { //������������ʼ���յ�,����ѭ����������״̬
        for (int x1 = 1, x1Lim = min(step - 1, tableLength); x1 <= x1Lim; ++x1) {
            for (int x2 = 1, x2Lim = min(step - 1, tableLength); x2 <= x2Lim; ++x2) {
                //�Ϸ�pndXLim����Rob�ɵ���ķ�����������: ��ǰ���߹�����+2-1 �� ��������F�ı߳�n ����Сֵ
                dpMaxValue[step & 1][x1][x2] =
                    max( //��¼�����е��ĸ��ϴ�״̬���ռ��������������ֵ, ����Ӹ�״̬ת�ƶ���
                        max(
                            dpMaxValue[(step - 1) & 1][x1 - 1][x2],      //Rob1�������������, Rob2���ϱ���������
                            dpMaxValue[(step - 1) & 1][x1 - 1][x2 - 1]), //Rob1�������������, Rob2���ϱ���������
                        max(
                            dpMaxValue[(step - 1) & 1][x1][x2],        //Rob1���ϱ���������, Rob2�������������
                            dpMaxValue[(step - 1) & 1][x1][x2 - 1])) + //Rob1���ϱ���������, Rob2���ϱ���������
                    table[x1][step - x1] +                             //dpMaxValue����table[x1][step - x1]
                    table[x2][step - x2] * (x1 != x2);           /*��Rob1��Rob2�ڴ˴�״̬�ߵ��˲�ͬ��2������, 
                    ��table[x1][y1] != table[x2][y2],dpMaxValueҪ����table[x2][step - x2]*/
            }
        }
    }
    //����𰸿ɻ�õ��������ֵ��output.txt
    fprintf(fpout, "%d\n", dpMaxValue[0][tableLength][tableLength]);
    fclose(fpout);//�ļ�������, �ر��ļ������
    return 0;
}


