#include <bits/stdc++.h>
using namespace std;

int main() {
    void IntDiv(int n);
    int n;
    while (~scanf("%d", &n)) {
        IntDiv(n);
        cout << endl;
    }
    return 0;
}

void IntDiv(int n) {
    void IntDivFml(int n, int m, int l);
    if (n > 1) {
        printf("(%d %d %d):", n, n, 1);
        IntDivFml(n, n, 1);
        cout << ";\n";
    }
    for (int i = n - 1; i >= 2;) { //这一段代码有问题，无法给(n,i,j)写出一个书写顺序
        for (int j = 2; j <= n;) {
            bool pr = 0;
            if (abs(i + j - n) <= 1) {
                printf("(%d %d %d):", n, i, j);
                IntDivFml(n, i, j);
                pr = 1;
                //cout << endl;
            }
            if (i + j - n < 1) {
                ++j;
                if (pr == 1)
                    cout << ",";
            } else {
                --i;
                if (pr == 1)
                    cout << ";\n";
                break;
            }
        }
    }
    printf("(%d %d %d):", n, 1, n);
    IntDivFml(n, 1, n);
    cout << ".\n";
}

//整数划分式子，返回待划分数n的一个带有最大值m的并且长度为l的划分数集合
void IntDivFml(int n, int m, int l) {
    if (n == l) {
        for (int i = 0; i < n - 1; ++i)
            cout << 1 << "+";
        cout << 1;
        return;
    }
    if (n <= m) {
        cout << n;
        return;
    }
    //if(n>m)
    cout << m << "+";
    IntDivFml(n - m, min(n - m - (l - 1) + 1, m), l - 1);
}
/*
整数划分问题
将正整数n表示成一系列正整数之和：n=n1+n2+…+nk，
其中n1≥n2≥…≥nk≥1，k≥1。
正整数n的这种表示称为正整数n的划分。求正整数n的不同划分个数。 
例如正整数6有如下11种不同的划分：
    (准备划分的数，划分的数中必有的最大的数，划分的数的个数)
    6；(6,6,1)
    5+1；(6,5,2)
    4+2，4+1+1；(6,4,2)(6,4,3)
    3+3，3+2+1，3+1+1+1；
    2+2+2，2+2+1+1，2+1+1+1+1；
    1+1+1+1+1+1。
输入正整数n的值，输出n的划分种类数及具体的划分情况。测试值（n=6，n=7）
当n=6时，则输出：共有11划分，分别为：
 6=6；
 6=5+1；
 .................................
 6=1+1+1+1+1+1;
*/

/*baidu
#include <bits/stdc++.h>
using namespace std;

int x[50] = {0};

int main() {
    void split(int n, int k);
    int n;
    printf("%Please input 'n'(0<n<100):");
    scanf("%d", &n);
    split(n, 0);
    return 0;
}

void split(int n, int k) {
    void display(int k);
    int i;
    if (n == 0)
        display(k);
    else {
        for (i = n; i > 0; --i) {
            if (k == 0 || i < x[k - 1]) {
                x[k] = i;
                split(n - i, k + 1);
            }
        }
    }
}

void display(int k) {
    int i;
    for (i = 0; i < k; ++i)
        printf("%d ", x[i]);
    printf("\n");
}
*/

/**
 * 弃掉的算法2
int main() {
    void IntDiv(int n, int k);
    int n, k;
    while (~scanf("%d %d", &n, &k)) {
        IntDiv(n, k);
        cout << endl;
    }
    return 0;
}

int ar[100];

void IntDiv(int n, int k) {
    if (k == 1) {
        printf("%d", n);
    }
    if (k == 2) {
        for (int i = n - 1; i * 2 >= n; --i) {
            int j = 0;
            memset(ar, 0, 400);
            ar[j++] = i;
            ar[j++] = n - i;
            for (int i = 0; ar[i] != 0; ++i) {
                IntDiv(ar[i], 1);
                cout << " ";
            }
            cout << endl;
        }
    }
    if (k == 3) {
    }
}
*/

/*for (int i = n-1, j = 2; i >= 1 && j <= n;) {
        if (abs(i + j - n) <= 1 && i * j >= n) {
            printf("(%d %d %d):", n, i, j);
            IntDivFml(n, i, j);
            //cout << endl;
        }
        if (abs(i + (j + 1) - n) <= 1) {
            ++j;
            if (i * (j - 1) >= n)
                cout << ",";
        } else {
            --i;
            if ((i + 1) * j >= n)
                cout << ";\n";
        }
    }*/