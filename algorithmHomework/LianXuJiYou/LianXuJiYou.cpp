#include <bits/stdc++.h>
using namespace std;

const int MAXFACELIMIT = 10;      //面值种类最大限制
const int MAXPOSTAGELIMIT = 1000; //邮资最大限制

int faceLimit, stickLimit; //文件输入的待计算的 面值种类限制 可贴张数限制

//dfsFacePlan[i] dfs过程备忘录 记录到当前第i分支(已选的面值)的所有选择
int dfsFacePlan[MAXFACELIMIT] = {0};
//postageMinStickNum[i][j]在已选的i张中组合出j邮资花费最少的张数
int postageMinStickNum[MAXFACELIMIT][MAXPOSTAGELIMIT];
//postageLastStickNum[i][j]在已选的i张中组合出j邮资 花费最少张数 的计划中 第i张邮票(最后一张)所需要的张数
int postageLastStickNum[MAXFACELIMIT][MAXPOSTAGELIMIT];

int facePlanMaxPostage;           //计算出的最大连续邮资上限
int FacePlan[MAXFACELIMIT] = {0}; //计算出的面值选择方案

//文件输入输出流
FILE *fpin, *fpout;

/**
 * @brief 文件输入待计算的 面值种类限制 和 可贴张数限制
 */
void fInitMess() {
    facePlanMaxPostage = 0;
    fpin = fopen("input.txt", "r");
    fscanf(fpin, "%d%d", &faceLimit, &stickLimit);
    fclose(fpin);
}

/**
 * @brief 文件输出正在计算的 面值种类限制 和 可贴张数限制
 */
void fOutputMess() {
    fpout = fopen("output.txt", "w");
    fprintf(fpout, "faceLimit=%d,stickLimit=%d\n\n", faceLimit, stickLimit);
}

/**
 * @brief 将dfs备忘录中的分支选择记录到最终选择
 */
void recordDfsFacePlan() {
    for (int i = 1; i <= faceLimit; ++i)
        FacePlan[i] = dfsFacePlan[i];
}

/**
 * @brief 若上方postageMinStickNum[i][j]已经计算好，本函数直接返回上方存储值
 * @param hasPlanFaceNum dfs过程中已经放置好的面值种类数目
 * @param stickPostage  dfs过程中准备组合出的邮资
 * @return 返回在已选的i张中组合出j邮资花费最少的张数
 */
int getPostageMinStickNum(int hasPlanFaceNum, int stickPostage) {
    if (postageMinStickNum[hasPlanFaceNum][stickPostage]) //如果已经算出来不是0了直接返回
        return postageMinStickNum[hasPlanFaceNum][stickPostage];
    if (stickPostage == 0 || stickPostage == 1 || hasPlanFaceNum == 1) { //到底条件
        if (dfsFacePlan[hasPlanFaceNum] <= stickPostage)
            postageLastStickNum[hasPlanFaceNum][stickPostage] = stickPostage;
        return postageMinStickNum[hasPlanFaceNum][stickPostage] = stickPostage;
    }
    int retPostageMinStickNum = INT_MAX; //存储返回值
    int retLastPlanFaceChooseNum = 0;    //存储此次组合邮资中最后一张邮票所需要的张数
    for (int lastPlanFaceChooseNum = 0, tmp;
         lastPlanFaceChooseNum <= stickLimit &&
         stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum] >= 0;
         ++lastPlanFaceChooseNum) { //遍历此次组合邮资中最后一张邮票所需要的张数
        if ((tmp = (lastPlanFaceChooseNum +
                    getPostageMinStickNum(hasPlanFaceNum - 1, stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum]))) <= retPostageMinStickNum) {
            retPostageMinStickNum = tmp;                      //依据备忘录拿最组合所需的最小总张数
            retLastPlanFaceChooseNum = lastPlanFaceChooseNum; //记录此次组合邮资中最后一张邮票所需要的张数
        }
    }
    postageLastStickNum[hasPlanFaceNum][stickPostage] = retLastPlanFaceChooseNum;    //最后一张张数打入备忘录方便回溯
    return postageMinStickNum[hasPlanFaceNum][stickPostage] = retPostageMinStickNum; //打入备忘录并返回值
}

