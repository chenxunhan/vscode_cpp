#include <climits>
#include <iostream>
using namespace std;

//头部很长，两个单词都得写好
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

//<>里要放置正确的类型
template <typename T1, typename T2>
Sample<T1, T2>::Sample(T1 t1, T2 t2) {
    a = t1;
    b = t2;
}

template <typename T1, typename T2>
Sample<T1, T2>::~Sample() {
}

//注意加上函数类型
template <typename T1, typename T2>
void Sample<T1, T2>::dispType() {
    cout << (a) << endl
         << (b);
}

int main() {

    //正确不溢出
    Sample<long long, double> s((long long) (INT_MAX) *2, 3.33533);
    //正确不溢出
    Sample<long long, double> s(2LL * INT_MAX, 3.33533);
    //不正确溢出
    Sample<long long, double> s(2L * INT_MAX, 3.33533);
    
    //不正确溢出
    Sample<long long, double> s(2 * INT_MAX, 3.33533);
    
    s.dispType();
    return 0;
}