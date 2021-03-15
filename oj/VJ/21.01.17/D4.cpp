#include <iostream>

int main() {
    long long ans(0);
    int counts(1), last, LessCounts(0);
    char sign;

    std::cin >> sign;
    last = sign;
    while (std::cin >> sign) {
        bool isRepeat(sign == last);
        switch (sign) {
        case '<':
            if (isRepeat) //<<时加上计数器
                ans += counts;
            else //><时计算连续>>
            {
                if (counts > LessCounts) {
                    ans += counts * (counts + 1) >> 1;
                } else {
                    ans += LessCounts + (((counts - 1) * counts) >> 1);
                }
            }
            break;
        case '>':
            if (!isRepeat)
                LessCounts = counts;
        }
        isRepeat ? ++counts : counts = 1;
        last = sign;
    }
    if (last == '<')
        ans += counts;
    else {
        if (counts > LessCounts) {
            ans += counts * (counts + 1) >> 1;
        } else {
            ans += LessCounts + (((counts - 1) * counts) >> 1);
        }
    }

    std::cout << ans;

    return 0;
}
