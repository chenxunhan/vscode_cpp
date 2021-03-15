#include <iostream>
using namespace std;
class Complex {
  private:
    double i;
    double j;

  public:
    Complex(int = 0, int = 0);
    void display();
    Complex operator++();    //ǰ׺����
    Complex operator++(int); //��׺������������Ҫ��int
};

Complex::Complex(int a, int b) {
    i = a;
    j = b;
}

void Complex::display() {
    cout << i << '+' << j << 'i' << endl;
}

Complex Complex::operator++() {
    ++i;
    ++j;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++*this;
    return temp;
}



int main() {
    Complex comnum1(2, 2), comnum2, comnum3;
    cout << "��������ǰ:" << endl;
    cout << "comnum1:";
    comnum1.display();
    cout << "comnum2:";
    comnum2.display();
    cout << "comnum3:";
    comnum3.display();
    cout << endl;

    cout << "ǰ׺���������" << endl;
    comnum2 = ++comnum1;
    cout << "comnum1:";
    comnum1.display();
    cout << "comnum2:";
    comnum2.display();
    cout << endl;

    cout << "��׺���������:" << endl;
    comnum3 = comnum1++;
    cout << "comnum1:";
    comnum1.display();
    cout << "comnum3:";
    comnum3.display();

    return 0;
}