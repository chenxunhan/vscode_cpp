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
/*dpMaxValue[x1][y1][x2][y2]: 当x1+y1=x2+y2
Rob1 走到第 x1行第 y1列 而 Rob2走到第 x2行第 y2列 可收集的最大样本价值,
dpMaxValue[tableLength][tableLength][tableLength][tableLength]就是最终的答案,
其中有个注意点: 当x1+y1!=x2+y2数组里的数据为0, 并非正确数据*/
int dpMaxValue[MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH][MAXTABLELENGTH] = {0};

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
    for (int x1 = 1; x1 <= tableLength; ++x1) { //三层循环自底向上遍历所有的状态
        for (int y1 = 1; y1 <= tableLength; ++y1) {
            for (int x2 = 1; x2 <= tableLength; ++x2) {
                int y2 = x1 + y1 - x2;
                dpMaxValue[x1][y1][x2][y2] = 
                    max(//记录着所有的四个上次状态中收集到的最大样本价值, 代表从该状态转移而来
                        max(
                            dpMaxValue[x1][y1 - 1][x2 - 1][y2],  //Rob1从左边向右走来, Rob2从上边向下走来
                            dpMaxValue[x1][y1 - 1][x2][y2 - 1]), //Rob1从左边向右走来, Rob2从左边向右走来
                        max(
                            dpMaxValue[x1 - 1][y1][x2][y2 - 1],  //Rob1从上边向下走来, Rob2从左边向右走来
                            dpMaxValue[x1 - 1][y1][x2 - 1][y2])) //Rob1从上边向下走来, Rob2从上边向下走来
                    + table[x1][y1] + table[x2][y2];
                /*若Rob1和Rob2在此次状态走到了同一个格子, 则table[x1][y1] = table[x2][y2],
                上方dpMaxValue[][][][]取了同一个格子样本值两次, 因此需要减掉一次*/
                if (x1 == x2 && y1 == y2)
                    dpMaxValue[x1][y2][x2][y2] -= table[x1][y1];
            }
        }
    }
    //输出答案可获得的最大样本值到output.txt
    fprintf(fpout, "%d\n", dpMaxValue[tableLength][tableLength][tableLength][tableLength]);
    fclose(fpout);//文件输出完毕, 关闭文件输出流
    return 0;
}


    /*解释:
    设(x1,y1,x2,y2)为Rob 第1次行走走到第x1行第y1列 而 第2次行走走到第x2行第y2列的状态
    题意可以转化为: 有2个Rob同时从A出发, 每次都走一步, 经过2*(tableLength-1)后2个Rob同时走到B, 求共同收集到的最大样本值
    在每一次2个Rob各走一步后都会处于各自的位置, 
    则(x1,y1,x2,y2)可转化为Rob1走到[x1,y1], Rob2走到[x2,y2]时的状态
    因为2个Rob同时走步停下, x1+y1会恒等于x2+y2
    初始状态A为(1,1,1,1), 最终状态B为(tableLength,tableLength,tableLength,tableLength),
    在每一个(x1,y1,x2,y2)状态, 有dpMaxValue[x1][y1][x2][y2]记录着Rob1和Rob2可共同收集到的最大样本价值
    在每一个状态进行下一步状态转移时, 有4种转移方式
    1.Rob1向右，Rob2向下
    2.Rob1向右，Rob2向右
    3.Rob1向下，Rob2向右
    4.Rob1向下，Rob2向下
    因此逆向思考可知每个状态(x1,y1,x2,y2)由四种状态转移而来, 
    设上次状态为(x'1,y'1,x'2,y'2),因每次状态转移Rob1和Rob2各走了1步合计2步, 因此x1+y1+x2+y2 = x'1+y'1+x'2+y'2-2
    若每一次转移都选择上一个dpMaxValue[x'1][y'1][x'2][y'2]记录着最大样本价值的状态转移而来,
    并利用dpMaxValue[x'1][y'1][x'2][y'2]和此次状态走到的新格子table[x1][y1]和table[x2][y2]的和来
    更新dpMaxValue[x1][y1][x2][y2],
    那么当转移到最终状态B(tableLength,tableLength,tableLength,tableLength)时,
    dpMaxValue[tableLength][tableLength][tableLength][tableLength]就记录着
    Rob1和Rob2同时从A出发一起走到B时共同收集到的最大样本值, 也就是最终答案,
    上述分析运用了动态规划的思想
    */