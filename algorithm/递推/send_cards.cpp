//����Ƭ �� 2588 ��
//��ѷ�
#include <bits/stdc++.h>
using namespace std;

long long a[60] = {0, 3, 6, 6};

int main() {
    for (int i = 4; i <= 55; i++) {
        a[i] = a[i - 1] + 2 * a[i - 2];
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%lld\n", *(a + n));
    }
    return 0;
}