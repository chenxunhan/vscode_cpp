#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class symmetric_matrix {
  private:
    int order;
    T *value;

  public:
    symmetric_matrix();
    symmetric_matrix(int, T **);
    ~symmetric_matrix();
    int order();
    T &operator[][](int i, int j) {
        if (j > i) {
            int t = ++j;
            j = ++i;
            i = t;
        }
        return &value[(i + 1) * i / 2 + j - 1];
    };
};

template <typename T>
symmetric_matrix<T>::symmetric_matrix() {
    order = 0;
    value = nullptr;
    *value = nullptr;
}
//1 2 3   n
template <typename T>
symmetric_matrix<T>::symmetric_matrix(int n, T **_value) {
    order = n;
    value = new T[n * (n + 1) / 2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            value[(i + 1 + 2) * (i + 1) / 2 + (j + 1) - 1] = value[i][j];
        }
    }
}

template <typename T>
symmetric_matrix<T>::~symmetric_matrix() {
    delete value;
}

template <typename T>
int symmetric_matrix<T>::order() {
    return order;
}

int main() {
    int mat[5][5] = {{1, 1, 0, 0, 0},
                     {1, 1, 1, 0, 0},
                     {0, 1, 1, 1, 0},
                     {0, 0, 1, 1, 1},
                     {0, 0, 0, 1, 1}};
    symmetric_matrix<int> m(5, mat);
    cout << m[0][0];
    return 0;
}