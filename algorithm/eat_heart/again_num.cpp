//����������Ϸ �� 2600 ��
//��ѷ�
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char num[20];
    int m;
    while (~scanf("%s", num)) {
        scanf("%d", &m);
        m = min(210, m);
        int index = 1;
        for (int i = 1;i<=m+index-1&& num[i] != 0; ++i){
            if (num[i] > num[index-1]) {
                    mxi = i;
                    if(mx=='9'){
                        break;
                    }
                }
        }

        while(){%!=

        }
            int i = 1;
        while (m > 0 && i < strlen(num)) {
            //find max
            int mxj = -1;
            char mx = 0;
            for (int j = i; j <= m + i - 1 && num[j] != 0; ++j) {
                if (num[j] > mx) {
                    mx = num[j];
                    mxj = j;
                    if(mx=='9'){
                        break;
                    }
                }
            }

            //max set at head
            if (mx > num[i - 1]) {
                for (int ci = mxj; ci >= i; --ci) {
                    num[ci] = num[ci - 1];
                }
                num[i - 1] = mx;
                m -= mxj - i + 1;
            }
            ++i;
        }
        cout << num << endl;
    }
    return 0;
}




//ԭ����任����
/*
int main() {
    char num[21];
    int m;
    while (~scanf("%s", num)) {
        scanf("%d", &m);
        m = min(210, m);
        int i = 1;
        while (m > 0 && i < strlen(num)) {
            //find max
            int mxj = -1;
            char mx = 0;
            for (int j = i; j <= m + i - 1 && num[j] != 0; ++j) {
                if (num[j] > mx) {
                    mx = num[j];
                    mxj = j;
                    if(mx=='9'){
                        break;
                    }
                }
            }

            //max set at head
            if (mx > num[i - 1]) {
                for (int ci = mxj; ci >= i; --ci) {
                    num[ci] = num[ci - 1];
                }
                num[i - 1] = mx;
                m -= mxj - i + 1;
            }
            ++i;
        }
        cout << num << endl;
    }
    return 0;
}
*/
