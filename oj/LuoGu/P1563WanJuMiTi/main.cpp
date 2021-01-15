#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1e5 + 5;
enum CirDir {
    faceIn = 0,
    faceOut = 1
};

enum SideDir {
    Left = 0,
    Right = 1
};
struct {
    CirDir cirDir;
    string job;
} people[MAXSIZE];

int jobNum, cmdNum;
int getPos(int pos0, SideDir sideDir, int dis) {
    //+: faceIn&right || faceOut&left
    //-: faceIn&left  || faceOut&right
    int retPos;
    if (people[pos0].cirDir == faceIn) {
        if (sideDir == Right) {
            retPos = pos0 + dis;
        } else if (sideDir == Left) {
            retPos = pos0 - dis;
        }
    } else if (people[pos0].cirDir == faceOut) {
        if (sideDir == Left) {
            retPos = pos0 + dis;
        } else if (sideDir == Right) {
            retPos = pos0 - dis;
        }
    }
    if (retPos <= 0) {
        // retPos += ((-retPos) / jobNum + 2) * jobNum;
    }
    if (retPos > jobNum) {
        retPos %= jobNum;
    }
    if (retPos == 0) {
        retPos = jobNum;
    }
    return retPos;
}
int main() {
    scanf("%d%d", &jobNum, &cmdNum);
    for (int i = 1; i <= jobNum; i++) {
        scanf("%d", &people[i].cirDir);
        scanf("%s", people[i].job.c_str());
    }
    SideDir sideDir;
    int dis;
    int pos = 1;
    for (int i = 1; i <= cmdNum; ++i) {
        scanf("%d%d", &sideDir, &dis);
        pos = getPos(pos, sideDir, dis);
    printf("%s", people[pos].job.c_str());
    }
    return 0;
}