#include <bits/stdc++.h>
using namespace std;
const int MAX = 500 + 5;
int mat[MAX][MAX] = {0};
int n, m;
int x, y, r, z;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, k = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mat[i][j] = k++;

    while (m--) { //x,y是中心;z是顺0逆1,r是1/4区域的长度大小
        scanf("%d%d%d%d", &x, &y, &r, &z);
        if (z) {
            for (int i = 0; i <= r; ++i)
                for (int j = 1; j <= r; ++j) {
                    swap(mat[x + i][y + j], mat[x - j][y + i]); //1象限
                    swap(mat[x + i][y + j], mat[x - i][y - j]); //4
                    swap(mat[x + i][y + j], mat[x + j][y - i]); //3
                }
            continue;
        }
        for (int i = 0; i <= r; ++i)
            for (int j = 1; j <= r; ++j) {
                swap(mat[x + i][y + j], mat[x + j][y - i]); //3
                swap(mat[x + i][y + j], mat[x - i][y - j]); //4
                swap(mat[x + i][y + j], mat[x - j][y + i]); //1
            }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            printf("%d ", mat[i][j]);
        putchar('\n');
    }
    return 0;
}
