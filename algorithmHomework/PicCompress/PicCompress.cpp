#include <bits/stdc++.h>
const int MAXLENGTH = 30; //ͼ��Ҷ�ֵ������󳤶�

/*
����ע����Ҫ˵��:
�������������»���������
�������������շ�������
length�ǳ���֮��, �������еĳ���
bits  �Ǳ���λ����֮��, ���� һ�����ػ��������� ��(��)�Ҷ�ֵ����λռλ, ����λ���Ƕ�����ռλ
length ������� bits
����ĩ�˴����»��ߴ����βλ��߷�ȫ�ֱ��� eg.pixels_length_
*/

/*pixels_header_bits: ����ͷ����λ, part_maxlength: �����������Ҷ�ֵ����,
��ʼ����pixels_header_bits=11, part_maxlength=256*/
int pixels_header_bits, part_maxlength; //pixel: ����
//pixels[i]: ͼ��Ҷ�ֵ���еĵ�i���Ҷ�ֵ(����i: 1~pixles_length, ���Ҷ�ֵ: 0~255), pixels_length: ���г���
int pixels[MAXLENGTH], pixels_length;

//pixel_bits[i]: pixels[i]ռ�õı���λ, ����:255(11111111B)ռλ8, 0(00000000B)ռλ1, 8(00001000B)ռλ3
int pixel_bits[MAXLENGTH];
//compress_bits_memorandum[i]: ������¼ѹ��pixels[1~i]��ö�ͼ��ռ�ñ���λ
int compress_bits_memorandum[MAXLENGTH]; //memorandum: ����¼

/*lastpart_length[i]:��Ǻ���1 ��¼ ѹ��pixels[1~i]�� 
pixels[i]��Ϊ���һ������ �����һ���Ҷ�ֵʱ �����һ�ε����г���*/
int lastpart_length[MAXLENGTH];
/*lastpart_maxbit[i]:��Ǻ���2 ��¼ ѹ��pixels[1~i]�� 
pixels[i]��Ϊ���һ������ �����һ���Ҷ�ֵʱ �����һ�ε����е�ÿ���Ҷ�ֵ����(���)ռ�ñ���λ*/
int lastpart_maxbit[MAXLENGTH];

//eachpart_length[i]: ѹ������pixels���i�λҶ�ֵ���еĳ���(����i: 1~parts_number), parts_number: �ֶ�����
int eachpart_length[MAXLENGTH], parts_number;

//��ʼ��������Ϣ, ��ͼ��Ҷ�ֵ���С�ͼ��Ҷ�ֵ���г��ȡ���ͷռ�ñ���λ���������Ҷ�ֵ�洢���� ��ʼ��
void initPixels(const int pixels_[], const int &pixels_length_,
                const int &pixels_header_bits_, const int &part_maxlength_) {
    for (int i = 1; i <= pixels_length_; ++i)
        pixels[i] = pixels_[i - 1];
    pixels_length = pixels_length_;
    pixels_header_bits = pixels_header_bits_;
    part_maxlength = part_maxlength_;
}

//�����ʼ����Ϣ, ͼ��Ҷ�ֵ���С�ͼ��Ҷ�ֵ���г��ȡ���ͷռ�ñ���λ���������Ҷ�ֵ����
void printPixelsMessage() {
    printf("[����ͷռλ: %d bits, ���ֶ����ռλ: %d bits]\n\n", pixels_header_bits, part_maxlength);
    printf("ͼ�����ػҶ�ֵ����: <");
    for (int i = 1; i < pixels_length; ++i)
        printf("%d,", pixels[i]);
    printf("%d>\n", pixels[pixels_length]);
    printf("���ػҶ�ֵ���г���: %d\n\n", pixels_length);
}

//����ʮ����numռ�õı���λ
int bitLength(int num) {
    if (num == 0) //�����0����ռ1λ
        return 1;
    int length = 0;
    while (num != 0)         //�������λ����δ����
        ++length, num >>= 1; //����λ����+1, num����λ����1λ
    return length;
}

