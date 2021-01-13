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
    static int c[15], n;
    n = 0;
    while (num) {
        c[n++] = num % 10;
        num /= 10;
    }
    for (int i(0); i <= n / 2; ++i) {
        if (c[i] != c[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a(5), b(500), i(0);
    // cin >> a>>b;
    eulerSieve(b);
    for (; prime[i] < a && prime[i]; ++i) {}
    for (; prime[i] <= b && prime[i]; ++i) {
        if (isHuiWen(prime[i])) {
            cout << prime[i] << endl;
        }
    }

    return 0;
}