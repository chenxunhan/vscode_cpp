#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXTABLELENGTH = 15; //定义方格区域F的最大边长常量

//fpin:文件输入流,fpout:文件输出流
FILE *fpin, *fpout;
//tableLength:样本输入的方格区域F的边长n
int tableLength;
//table[x][y]:样本输入的方格区域F的第x行第y列方格位置的样本价值 1<=x,y<=tableLength
int table[MAXTABLELENGTH][MAXTABLELENGTH] = {0};
/*dpMaxValue[0 / 1][x1][x2]: 不断更新存放着当前计算时刻当Rob1和Rob2各走了step(偶数 / 奇数)步后
Rob1 走到第 x1行第 step+2-x1列 而 Rob2走到第 x2行第 step+2-x2列 可收集的最大样本价值,
最后一个计算更新出的dpMaxValue[0][tableLength][tableLength]值就是最终的答案*/
int dpMaxValue[2][MAXTABLELENGTH][MAXTABLELENGTH];

int main() {
    fpin = fopen("input.txt", "r");   //只读方式读入程序同目录下 input.txt 输入文件
    fpout = fopen("output.txt", "w"); //只写方式读入程序同目录下 output.txt 输出文件
    fscanf(fpin, "%d", &tableLength); //读入tableLength:样本输入的方格区域F的边长n
    int x, y, v;                      //x:方格的行位置, y:方格的列位置, v:该位置的样本值

    /*读入样本输入文件中的每一行 x:方格的行位置, y:方格的列位置, v:该位置的样本值数据
    直到最后一行3个0*/
    while (fscanf(fpin, "%d%d%d", &x, &y, &v) &&
           (x || y || v)) //(x||y||v) 等价于 !(x==0 && y==0 && v==0), 即未终止读入的条件
        table[x][y] = v;  //在未到最后一行0 0 0 前进行样本位置赋值
    fclose(fpin);         //文件输入完毕, 关闭文件输入流

    //此处step并非Rob1和Rob2各走过了的步数, 一开始走过步数为0时, Rob都在第1行第1列, 因此step初始值为2
    for (int step = 2, stepLim = 2 * tableLength; step <= stepLim; ++step) { //步数遍历从起始到终点,三层循环遍历所有状态
        for (int x1 = 1, x1Lim = min(step - 1, tableLength); x1 <= x1Lim; ++x1) {
            for (int x2 = 1, x2Lim = min(step - 1, tableLength); x2 <= x2Lim; ++x2) {
                //上方pndXLim代表Rob可到达的方格行数限制: 当前已走过步数+2-1 和 方格区域F的边长n 的最小值
                dpMaxValue[step & 1][x1][x2] =
                    max( //记录着所有的四个上次状态中收集到的最大样本价值, 代表从该状态转移而来
                        max(
                            dpMaxValue[(step - 1) & 1][x1 - 1][x2],      //Rob1从左边向右走来, Rob2从上边向下走来
                            dpMaxValue[(step - 1) & 1][x1 - 1][x2 - 1]), //Rob1从左边向右走来, Rob2从上边向下走来
                        max(
                            dpMaxValue[(step - 1) & 1][x1][x2],        //Rob1从上边向下走来, Rob2从左边向右走来
                            dpMaxValue[(step - 1) & 1][x1][x2 - 1])) + //Rob1从上边向下走来, Rob2从上边向下走来
                    table[x1][step - x1] +                             //dpMaxValue加上table[x1][step - x1]
                    table[x2][step - x2] * (x1 != x2);           /*若Rob1和Rob2在此次状态走到了不同的2个格子, 
                    则table[x1][y1] != table[x2][y2],dpMaxValue要加上table[x2][step - x2]*/
            }
        }
    }
    //输出答案可获得的最大样本值到output.txt
    fprintf(fpout, "%d\n", dpMaxValue[0][tableLength][tableLength]);
    fclose(fpout);//文件输出完毕, 关闭文件输出流
    return 0;
}


