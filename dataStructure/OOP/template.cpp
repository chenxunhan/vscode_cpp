#include <climits>
#include <iostream>
using namespace std;

//ͷ���ܳ����������ʶ���д��
template <typename T1, typename T2>
class Sample {
  private:
    T1 a;
    T2 b;

  public:
    Sample(T1, T2);
    ~Sample();
    void dispType();
};

//<>��Ҫ������ȷ������
template <typename T1, typename T2>
Sample<T1, T2>::Sample(T1 t1, T2 t2) {
    a = t1;
    b = t2;
}

template <typename T1, typename T2>
Sample<T1, T2>::~Sample() {
}

//ע����Ϻ�������
template <typename T1, typename T2>
void Sample<T1, T2>::dispType() {
    cout << (a) << endl
         << (b);
}

int main() {

    //��ȷ�����
    Sample<long long, double> s((long long) (INT_MAX) *2, 3.33533);
    //��ȷ�����
    Sample<long long, double> s(2LL * INT_MAX, 3.33533);
    //����ȷ���
    Sample<long long, double> s(2L * INT_MAX, 3.33533);
    
    //����ȷ���
    Sample<long long, double> s(2 * INT_MAX, 3.33533);
    
    s.dispType();
    return 0;
}