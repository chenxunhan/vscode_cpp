#include <iostream>
using namespace std;
const int MAX = 1e5 + 5;
bool used[MAX] = {0};
int befHasDifNum[MAX] = {0};
int servOrder[MAX] = {0};
int res[MAX] = {0};
int main() {
    int cardNum, servNum;
    scanf("%d%d", &cardNum, &servNum);
    for (int i = 1; i <= servNum; ++i) {
        scanf("%d", servOrder + i);
        
    }
    int i;
    res[servNum] = befHasDifNum[servNum]=0;
    used[servNum] = 1;
    for ( i= servNum-1; i >= 1;--i){
        befHasDifNum[i] = befHasDifNum[i + 1] + (!used[i]);
        used[i] = 1;
    }
    for (++i;i<=servNum;++i){
        printf("%d\n", res[i]);
    }

        return 0;
}
