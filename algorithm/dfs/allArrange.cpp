#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int mx;
int res[N];
bool used[N];

void printres() {
    for (int i = 0; i < mx; ++i) {
        printf("%d ", res[i]);
    }
    putchar('\n');
}

//level  num
void f(int l) {
    if (l == mx + 1) {
        printres();
    }
    for (int i = 0; i <= mx; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            res[l] = i;
            f(l + 1);
            used[i] = 0;
        }
    }
}

//a from 0
void allArrange(const int a, const int b) {
    memset(used, 0, sizeof(used));
    mx = b;
    f(0);
}

int main() {
    allArrange(0, 3);
    return 0;
}

dfs(){
    if(����){
        //�𰸲���
        return;
    }
    if(Խ�粻�Ϸ�)
        return;
    if(����״̬)//��֦
        return;
    for(��չ��ʽ){
        if(��չ��ʽ�Ϸ� δ�����){
            ���
            �����
            ������һ��
            ������Ǻʹ�
        }
    }
}