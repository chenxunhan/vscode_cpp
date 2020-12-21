#include <bits/stdc++.h>
const int MAXLENGTH = 30; //图像灰度值序列最大长度

/*
代码注释重要说明:
长名变量采用下划线命名法
长名函数采用驼峰命名法
length是长度之意, 代表序列的长度
bits  是比特位长度之意, 代表 一个像素或像素序列 的(总)灰度值比特位占位, 比特位就是二进制占位
length 勿混淆于 bits
变量末端带有下划线代表形参或者非全局变量 eg.pixels_length_
*/

/*pixels_header_bits: 各段头比特位, part_maxlength: 各段序列最大灰度值长度,
初始化后pixels_header_bits=11, part_maxlength=256*/
int pixels_header_bits, part_maxlength; //pixel: 像素
//pixels[i]: 图像灰度值序列的第i个灰度值(其中i: 1~pixles_length, 各灰度值: 0~255), pixels_length: 序列长度
int pixels[MAXLENGTH], pixels_length;

//pixel_bits[i]: pixels[i]占用的比特位, 举例:255(11111111B)占位8, 0(00000000B)占位1, 8(00001000B)占位3
int pixel_bits[MAXLENGTH];
//compress_bits_memorandum[i]: 备忘记录压缩pixels[1~i]后该段图像占用比特位
int compress_bits_memorandum[MAXLENGTH]; //memorandum: 备忘录

/*lastpart_length[i]:标记函数1 记录 压缩pixels[1~i]后 
pixels[i]作为最后一段序列 的最后一个灰度值时 这最后一段的序列长度*/
int lastpart_length[MAXLENGTH];
/*lastpart_maxbit[i]:标记函数2 记录 压缩pixels[1~i]后 
pixels[i]作为最后一段序列 的最后一个灰度值时 这最后一段的序列的每个灰度值所需(最大)占用比特位*/
int lastpart_maxbit[MAXLENGTH];

//eachpart_length[i]: 压缩整段pixels后第i段灰度值序列的长度(其中i: 1~parts_number), parts_number: 分段数量
int eachpart_length[MAXLENGTH], parts_number;

//初始化各类信息, 对图像灰度值序列、图像灰度值序列长度、段头占用比特位、各段最大灰度值存储长度 初始化
void initPixels(const int pixels_[], const int &pixels_length_,
                const int &pixels_header_bits_, const int &part_maxlength_) {
    for (int i = 1; i <= pixels_length_; ++i)
        pixels[i] = pixels_[i - 1];
    pixels_length = pixels_length_;
    pixels_header_bits = pixels_header_bits_;
    part_maxlength = part_maxlength_;
}

//输出初始化信息, 图像灰度值序列、图像灰度值序列长度、段头占用比特位、各段最大灰度值长度
void printPixelsMessage() {
    printf("[各段头占位: %d bits, 各分段最大占位: %d bits]\n\n", pixels_header_bits, part_maxlength);
    printf("图像像素灰度值序列: <");
    for (int i = 1; i < pixels_length; ++i)
        printf("%d,", pixels[i]);
    printf("%d>\n", pixels[pixels_length]);
    printf("像素灰度值序列长度: %d\n\n", pixels_length);
}

//计算十进制num占用的比特位
int bitLength(int num) {
    if (num == 0) //如果是0本身占1位
        return 1;
    int length = 0;
    while (num != 0)         //如果比特位右移未到底
        ++length, num >>= 1; //比特位长度+1, num比特位右移1位
    return length;
}

/*变位压缩pixels[], 计算出
compress_bits_memorandum[], pixel_bits[], lastpart_length[], lastpart_maxbit[]
各个变量说明参阅上方注释*/
void compressPixels() {
    int current_max_bits;                      //临时保存最大比特位
    compress_bits_memorandum[0] = 0;           //图像长度为0时压缩后图像占位0
    for (int i = 1; i <= pixels_length; ++i) { //此时计算压缩pixels[1~i]后得出的各类信息
        pixel_bits[i] = bitLength(pixels[i]);  //记录图像灰度值序列第i个灰度值的比特位
        current_max_bits = INT_MIN;            //设置临时最大比特位负无穷
        compress_bits_memorandum[i] = INT_MAX; //设置压缩pixels[1~i]后该段图像占用比特位正无穷

        for (int j = 1, j_end = std::min(i, part_maxlength); j <= j_end; ++j) { /*为了计算最后一段序列长度的最优取值,
        最后一段序列长度 j 需要从 1 遍历到 part_maxlength, 
        当然图像序列小于part_maxlength时, 遍历到图像最大长度就停下来, 也就是遍历到 min(i, part_maxlength) */
            current_max_bits = std::max(pixel_bits[i - j + 1], current_max_bits);
            //更新最后一段序列pixels[i-j+1 ~ pixels_length]中所有灰度值的最大比特位
            if (compress_bits_memorandum[i] > compress_bits_memorandum[i - j] + j * current_max_bits) {
                /*当设置最后一分割段序列长度为j时, 若这一段占用比特位 与 整个pixels序列前几段的最优占用比特位 的和
                小于当前备忘录中包括此段整个pixels序列占用比特位, 更新pixels序列占用比特位为这个更小的比特位值*/
                compress_bits_memorandum[i] = compress_bits_memorandum[i - j] + j * current_max_bits;
                /*变量说明:
                compress_bits_memorandum[i]: 需要一直更新最小最优值的压缩pixels[1~i]后该段图像占用的比特位,
                compress_bits_memorandum[i - j]: 已算出的压缩pixels[1~ i-j]后该段图像占用的最小比特位,
                j * current_max_bits: 最后一个分段pixels[i-j+1 ~ pixels_length]的占用比特位:
                最后一个分段的长度 * 该分段中所有的像素点所设置占用的比特位(该段最大灰度值占用比特位)*/
                lastpart_length[i] = j;                //记录最后一个分隔段的长度
                lastpart_maxbit[i] = current_max_bits; //记录最后一个分隔段中的最大比特位
            }
        }
        compress_bits_memorandum[i] += pixels_header_bits; /*为压缩pixels[1~i]后该段图像占用的比特位
                                                            加上这最后一段的段头所需要占用的比特位*/
    }
}

