#include <iostream>
using namespace std;

class Sample {
  private:
    int x, y;
    int *a;

  public:
    Sample();
    Sample(int, int, int *);
    ~Sample();
    void setXY(int, int);
};

Sample::Sample() {
    x = 0;
    y = 0;
    a = new int[10]{0};
}

//���캯�� �� ���ع��캯�� �������� ���üӺ�������
Sample::Sample(int _x, int _y, int _a[]) {
    x = _x;
    y = _y;
    a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = _a[i];
    }
}

Sample::~Sample() {
    delete a;
}

void Sample::setXY(int _x, int _y) {
    x = _x;
    y = _y;
}
