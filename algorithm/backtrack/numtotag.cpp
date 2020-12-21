//num to target
//cxh
#include <bits/stdc++.h>
using namespace std;
typedef int ele;

ele comb_sign(ele a, ele b, int sign, bool &ok) { //sign 1+ 2- 3* 4/ 5~* 6~/
    ok = 1;                                       //除数正确
    switch (sign) {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return b - a;
    case 4:
        return a * b;
    case 5:
        if (b == 0) {
            ok = 0;
            return 0;
        }
        return a / b;
    default: //case 6
        if (a == 0) {
            ok = 0;
            return 0;
        }
        return b / a;
    }
}

bool num_to_target(vector<ele> num, ele target) {
    if (num.size() == 1) {
        if (num[0] == target)
            return true;
        else
            return 0;
    }
    for (int i = 0; i < num.size() - 1; ++i) {
        for (int j = i + 1; j < num.size(); ++j) {
            vector<ele> stor;
            stor.push_back(num[i]);
            stor.push_back(num[j]);
            num.erase(num.begin() + j);
            num.erase(num.begin() + i);
            for (int sign = 1; sign <= 6; ++sign) {
                bool ok;
                ele com_new = comb_sign(stor[0], stor[1], sign, ok);
                if (ok == 0) {
                    continue;
                }
                num.push_back(com_new);
                if (num_to_target(num, target)) {
                    return 1;
                }
                num.pop_back();
            }
            num.insert(num.begin() + i, stor[0]);
            num.insert(num.begin() + j, stor[1]);
        }
    }
    return 0;
}

int main() {
    int n, ta;
    while (~scanf("%d%d", &n, &ta)) {
        vector<ele> num;
        int t;
        while (n--) {
            scanf("%d", &t);
            num.push_back(t);
        }
        if (num_to_target(num, ta)) {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}

/*
//num to target
//cxh
#include <bits/stdc++.h>
using namespace std;
typedef int ele;

bool used[6];

ele comb_sign(ele a, ele b, int sign, bool &dvnz) { //sign 1+ 2- 3* 4/ 5~* 6~/
    dvnz = 1;                                       //除数正确？
    switch (sign) {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return b - a;
    case 4:
        return a * b;
    case 5:
        if (b == 0) {
            dvnz = 0;
            return 0;
        }
        return a / b;
    default: //case 6
        if (a == 0) {
            dvnz = 0;
            return 0;
        }
        return b / a;
    }
}

bool num_to_target(vector<ele> num, ele target) {
    if (num.size() == 1) {
        if (num[0] == target)
            return true;
        else
            return 0;
    }
    for (int i = 0; i < num.size() - 1; ++i) {
        if (used[i]) {
            continue;
        } else {
            used[i] = 1;
        }
        for (int j = i + 1; j < num.size(); ++j) {
            if (used[j]) {
                continue;
            } else {
                used[j] = 1;
            }
            vector<ele> stor;
            stor.push_back(num[i]);
            stor.push_back(num[j]);
            //num.erase(num.begin() + j);
            //num.erase(num.begin() + i);
            for (int sign = 1; sign <= 6; ++sign) {
                bool dvnz;
                ele com_new = comb_sign(stor[0], stor[1], sign, dvnz);
                if (dvnz == 0) {
                    continue;
                }
                num.push_back(com_new);
                if (num_to_target(num, target)) {
                    return 1;
                }
                num.pop_back();
            }
            used[j] = 0;
            //num.insert(num.begin() + i, stor[0]);
            //num.insert(num.begin() + j, stor[1]);
        }
        used[i] = 0;
    }
    return 0;
}

int main() {
    int n, ta;
    while (~scanf("%d%d", &n, &ta)) {
        memset(used, 0, 6);
        vector<ele> num;
        int t;
        while (n--) {
            scanf("%d", &t);
            num.push_back(t);
        }
        if (num_to_target(num, ta)) {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}*/