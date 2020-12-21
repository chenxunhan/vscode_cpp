

#include <bits/stdc++.h>
/*�궨��for Ϊ loop,���ٴ�����  
register��int����Ĵ�������߱��������ٶ�*/
#define loop(i, x, y) for (register int i = x; i <= y; ++i)
using namespace std;
const int N = 100; //���з���󳤶�Ϊ100

//m:X���еĳ���  n:Y���еĳ���
int m, n;
//X: X�����ַ�������飬Y: Y�����ַ��������
char X[N], Y[N];
//�Ż�����C[i][j]: Xi��Yj������������г���,C[m][n]�������մ� X���к� Y���е�����������еĳ���
int C[N][N];
/*��Ǻ���B[i][j]: Xi��Yj�������������Ԫ��ѡȡ��Ϣ,
�����·����� StructureSequence() �� B[m][n]�� B[0][0]����ʱ�ҵ�����������еĸ�λ�ַ�
���õ��ַ�ֻ������('z','s','x'),
������Ϣ(�����ַ��������ݷ��򡪡����ݷ������)'z'�����󡪡�'��','s'�����ϡ���'��','x'����б����'�I'  */
char B[N][N];

/* ��ʼ����������ֵ���г��ȵ�ȫ�ֱ���m n�����ַ���X_��Y_�ŵ�ȫ���ַ�����X[1~m],Y[1~n]�У�����󷽺���ʹ��
ʹ��X[i]�ŵ���X���еĵ�i���ַ�����Ϊ��ʵ����û�е�0���ַ������X[0]��ŵ���Ϣ��Ч��Y[]ͬ��*/
void init(const string &X_, const string &Y_) {
    m = X_.size(), n = Y_.size(); //XY���г��ȸ�ֵ
    loop(i, 1, m)                 //X�����ַ���ֵ
        X[i] = X_[i - 1];
    loop(i, 1, n) //Y�����ַ���ֵ
        Y[i] = Y_[i - 1];
}

// ���XY���г�ʼ��Ϣ
void print_mes() {
    printf("X_length:%2d, X: %s\n", m, X + 1),
        printf("Y_length:%2d, Y: %s\n\n", n, Y + 1);
}

//����Ż�����C[][]��
void LCS() {
    C[0][0] = 0; //��0�е�0��Ϊ0����X Y���г��ȶ�Ϊ0ʱ����������г���Ϊ0
    /*�·�2��loop����:�� X1-Y1 ���ҵ���˳������� Xm-Yn ,
	Xi-Yj����ǰ׼������ ����Ϊi��X����[X0~Xi]�� ����Ϊj��Y����[Y0~Yj] ������������еĳ���,
	��������0��ʼ��1��ʼ����:��ΪX0-Y? �� X?-Y0(?������Ϸ�ȡֵ)�Ǽ��㳤��Ϊ0������,����0���ñ�������*/
    loop(i, 1, m) {             //i��X���е��ַ���������,��X����m����
        C[i][0] = 0;            //��ʼ��C[][]��0��Ϊ0����Y���г���Ϊ0ʱ����������г���Ϊ0
        loop(j, 1, n) {         //j��Y���е��ַ���������,��Y����n����
            C[0][i] = 0;        //��ʼ��C[][]��0��Ϊ0����X���г���Ϊ0ʱ����������г���Ϊ0
            if (X[i] == Y[j]) { //��X��i���ַ���Y��j���ַ����,���ַ�Ҫ����LCS
                //LCS����+1
                C[i][j] = C[i - 1][j - 1] + 1,
                B[i][j] = 'x'; //��¼���ݵ�ʱ���� ���Ϸ������
                continue;
            } //�Ϸ�continue����˴�else ,����X[i] != Y[j]
            // ��һ������
            if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j],
                B[i][j] = 's'; //��¼���ݵ�ʱ���� �Ϸ������
                continue;
            } //�˴�����ʡ�ԣ�ԭ����: (X[i] != Y[j]) && (C[i - 1][j] < C[i][j - 1])
            C[i][j] = C[i][j - 1],
            B[i][j] = 'z'; //��¼���ݵ�ʱ���� �������

            //�ڶ�������
            // if (C[i][j - 1] >= C[i - 1][j]) {

            //     C[i][j] = C[i][j - 1],
            //     B[i][j] = 'z';
            //     continue;
            // }
            // C[i][j] = C[i - 1][j],
            // B[i][j] = 's';
        }
    }
}

//�ݹ����LCS���кͳ���
//һ��ʼ����������ʹ�õ��Ǹ���ֵ���ݹ���ý��������ֵ
//@param m_ ��
void StructureSequence(const int &m_ = m, const int &n_ = n, const bool &first = 1) {
    if (!m_ || !n_) {    //m_==0 || n_==0��X��Y���е�����
        printf("LCS: "); //���LCS
        return;
    }
    switch (B[m_][n_]) {
    case 'z': //��B[][]�����
        StructureSequence(m_, n_ - 1, 0);
        break;
    case 's': //��B[][]�ϻ���
        StructureSequence(m_ - 1, n_, 0);
        break;
    default: //case 'x' ��B[][]���ϻ���
        StructureSequence(m_ - 1, n_ - 1, 0);
        printf("%c", X[m_]);
        break;
    }
    //�����һ���������ʽ�����
    first &&printf("\nlength of LCS: %d\n\n", C[m][n]);
}

//���C[][]
void print_C() {
    printf("C:X\\Y");
    loop(i, 0, n)
        printf("[%2d]", i);
    putchar('\n');
    loop(i, 0, m) {
        printf(" [%2d]", i);
        loop(j, 0, n)
            printf("%3d ", C[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

//���B[][]
void print_B() {
    printf("B:X\\Y");
    loop(i, 1, n)
        printf("[%2d]", i);
    putchar('\n');
    loop(i, 1, m) {
        printf(" [%2d]", i);
        loop(j, 1, n) //��ʽ�����������'z'����'��','s'����'��','x'����'�I'
            printf(B[i][j] == 'x'
                       ? "  �I "
                       : (B[i][j] == 'z'
                              ? "  �� "
                              : "  �� "));
    }
    putchar('\n');
}

int main() {
    //1��
    string X_ = "ABCBDAB",
           Y_ = "BDCABA";
    // //2��
    // string X_ = "13456778",
    //        Y_ = "357486782";

    init(X_, Y_);        //��ʼ��
    print_mes();         //�����ʼ����Ϣ
    LCS();               //LCS����C[][]  B[][]
    StructureSequence(); //�������LCS��Ϣ
    print_C();           //���C[][]
    print_B();           //���B[][]
    return 0;
}