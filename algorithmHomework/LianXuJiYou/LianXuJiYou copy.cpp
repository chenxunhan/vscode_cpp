#include <bits/stdc++.h>
using namespace std;

const int MAXFACELIMIT = 10;
const int MAXPOSTAGELIMIT = 300;

int faceLimit, stickLimit;
int facePlanMaxPostage;

int FacePlan[MAXFACELIMIT] = {0};
int dfsFacePlan[MAXFACELIMIT] = {0};

int postageMinStickNum[MAXFACELIMIT][MAXPOSTAGELIMIT];
int postageEachFaceStickNum[MAXFACELIMIT];

FILE *fpout;

void fInitMess() {
    facePlanMaxPostage = 0;
    // faceLimit = 4, stickLimit = 3;
    faceLimit = 4, stickLimit = 3;
    // FILE *fpin = fopen("input.txt", "r");
    // fscanf(fpin, "%d%d", &faceLimit, &stickLimit);
    // fclose(fpin);
}

void fOutputMess() {
    fpout = fopen("output.txt", "w");
    fprintf(fpout, "faceLimit=%d,stickLimit=%d\n\n", faceLimit, stickLimit);
}

void recordDfsFacePlan() {
    for (int i = 1; i <= faceLimit; ++i) {
        FacePlan[i] = dfsFacePlan[i];
    }
}

int getPostageMinStickNum(int hasPlanFaceNum, int stickPostage) {
    postageEachFaceStickNum[hasPlanFaceNum] = 0;
    if (postageMinStickNum[hasPlanFaceNum][stickPostage]) {
        return postageMinStickNum[hasPlanFaceNum][stickPostage];
    }
    if (stickPostage == 0 || stickPostage == 1 || hasPlanFaceNum == 1) {
        return postageMinStickNum[hasPlanFaceNum][stickPostage] = stickPostage;
    }
    int retDfsMaxPostage = INT_MAX;
    int retLastPlanFaceChooseNum;
    for (int lastPlanFaceChooseNum = 0, tmp;
         lastPlanFaceChooseNum <= stickLimit && stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum] >= 0;
         ++lastPlanFaceChooseNum) {
        if ((tmp =
                 (getPostageMinStickNum(hasPlanFaceNum - 1, stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum]) + lastPlanFaceChooseNum)) < retDfsMaxPostage) {
            retDfsMaxPostage = tmp;
            retLastPlanFaceChooseNum = lastPlanFaceChooseNum;
        }
    }
    // while (stickPostage)

    postageEachFaceStickNum[hasPlanFaceNum] = retLastPlanFaceChooseNum;
    return postageMinStickNum[hasPlanFaceNum][stickPostage] = retDfsMaxPostage;
}

void fOutputDfsThisLv(int hasPlanFaceNum, int dfsMaxPostage) {
    for (int i = 1; i < hasPlanFaceNum; ++i) {
        fprintf(fpout, "\t");
    }
    fprintf(fpout, "(x%d=%d,r%d=%d) (", hasPlanFaceNum, dfsFacePlan[hasPlanFaceNum], hasPlanFaceNum, dfsMaxPostage);
    // fprintf(fpout, "(Face%d=%d,MaxPostage=%d) FaceStickPlan(", hasPlanFaceNum, dfsFacePlan[hasPlanFaceNum], dfsMaxPostage);
    for (hasPlanFaceNum; hasPlanFaceNum >= 1; --hasPlanFaceNum) {
        for (int i = 1; i <= postageEachFaceStickNum[hasPlanFaceNum]; ++i) {
            fprintf(fpout, "[%d]", dfsFacePlan[hasPlanFaceNum]);
        }
    }
    fprintf(fpout, ")\n");
}

void dfsGetFacePlan(int hasPlanFaceNum) {
    memset(postageMinStickNum, 0, sizeof(postageMinStickNum));
    memset(postageEachFaceStickNum, 0, sizeof(postageEachFaceStickNum));
    //get dfs
    int dfsMaxPostage = 0;
    while (!(getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage) <= stickLimit &&
             getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage + 1) > stickLimit) &&
           hasPlanFaceNum) {
        ++dfsMaxPostage;
    }
    if (hasPlanFaceNum)
        fOutputDfsThisLv(hasPlanFaceNum, dfsMaxPostage);
    if (hasPlanFaceNum == faceLimit) {
        if (dfsMaxPostage > facePlanMaxPostage) {
            facePlanMaxPostage = dfsMaxPostage;
            recordDfsFacePlan();
        }
        return;
    }
    for (int thisLvChooseFace = dfsFacePlan[hasPlanFaceNum] + 1;
         thisLvChooseFace <= dfsMaxPostage + 1;
         ++thisLvChooseFace) {
        dfsFacePlan[hasPlanFaceNum + 1] = thisLvChooseFace;
        dfsGetFacePlan(hasPlanFaceNum + 1);
    }
}

void dispPlan() {
    fprintf(fpout, "FacePlan=<%d", FacePlan[1]);
    for (int i = 2; i <= faceLimit; ++i) {
        fprintf(fpout, ",%d", FacePlan[i]);
    }
    fprintf(fpout, ">%2cPostageRange:[1,%d]", ' ', facePlanMaxPostage);
    fclose(fpout);
}

int main() {
    fInitMess();
    fOutputMess();
    dfsGetFacePlan(0);
    dispPlan();
    return 0;
}
