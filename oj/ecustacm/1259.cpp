#include <bits/stdc++.h>
using namespace std;

int xg, ru, sh, hu, sa, ya, xn, qi;

bool diff() {
    bool u[10] = {0};
    u[xg] = u[ru] = u[sh] = u[hu] = u[sa] = u[ya] = u[xn] = u[qi] = 1;
    int sum = 0;
    for (bool i : u) {
        sum += i;
    }
    return (sum == 8) ? 1 : 0;
}

int main() {
    for (xg = 0; xg <= 9; ++xg) {
        for (ru = 0; ru <= 9; ++ru) {
            for (sh = 0; sh <= 9; ++sh) {
                for (hu = 0; hu <= 9; ++hu) {
                    for (sa = 0; sa <= 9; ++sa) {
                        for (ya = 0; ya <= 9; ++ya) {
                            for (xn = 0; xn <= 9; ++xn) {
                                for (qi = 0; qi <= 9; ++qi) {
                                    if ((xg + sa) * 1000 + (ru + ya) * 100 + (sh + xn) * 10 + hu + ru == sa * 10000 + ya * 1000 + sh * 100 + ru * 10 + qi) {
                                        if (diff())
                                            cout << sa * 1000 + ya * 100 + xn * 10 + ru << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}