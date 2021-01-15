#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 25 * 2500 + 5;
char inputWL[MAXSIZE] = {0};

int hhScore, opScore;

void initScore() {
    hhScore = opScore = 0;
}
void printScore() {
    if (hhScore == 0 && opScore == 0) {
        // return;
    }
    printf("%d:%d\n", hhScore, opScore);
}
bool is11End() {
    if ((hhScore >= 11 || opScore >= 11) && (abs(hhScore - opScore) >= 2)) {
        return 1;
    }
    return 0;
}

bool is21End() {
    if ((hhScore >= 21 || opScore >= 21) && (abs(hhScore - opScore) >= 2)) {
        return 1;
    }
    return 0;
}

int main() {
    {
        char c;
        int i = 0;
        while (1) {
            scanf("%c", &c);
            if (c == 'E') {
                printScore();
                putchar('\n');
                inputWL[i] = c;
                initScore();
                break;
            }
            if (c == 'W' || c == 'L') {
                inputWL[i] = c;
                if (c == 'W') {
                    ++hhScore;
                } else if (c == 'L') {
                    ++opScore;
                }
                if (is11End()) {
                    printScore();
                    initScore();
                }
                ++i;
            }
        }
    }
    for (int i = 0; inputWL[i] != 'E'; ++i) {
        if (inputWL[i] == 'W') {
            ++hhScore;
        } else if (inputWL[i] == 'L') {
            ++opScore;
        }
        if (is21End()) {
            printScore();
            initScore();
        }
    }
    printScore();
    return 0;
}