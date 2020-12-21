#include <bits/stdc++.h>
using namespace std;

const int MAXFACELIMIT = 10;      //��ֵ�����������
const int MAXPOSTAGELIMIT = 1000; //�����������

int faceLimit, stickLimit; //�ļ�����Ĵ������ ��ֵ�������� ������������

//dfsFacePlan[i] dfs���̱���¼ ��¼����ǰ��i��֧(��ѡ����ֵ)������ѡ��
int dfsFacePlan[MAXFACELIMIT] = {0};
//postageMinStickNum[i][j]����ѡ��i������ϳ�j���ʻ������ٵ�����
int postageMinStickNum[MAXFACELIMIT][MAXPOSTAGELIMIT];
//postageLastStickNum[i][j]����ѡ��i������ϳ�j���� ������������ �ļƻ��� ��i����Ʊ(���һ��)����Ҫ������
int postageLastStickNum[MAXFACELIMIT][MAXPOSTAGELIMIT];

int facePlanMaxPostage;           //����������������������
int FacePlan[MAXFACELIMIT] = {0}; //���������ֵѡ�񷽰�

//�ļ����������
FILE *fpin, *fpout;

/**
 * @brief �ļ����������� ��ֵ�������� �� ������������
 */
void fInitMess() {
    facePlanMaxPostage = 0;
    fpin = fopen("input.txt", "r");
    fscanf(fpin, "%d%d", &faceLimit, &stickLimit);
    fclose(fpin);
}

/**
 * @brief �ļ�������ڼ���� ��ֵ�������� �� ������������
 */
void fOutputMess() {
    fpout = fopen("output.txt", "w");
    fprintf(fpout, "faceLimit=%d,stickLimit=%d\n\n", faceLimit, stickLimit);
}

/**
 * @brief ��dfs����¼�еķ�֧ѡ���¼������ѡ��
 */
void recordDfsFacePlan() {
    for (int i = 1; i <= faceLimit; ++i)
        FacePlan[i] = dfsFacePlan[i];
}

/**
 * @brief ���Ϸ�postageMinStickNum[i][j]�Ѿ�����ã�������ֱ�ӷ����Ϸ��洢ֵ
 * @param hasPlanFaceNum dfs�������Ѿ����úõ���ֵ������Ŀ
 * @param stickPostage  dfs������׼����ϳ�������
 * @return ��������ѡ��i������ϳ�j���ʻ������ٵ�����
 */
int getPostageMinStickNum(int hasPlanFaceNum, int stickPostage) {
    if (postageMinStickNum[hasPlanFaceNum][stickPostage]) //����Ѿ����������0��ֱ�ӷ���
        return postageMinStickNum[hasPlanFaceNum][stickPostage];
    if (stickPostage == 0 || stickPostage == 1 || hasPlanFaceNum == 1) { //��������
        if (dfsFacePlan[hasPlanFaceNum] <= stickPostage)
            postageLastStickNum[hasPlanFaceNum][stickPostage] = stickPostage;
        return postageMinStickNum[hasPlanFaceNum][stickPostage] = stickPostage;
    }
    int retPostageMinStickNum = INT_MAX; //�洢����ֵ
    int retLastPlanFaceChooseNum = 0;    //�洢�˴�������������һ����Ʊ����Ҫ������
    for (int lastPlanFaceChooseNum = 0, tmp;
         lastPlanFaceChooseNum <= stickLimit &&
         stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum] >= 0;
         ++lastPlanFaceChooseNum) { //�����˴�������������һ����Ʊ����Ҫ������
        if ((tmp = (lastPlanFaceChooseNum +
                    getPostageMinStickNum(hasPlanFaceNum - 1, stickPostage - lastPlanFaceChooseNum * dfsFacePlan[hasPlanFaceNum]))) <= retPostageMinStickNum) {
            retPostageMinStickNum = tmp;                      //���ݱ���¼��������������С������
            retLastPlanFaceChooseNum = lastPlanFaceChooseNum; //��¼�˴�������������һ����Ʊ����Ҫ������
        }
    }
    postageLastStickNum[hasPlanFaceNum][stickPostage] = retLastPlanFaceChooseNum;    //���һ���������뱸��¼�������
    return postageMinStickNum[hasPlanFaceNum][stickPostage] = retPostageMinStickNum; //���뱸��¼������ֵ
}

/**
 * @brief �ļ������ǰdfs��֧��ѡ��
 * @param hasPlanFaceNum dfs�������Ѿ����úõ���ֵ������Ŀ
 * @param stickPostage  dfs������׼����ϳ�������
 * 
 */
void fOutputDfsThisLv(int hasPlanFaceNum, int dfsMaxPostage) {
    for (int i = 1; i < hasPlanFaceNum; ++i) {
        fprintf(fpout, "\t\t");
    }
    fprintf(fpout, "(x%d=%d,r%d=%d) (", hasPlanFaceNum, dfsFacePlan[hasPlanFaceNum], hasPlanFaceNum, dfsMaxPostage);
    while (dfsMaxPostage) { //�������
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
 * @brief ���ĺ���dfs�������ֵ����
 * @param hasPlanFaceNum dfs�������Ѿ����úõ���ֵ������Ŀ
 */
void dfsGetFacePlan(int hasPlanFaceNum = 0) {
    memset(postageMinStickNum, 0, sizeof(postageMinStickNum)); //��ʼ��
    memset(postageLastStickNum, 0, sizeof(postageLastStickNum));
    int dfsMaxPostage = 0;
    while (!(getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage) <= stickLimit &&
             getPostageMinStickNum(hasPlanFaceNum, dfsMaxPostage + 1) > stickLimit) &&
           hasPlanFaceNum)
        ++dfsMaxPostage; //�õ���������������������

    if (hasPlanFaceNum) //���Ѿ���ѡ���֧�ˣ���ʼ�����֧��Ϣ
        fOutputDfsThisLv(hasPlanFaceNum, dfsMaxPostage);
    if (hasPlanFaceNum == faceLimit) {            //��֧����Ҷ��
        if (dfsMaxPostage > facePlanMaxPostage) { //�����ǰ�������������������ʴ��ڼ�¼��
            facePlanMaxPostage = dfsMaxPostage;   //��¼����
            recordDfsFacePlan();                  //��¼����
        }
        return;
    }
    for (int thisLvChooseFace = dfsFacePlan[hasPlanFaceNum] + 1;
         thisLvChooseFace <= dfsMaxPostage + 1; //�ں���������ڱ�����ǰ��֧��ֵ��ѡ���������������dfs
         ++thisLvChooseFace) {
        dfsFacePlan[hasPlanFaceNum + 1] = thisLvChooseFace; //��¼��ǰ��֧
        dfsGetFacePlan(hasPlanFaceNum + 1);                 //�����²��֧
    }
}

/**
 * @brief �ļ�������շ��䷽��
 */
void dispPlan() {
    fprintf(fpout, "\nFacePlan=<%d", FacePlan[1]);
    for (int i = 2; i <= faceLimit; ++i)
        fprintf(fpout, ",%d", FacePlan[i]);
    fprintf(fpout, ">  PostageRange:[1,%d]", facePlanMaxPostage);
    fclose(fpout);
}

int main() {
    fInitMess();      //�ļ����������� ��ֵ�������� �� ������������
    fOutputMess();    //�ļ�������ڼ���� ��ֵ�������� �� ������������
    dfsGetFacePlan(); //���ĺ���dfs�������ֵ����
    dispPlan();       //�ļ�������շ��䷽��
    return 0;
}