/*��λѹ��pixels[], �����
compress_bits_memorandum[], pixel_bits[], lastpart_length[], lastpart_maxbit[]
��������˵�������Ϸ�ע��*/
void compressPixels() {
    int current_max_bits;                      //��ʱ����������λ
    compress_bits_memorandum[0] = 0;           //ͼ�񳤶�Ϊ0ʱѹ����ͼ��ռλ0
    for (int i = 1; i <= pixels_length; ++i) { //��ʱ����ѹ��pixels[1~i]��ó��ĸ�����Ϣ
        pixel_bits[i] = bitLength(pixels[i]);  //��¼ͼ��Ҷ�ֵ���е�i���Ҷ�ֵ�ı���λ
        current_max_bits = INT_MIN;            //������ʱ������λ������
        compress_bits_memorandum[i] = INT_MAX; //����ѹ��pixels[1~i]��ö�ͼ��ռ�ñ���λ������

        for (int j = 1, j_end = std::min(i, part_maxlength); j <= j_end; ++j) { /*Ϊ�˼������һ�����г��ȵ�����ȡֵ,
        ���һ�����г��� j ��Ҫ�� 1 ������ part_maxlength, 
        ��Ȼͼ������С��part_maxlengthʱ, ������ͼ����󳤶Ⱦ�ͣ����, Ҳ���Ǳ����� min(i, part_maxlength) */
            current_max_bits = std::max(pixel_bits[i - j + 1], current_max_bits);
            //�������һ������pixels[i-j+1 ~ pixels_length]�����лҶ�ֵ��������λ
            if (compress_bits_memorandum[i] > compress_bits_memorandum[i - j] + j * current_max_bits) {
                /*���������һ�ָ�����г���Ϊjʱ, ����һ��ռ�ñ���λ �� ����pixels����ǰ���ε�����ռ�ñ���λ �ĺ�
                С�ڵ�ǰ����¼�а����˶�����pixels����ռ�ñ���λ, ����pixels����ռ�ñ���λΪ�����С�ı���λֵ*/
                compress_bits_memorandum[i] = compress_bits_memorandum[i - j] + j * current_max_bits;
                /*����˵��:
                compress_bits_memorandum[i]: ��Ҫһֱ������С����ֵ��ѹ��pixels[1~i]��ö�ͼ��ռ�õı���λ,
                compress_bits_memorandum[i - j]: �������ѹ��pixels[1~ i-j]��ö�ͼ��ռ�õ���С����λ,
                j * current_max_bits: ���һ���ֶ�pixels[i-j+1 ~ pixels_length]��ռ�ñ���λ:
                ���һ���ֶεĳ��� * �÷ֶ������е����ص�������ռ�õı���λ(�ö����Ҷ�ֵռ�ñ���λ)*/
                lastpart_length[i] = j;                //��¼���һ���ָ��εĳ���
                lastpart_maxbit[i] = current_max_bits; //��¼���һ���ָ����е�������λ
            }
        }
        compress_bits_memorandum[i] += pixels_header_bits; /*Ϊѹ��pixels[1~i]��ö�ͼ��ռ�õı���λ
                                                            ���������һ�εĶ�ͷ����Ҫռ�õı���λ*/
    }
}

//Ϊ�˶����·� ����¼ �� β�γ� ����������˵����Ϣ
void printFormat() {
    printf("�±���:");
    for (int i = 1; i <= pixels_length; ++i)
        printf(" [%3d]", i);
    printf("\n�Ҷ�ֵ:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", pixels[i]);
}

//�������¼
void printCompressLengthMemorandum() {
    printf("\n����¼:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", compress_bits_memorandum[i]);
}

//���ѹ��ͼ��� ���ӻҶ�ֵ������ ���ָ��εĶγ�
void printLastpartLength() {
    printf("\nβ�γ�:");
    for (int i = 1; i <= pixels_length; ++i)
        printf("%5d ", lastpart_length[i]);
    printf("\n\n");
}

/*����β�γ����� ���ݽ� ѹ������pixels[] ��
 ���ָ��εĳ��ȵ� eachpart_length[]
�� �ָ��ε���Ŀ�� parts_number ��*/
void TrackbackLastpartLength() {
    int pixels_index = pixels_length, //�����±��β����ǰ����
        parts_index = 1;              //�ָ���±�
    while (pixels_index != 0) {       //�������±�δ��ͷ��, ��������β�γ���eachpart_length[]��

        eachpart_length[parts_index++] = lastpart_length[pixels_index]; //�����һ�εĶγ�������eachpart_length[]��
        pixels_index -= lastpart_length[pixels_index];                  //���������±��������һ��
    }
    //����ָ�ε���Ŀ��parts_number
    parts_number = --parts_index; //���ݵ��ڵ�ʱ, ��һ�ζγ������, parts_index��+1, ���Ҫ����ȥ
    //�Ϸ��Ǵ�β����ͷ����, �������򱣴�β�γ�, �����Ҫ��תeachpart_length����, ʹ�����򱣴�
    for (int i = 1; i < parts_index; ++i, --parts_index) {
        std::swap(eachpart_length[i], eachpart_length[parts_index]);
    }
}

/*����ָ�ε���Ϣ: 
ѹ�����ͼ���С������(�ڼ���)���γ�(ÿ�λҶ�ֵ����)����λ(ÿ�θ��Ҷ�ֵռλ)������Ϣ(ÿ�εĻҶ�ֵ����)*/
void printPartsMessage() {
    printf("ѹ�����ͼ���С:%d bits\n", compress_bits_memorandum[pixels_length]);
    printf("[����][�γ�][��λ] <����Ϣ...>\n");
    for (int i = 1, pixels_index = 1, current_pixelindex_end = 0; i <= parts_number; ++i) {
        printf("%4d  %4d  %4d  ", i, eachpart_length[i], lastpart_maxbit[pixels_index]);
        current_pixelindex_end += eachpart_length[i]; //���¶���Ϣ��������һ���±�λ
        printf(" <");                                 //�¼����������Ϣpixels[pixels_index ~ current_pixelindex_end]
        while (pixels_index < current_pixelindex_end)
            printf("%d,", pixels[pixels_index++]);
        printf("%d>\n", pixels[pixels_index++]);
    }
}
int main() {
    // int pixels_[] = {10, 12, 15, 255, 1, 2}; //��1
    int pixels_[] = {1, 1, 0, 1, 233, 28, 58, 60};      //��2
    int pixels_length_ = sizeof(pixels_) / sizeof(int); //�Զ��������ػҶ�ֵ����

    initPixels(pixels_, pixels_length_, 11, 256); //��ʼ��������Ϣ
    printPixelsMessage();                         //�����ʼ����Ϣ
    compressPixels();                             //��λѹ������
    printFormat();                                //���˵����Ϣ
    printCompressLengthMemorandum();              //�������¼
    printLastpartLength();                        //���ѹ��ͼ��� ���ӻҶ�ֵ������ ���ָ��εĶγ�
    TrackbackLastpartLength();                    //����
    printPartsMessage();                          //����ָ�ε���Ϣ
    return 0;
}
