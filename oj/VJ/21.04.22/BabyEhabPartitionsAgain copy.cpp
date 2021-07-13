#include <bits/stdc++.h>
using namespace std;

class NaP {
  public:
    int val;
    int pos;
};

class vList {
  private:
    int sum_ = -1;

  public:
    vector<NaP> v;
    int sum() {
        if (sum_ != -1) {
            return sum_;
        }
        sum_ = 0;
        for (auto i = v.begin(); i != v.end(); ++i) {
            sum_ += (*i).val;
        }
        return sum_;
    }
};

vList sumList(vList a, int n, int pos) {
    vList r(a);
    r.v.push_back(NaP{n, pos});
    return r;
}

vList numItSelf(int n, int pos) {
    vList r;
    r.v.push_back(NaP{n, pos});
    return r;
}

vector<vList> V;
int n;
int arr[105], arrSumDiv = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
        arrSumDiv += arr[i];
    }
    if (arrSumDiv & 1) {
        puts("0");
        return 0;
    }
    arrSumDiv /= 2;
    for (int i = 1; i <= n; ++i) {
        vector<vList> Vt;
        Vt.push_back(numItSelf(arr[i], i));
        for (auto Vi = V.begin(); Vi != V.end(); ++Vi) {
            if ((*Vi).sum() + arr[i] > arrSumDiv) {
                continue;
            }
            Vt.push_back(sumList(*Vi, arr[i], i));
        }
        V.insert(Vt.end(), Vt.begin(), Vt.end());
    }
    for (auto Vi = V.begin(); Vi != V.end(); ++Vi) {
        printf("%d:(", (*Vi).sum());
        for (auto vi = (*Vi).v.begin(); vi != (*Vi).v.begin(); ++vi) {
            printf("%3d", (*vi).val);
        }
        puts(")");
    }
    return 0;
}