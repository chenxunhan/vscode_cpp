//���������� �� 2773 ��
//��ѷ�
/*
0 1 2 3 4 5 6 7 8
 1 1 1 1 1 1 1 1


0 1 1 2 4 4 5 6 7 8
 0 1 1 2 0 1 1 1 1
����0����0ǰ-1������

ԭ��0 1 2 4 4 5 6 7 8
� 1 1 2 0 1 1 1 1
����0����0ǰ-1�� �� ԭ����0����

0 1 2 2 4 5 6 7 8
 1 1 0 2 1 1 1 1
����0����0ǰ-1����������

4 4 5 6 6 10 12 14 16
 0 1 1 0 4  2  2  2
����0����00��ȫ��>=1�����>=2����(�ϲ���)

9  8 8  7  5 5
 -1 0 -1 -2 0

3 4 4 6 6 10 12 14 16
 1 0 2 0 4  2  2  2
����0����00��ȫ��>=1�����>=2����

4 5 5 6 6 10 12 14 16
 1 0 1 0 4  2  2  2
����0����00��ȫ��>=1����

bool = false;
<=0 7 8 9 9 
 0 1 2 0 -1 -1 -1 -2 0

int zhuang -1 0 1

��������ȫ�ֱ���bool
һ��ͷֱ�����ô˶ε������������Ϊtrue��
{���������һ��0,
��ǰ���������Ϊfalse,ԭ���鲻�����������no����������������һ��
���ô˶ε������������Ϊfalse��}
���������һ��+,���������֣�
���������һ��-,��������֣�
����β��ֱ�����yes

�����֣�
{}
��������һ��0ǰ��һ������>=2����������������Ϊtrue,
��������ֱ�ӽ���������ж�

�����֣�
{}
��������һ��0ǰ��һ������<=-2����������������Ϊtrue,
��������ֱ�����no
*/
#include <bits/stdc++.h>
using namespace std;
//����ѭ���Ż�
//��������
bool perfect = true;
int up_down; //up=0,down=1
int n;
int arr[100001], diff[100000];

bool diff_fc(int i) {
    if (i == 0) {
        return true;
    }
    if (diff[i] == 0) {
        if (perfect == false) {
            return false;
        }
        perfect = false;
        return true;
    }
    if (diff[i] > 0) {
        if (up_down == 1) {
            return false;
        }
        up_down = 0;
    } else {
        if (up_down == 0) {
            return false;
        }
        up_down = 1;
    }
    if (up_down == 0) {
        if (diff[i] >= 2) {
            perfect = true;
        }
    } else if (up_down == 1) {
        if (diff[i] <= -2) {
            perfect = true;
        }
    }
    return true;
}

int main() {
    int t = 0;
    while (~scanf("%d", &n)) {
        t = 0;
        perfect = true;
        up_down = -1;
        for (int ni = 1; ni <= n; ++ni) {
            scanf("%d", arr + ni);
            diff[ni - 1] = arr[ni] - arr[ni - 1];
            if (diff_fc(ni - 1) == false && t == 0) {
                printf("No\n");
                t = 1;
            } else if (ni >= n && t == 0) {
                printf("Yes\n");
                t = 1;
            }
        }
    }
    return 0;
}
