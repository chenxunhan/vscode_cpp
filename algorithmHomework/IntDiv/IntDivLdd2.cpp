#include <iostream>

#define MAX_N 100

void Divide(int n);

int ch[MAX_N + 2] = {0};
int *chose = ch + 1;
int sum(0);
std::string answer;

int main() {
    std::cout << ("请输入被划分的数：");
    std::cin >> chose[0];
    Divide(chose[0]);
    std::cout << "划分为" << sum << "种:\n"
              << answer;
    return 0;
}

void Divide(int n) {
    if (!n) {
        ++sum;
        answer += std::to_string(chose[0]) + '=';
        for (int i = 1; i < chose[-1]; ++i)
            answer += std::to_string(chose[i]) + '+';
        answer += std::to_string(chose[chose[-1]]) + '\n';
        return;
    }

    ++chose[-1];
    for (int i = (n < chose[chose[-1] - 1] ? n : chose[chose[-1] - 1]); i > 0; --i) {
        chose[chose[-1]] = i;
        Divide(n - i);
    }
    --chose[-1];

    return;
}