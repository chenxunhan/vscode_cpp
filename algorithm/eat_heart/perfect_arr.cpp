//perfect_arr.cpp
//cxh
//68ms
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int t1, t2;
    bool up_down; //1 up,0 down
    while (~scanf("%d", &n)) {
        up_down = 1;
        scanf("%d", &t1);
        int ni = 1;
        //up_down==1
        while (ni < n) {
            scanf("%d", &t2);
            if (t1 < 0) {
                ++ni;
                continue;
            }
            if (t1 < t2) {
                t1 = t2;
            } else { // if (t1 >= t2)
                if (ni - 1 < t2) {
                    t1 = t2;
                } else {
                    t1 = t2 < t1 - 1 ? t2 : t1 - 1;
                    //up_down = 0;
                    ++ni;
                    break;
                }
            }
            ++ni;
        }
        //up_down==0
        while (ni < n) {
            scanf("%d", &t2);
            if (t1 < 0) {
                ++ni;
                continue;
            }
            if (t1 < t2) {
                --t1;
            } else { // if (t1 >= t2)
                if (ni - 1 < t2) {
                    t1 = t2;
                } else {
                    t1 = t2 < t1 - 1 ? t2 : t1 - 1;
                }
            }
            ++ni;
        }

        if (t1 < 0) {
            puts("No");
            continue;
        }
        puts("Yes");
    }
    return 0;
}


//perfect_arr.cpp
//cxh
//64ms
#include <bits/stdc++.h>
using namespace std;

//q1:现在是降序，t2>t1,t2真的应该=t1-1?

int main() {
    int n;
    int t1, t2;
    bool up_down; //1 up,0 down
    while (~scanf("%d", &n)) {
        up_down = 1;
        scanf("%d", &t1);
        for (int ni = 1; ni < n; ++ni) {
            scanf("%d", &t2);
            if (t1 < 0) {
                continue;
            }
            if (t1 < t2) {
                if (up_down == 0) {
                    --t1;
                } else {
                    t1 = t2;
                }
            } else{// if (t1 >= t2) 
                if (ni - 1 < t2) {
                    t1 = t2;
                } else {
                    t1 = min(t2, t1 - 1);
                    up_down = 0;
                }
            }
        }
        if (t1 < 0) {
            puts("No");
            continue;
        }
        puts("Yes");
    }
    return 0;
}
