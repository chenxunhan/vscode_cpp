#include <bits/stdc++.h>
#define N 50 //���Ĳ�������
using namespace std;

//a[]���㷨ѭ��Ȧ�ĸ��������,res[][]�Ŵ�
//res[0][j]�Ŷ����j
//res[i][j]�ŵ�i�ӵ�j���ս�Ķ����
int a[N], res[N][N];
//n0������Ķ�����,n���㷨ѭ��Ȧ���ϵĶ�����,day��ʾ��ǰ�ǵڼ����ս
int n0, n, day;

//���浱�յĶ���Ĵ�
void saveRes() {
    for (int i = 0; i <= n >> 1; ++i) { //n>>1�ȼ���n/2
        res[a[i]][day] = a[n - i];
        res[a[n - i]][day] = a[i];
    }
}

//���㷨ѭ��Ȧ�ϵĶ���ѭ��˳ʱ����תһ��
void Round() {
    int tail = a[n - 1];
    for (int i = n - 1; i; --i)
        a[i] = a[i - 1];
    a[0] = tail;
}

//���res�𰸲���ʽ�����
void print() {
    if (n0 & 1) //���������Ϊ����,�����ʾ��Ϣ��0�������ö��ֿա�
        printf("0 means empty\n");
    printf("Date  :\t");
    for (int i = 1; i <= day; ++i) { //��һ���������
        printf("%d\t", i);
    }
    putchar('\n');
    for (int i = 1; i <= n0; ++i) {
        printf("Team%2d:\t", i); //�����i�ԵĶ���
        for (int j = 1; j <= day; ++j) {
            printf("%d\t", res[i][j]);
        }
        putchar('\n');
    }
}

//����������
void roundRobin() {
    // n = n0 - !(n0 & 1);           //���ݲ������������㷨ѭ��Ȧ�ϵĶ�����,��������,ż��-1
    n = n0 - 1 | 1;
    a[n] = (n0 & 1) ? 0 : n + 1; //����������Ϊ����,�㷨ѭ��Ȧa[]�����λΪ0(�ֿ�),��������һ��
    for (day = n; day; --day)    //���㷨ѭ��Ȧa[]���ö���
        a[day - 1] = day;
    //����forѭ��������day==0
    while (++day) {   //day���Ŷ�ս��������,����Ϊwhile��ѭ����������
        saveRes();    //���浱������
        if (day == n) //��������ѵ��������˳�
            break;
        Round(); //ѭ��Ȧ����˳ʱ��ѭ��
    }
    print(); //��������
}

int main() {
    while (1) {
        printf("input team nums(1<n<%d):", N);
        if (!(~scanf("%d", &n0)))
            break;
        roundRobin();
        putchar('\n');
    }
    return 0;
}

/*因为循环数组
#include <bits/stdc++.h>
#define N 20
using namespace std;

bool odd;
int a[N];
int res[N][N];
int n0, n, day;

int *newarptr(int len, int nidx, int idx) {
    return a + (nidx + idx + len) % len;
}

void saveRes() {
    for (int i = 0; i <= n / 2; ++i) {
        int a0 = *newarptr(odd ? n0 : n0 - 1, 1 - day, i),
            a1 = *newarptr(odd ? n0 : n0 - 1, 1 - day, n - i);
        res[a0][day] = a1,
        res[a1][day] = a0;
    }
}
// void saveRes() {
//     for (int i = 0; i <= n / 2; ++i) {
//         res[a[i]][day] = a[n - i];
//         res[a[n - i]][day] = a[i];
//     }
// }

void Round() {
    int len = n;
    int tail = a[len - 1];
    for (int i = len - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = tail;
}
void print() {
    for (int i = 1; i <= n0; ++i) {
        for (int j = 0; j <= day; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void roundRobin() {
    odd = (n0 & 1);
    n = odd ? n0 : n0 - 1, a[n] = odd ? 0 : n + 1;
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    // day = n;
    // while (--day)
    //     a[day - 1] = day;
    // while (++day) {
    day = 1;
    while (1) {
        saveRes();
        if (day == (odd ? n0 : n0 - 1))
            break;
        // Round();
        ++day;
    }
    print();
}

int main() {
    for (int i = 1; i < N; ++i)
        res[i][0] = i;
    n0 = 8;
    roundRobin();
    // while (1) {
    //     printf("please input(1<n<%d):", N);
    //     if (!(~scanf("%d", &n0)))
    //         break;
    //     roundRobin(n0);
    // }
    return 0;
}
*/

/*
#include <bits/stdc++.h>
#define N 20
using namespace std;

int to_n(int n0) {
    if (n0 & 1)
        return n0;
    return --n0;
}

int a[N] = {0};
int res[N][N] = {0};
int n0, n, day = 1;

void saveRes(int a[]) {
    for (int i = 0; i <= n / 2; ++i) {
        res[a[i]][day] = a[n - i];
        res[a[n - i]][day] = a[i];
    }
}

void Round(int a[]) {
    int len = n;
    int tail = a[len - 1];
    for (int i = len - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = tail;
}
void print() {
    for (int i = 1; i <= n0; ++i) {
        res[i][0] = i;
    }
    for (int i = 1; i <= n0; ++i) {
        for (int j = 0; j <= day; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void f() {
    bool odd = n0 & 1;
    n = to_n(n0);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    if (!odd) {
        a[n] = n + 1;
    } else {
        a[n] = 0;
    }
    // for (int i = 0; i < n0; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    while (1) {
        saveRes(a);
        if (a[0] == 2)
            break;
        Round(a);
        // for (int i = 0; i < n0; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        ++day;
    }
}

int main() {
    n0 = 5;
    f();
    print();
    return 0;
}
*/