/**
 * @brief 文件输出当前dfs分支的选择
 * @param hasPlanFaceNum dfs过程中已经放置好的面值种类数目
 * @param stickPostage  dfs过程中准备组合出的邮资
 * 
 */
void fOutputDfsThisLv(int hasPlanFaceNum, int dfsMaxPostage) {
    for (int i = 1; i < hasPlanFaceNum; ++i) {
        fprintf(fpout, "\t\t");
    }
    fprintf(fpout, "(x%d=%d,r%d=%d) (", hasPlanFaceNum, dfsFacePlan[hasPlanFaceNum], hasPlanFaceNum, dfsMaxPostage);
    while (dfsMaxPostage) { //回溯输出
        for (hasPlanFaceNum; hasPlanFaceNum >= 1; --hasPlanFaceNum) {
            for (int i = 1; i <= postageLastStickNum[hasPlanFaceNum][dfsMaxPostage]; ++i) {
                fprintf(fpout, "[%d]", dfsFacePlan[hasPlanFaceNum]);
            }
            dfsMaxPostage -= postageLastStickNum[hasPlanFaceNum][dfsMaxPostage] * dfsFacePlan[hasPlanFaceNum];
        }
    }
    fprintf(fpout, ")\n");
}

/**
 * @brief 核心函数dfs计算出面值方案
 * @param hasPlanFaceNum dfs过程中已经放置好的面值种类数目
 */
void dfsGetFacePlan(int hasPlanFaceNum = 0) {
    memset(postageMinStickNum, 0, sizeof(postageMinStickNum)); //初始化
    memset(postageLastStickNum, 0, sizeof(postageLastStickNum));
    int dfsMaxPostage = 0;
    while (!(getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage) <= stickLimit &&
             getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage + 1) > stickLimit) &&
           hasPlanFaceNum)
        ++dfsMaxPostage; //拿到连续集邮区间的最大邮资

    if (hasPlanFaceNum) //若已经有选择分支了，开始输出分支信息
        fOutputDfsThisLv(hasPlanFaceNum, dfsMaxPostage);
    if (hasPlanFaceNum == faceLimit) {            //分支到了叶子
        if (dfsMaxPostage > facePlanMaxPostage) { //如果当前连续集邮区间的最大邮资大于记录的
            facePlanMaxPostage = dfsMaxPostage;   //记录邮资
            recordDfsFacePlan();                  //记录方案
        }
        return;
    }
    for (int thisLvChooseFace = dfsFacePlan[hasPlanFaceNum] + 1;
         thisLvChooseFace <= dfsMaxPostage + 1; //在合理的区间内遍历当前分支面值所选择的张数，并继续dfs
         ++thisLvChooseFace) {
        dfsFacePlan[hasPlanFaceNum + 1] = thisLvChooseFace; //记录当前分支
        dfsGetFacePlan(hasPlanFaceNum + 1);                 //进入下层分支
    }
}

/**
 * @brief 文件输出最终分配方案
 */
void dispPlan() {
    fprintf(fpout, "\nFacePlan=<%d", FacePlan[1]);
    for (int i = 2; i <= faceLimit; ++i)
        fprintf(fpout, ",%d", FacePlan[i]);
    fprintf(fpout, ">  PostageRange:[1,%d]", facePlanMaxPostage);
    fclose(fpout);
}

int main() {
    fInitMess();      //文件输入待计算的 面值种类限制 和 可贴张数限制
    fOutputMess();    //文件输出正在计算的 面值种类限制 和 可贴张数限制
    dfsGetFacePlan(); //核心函数dfs计算出面值方案
    dispPlan();       //文件输出最终分配方案
    return 0;
}
