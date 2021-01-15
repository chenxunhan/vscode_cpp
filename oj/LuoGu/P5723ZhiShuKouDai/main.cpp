#include <bits/stdc++.h>
using namespace std;

int prime[(int) 1e8 + 5], primeNumber;
bool isPrime[(int) 1e8 + 5];

void eulerSieve(int end) {
    primeNumber = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int i(2); i <= end; ++i) {
        (isPrime[i]) && (prime[primeNumber++] = i);
        for (int j(0); j < primeNumber && i * prime[j] <= end; ++j) {
            isPrime[i * prime[j]] = 0;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
}

bool isHuiWen(int num) {
    int originalNum = num, reverseNum(0);
    while (num) {
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    }
    return (originalNum == reverseNum);
}

int main() {
    int a(5), b(1e8), i(0);
    cin >> a >> b;
    eulerSieve(b);
    for (; prime[i] < a && prime[i]; ++i) {}
    for (; prime[i] <= b && prime[i]; ++i) {
        if (isHuiWen(prime[i])) {
            // cout << prime[i] << endl;
            printf("%d\n", prime[i]);
        }
    }
    return 0;
}