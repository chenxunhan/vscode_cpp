#include <bits/stdc++.h>
#include <vector>//need this class,bit do not include
using namespace std;

//define
vector<int> the_vector;
vector<int>::iterator the_iterator;

int main() {
    for (int i = 0; i < 10; ++i) {
        the_vector.push_back(i);
    }
    //iterator like pointer, can ++,-- and *()
    //use for stl
    the_iterator = the_vector.begin();   //a[0]
    cout << *(the_iterator + 5) << endl; //a[5]
    for (the_iterator = the_vector.begin(); the_iterator != the_vector.end(); ++the_iterator) {
        cout << *(the_iterator) << "  ";
    }
    return 0;
}