//为了对齐下方 备忘录 和 尾段长 输出而输出的说明信息
void printFormat() {
    printf("下标序:");
    for (int i = 1; i <= pixels_length; ++i)
        printf(" [%3d]", i);
    printf("\n灰度值:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", pixels[i]);
}

//输出备忘录
void printCompressLengthMemorandum() {
    printf("\n备忘录:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", compress_bits_memorandum[i]);
}

//输出压缩图像后 各子灰度值序列中 最后分隔段的段长
void printLastpartLength() {
    printf("\n尾段长:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", lastpart_length[i]);
    printf("\n\n");
}

/*根据尾段长数组 回溯将 压缩整段pixels[] 后
 各分隔段的长度到 eachpart_length[]
和 分隔段的数目到 parts_number 中*/
void TrackbackLastpartLength() {
    int pixels_index = pixels_length, //像素下标从尾部往前回溯
        parts_index = 1;              //分割段下标
    while (pixels_index != 0) {       //若像素下标未到头部, 继续保存尾段长到eachpart_length[]中

        eachpart_length[parts_index++] = lastpart_length[pixels_index]; //将最后一段的段长保存在eachpart_length[]中
        pixels_index -= lastpart_length[pixels_index];                  //更新像素下标跳过最后一段
    }
    //保存分割段的数目到parts_number
    parts_number = --parts_index; //回溯到第底时, 第一段段长保存后, parts_index又+1, 因此要减回去
    //上方是从尾部向头回溯, 依次逆向保存尾段长, 因此需要反转eachpart_length数组, 使其正向保存
    for (int i = 1; i < parts_index; ++i, --parts_index) {
        std::swap(eachpart_length[i], eachpart_length[parts_index]);
    }
}

/*输出分割段的信息: 
压缩完毕图像大小、段序(第几段)、段长(每段灰度值个数)、像位(每段各灰度值占位)、段信息(每段的灰度值序列)*/
void printPartsMessage() {
    printf("压缩完毕图像大小:%d bits\n", compress_bits_memorandum[pixels_length]);
    printf("[段序][段长][像位] <段信息...>\n");
    for (int i = 1, pixels_index = 1, current_pixelindex_end = 0; i <= parts_number; ++i) {
        printf("%4d  %4d  %4d  ", i, eachpart_length[i], lastpart_maxbit[pixels_index]);
        current_pixelindex_end += eachpart_length[i]; //更新段信息输出的最后一个下标位
        printf(" <");                                 //下几行输出段信息pixels[pixels_index ~ current_pixelindex_end]
        while (pixels_index < current_pixelindex_end)
            printf("%d,", pixels[pixels_index++]);
        printf("%d>\n", pixels[pixels_index++]);
    }
}
int main() {
    // int pixels_[] = {10, 12, 15, 255, 1, 2}; //例1
    int pixels_[] = {1, 1, 0, 1, 233, 28, 58, 60};      //例2
    int pixels_length_ = sizeof(pixels_) / sizeof(int); //自动计算像素灰度值长度

    initPixels(pixels_, pixels_length_, 11, 256); //初始化各类信息
    printPixelsMessage();                         //输出初始化信息
    compressPixels();                             //变位压缩计算
    printFormat();                                //输出说明信息
    printCompressLengthMemorandum();              //输出备忘录
    printLastpartLength();                        //输出压缩图像后 各子灰度值序列中 最后分隔段的段长
    TrackbackLastpartLength();                    //回溯
    printPartsMessage();                          //输出分割段的信息
    return 0;
}
