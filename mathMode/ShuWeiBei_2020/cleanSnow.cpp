#include <bits/stdc++.h>
using namespace std;

const int MAXINITPOSNUM = 5;
const int MAXCLCARNUM = 5 * MAXINITPOSNUM;
const int MAXTRANSCARNUM = 5 * MAXINITPOSNUM;
const int MAXCLCPEONUM = 5 * MAXINITPOSNUM;

const int SNOWNUM = 30;
const int NODENUM = 141;
const int LINKNUM = 241;

int initPosNumber = 0;
int clcarNum = 0;
int transcarNum = 0;
int clcPeoNum = 0;

// double XYB[MAXCLCARNUM][SNOWNUM];
// double ShorteDistance[NODENUM+1][NODENUM+1]={0};

struct {
    double snowHeight;
    double hasPastTime = 0;
    double hasClcSnow = 0;
    int clcarRetHomeNum = 0;
    double snowDensity; //雪的密度
    // int greenSnowHeight;
} MainMess;

struct InitPos {
    int nodeNo;
    int clcarNumber;
    int clcPeoNumber;
    int transCarNumber;
    /*
    double lon,lat;
    */
} initPos[MAXINITPOSNUM + 1];

struct WorkerMess {
    int number;    //
    int run_speed; // (m/min)
};

struct Link {
    double originalDistance = 0; //save dis
    double shorteDistance = 0;
    int importantaceLv = 0;
} link[NODENUM + 1][NODENUM + 1];

void inputLinkDisByFile() {
    FILE *fin = fopen("D://MathMode//DisNoInfSig.txt", "r");
    for (int i = 1; i <= NODENUM; ++i) {
        for (int j = 1; j <= NODENUM; ++j) {
            fscanf(fin, "%lf", &link[i][j].originalDistance);
            // link[j][i].originalDistance = link[i][j].originalDistance;
        }
    }
    for (int i = 1; i <= NODENUM; ++i) {
        for (int j = 1; j <= NODENUM; ++j) {
            fscanf(fin, "%lf", &link[i][j].shorteDistance);
            // link[j][i].shorteDistance = link[i][j].shorteDistance;
        }
    }
    fclose(fin);
}

struct Clcar {
    // int no;
    int originalPosNodeNo;
    int posNodeNo;
    double taskEndTime = 0;
    bool isPlaned = 0;
} clcar[MAXCLCARNUM];

struct {
    int number;
    double runSpeed;   //km/h
    double cleanSpeed; //  yse:(kg/h)  x:(m^3/h)
} ClcarMess;

struct {
    int number;
    int run_speed;
    int box_size;
} TransCarMess;

struct Snow {
    // int serial_no;
    /*
    double lon,lat;
    */
    int posNodeNo; //对应的节点
    double area;   //m^2
    double weight;
    bool isCleaning = 0;
    bool isCleanUp = 0;
} snow[SNOWNUM + 1];

bool hasSnowAllCleanUp() {
    for (int i = 1; i <= SNOWNUM; ++i) {
        if (snow[i].isCleanUp == 0) {
            return 0;
        }
    }
    return 1;
}
bool hasSnowAllCleaning() {
    for (int i = 1; i <= SNOWNUM; ++i) {
        if (snow[i].isCleaning == 0) {
            return 0;
        }
    }
    return 1;
}

struct Node {
    int Value = 0;
} node[NODENUM + 1];

//函数返回方案序列<clcar.no,snow.no,clcar.taskendtime>
struct Plan {
    int clcarNo;
    int clcarBefPosNo;
    int clcarNextPos;
    int snowNo;
    double taskEndTime;
    // double taskEndTime;
};

bool hasClcarAllUsed() {
    for (int i = 1; i <= clcarNum; ++i) {
        if (clcar[i].isPlaned == 0) {
            return 0;
        }
    }
    return 1;
}

vector<Plan> plan;
bool plancmp(Plan a, Plan b) {
    return a.taskEndTime < b.taskEndTime;
}
void CleanSnowPlan() {
    // memset(XYB, 0, sizeof(XYB));
    bool haveClcarPlan = 0;
    int planidx = 0;
    int clcarPlanNum = 0;
    while (MainMess.clcarRetHomeNum != clcarNum) {
        while (!(/*hasSnowAllCleanUp() ||*/ hasClcarAllUsed())) { //cleaning不用回归
            double maxValue = -1;
            // double maxXYB = 0;
            int planClcarNo, cleaningSnowNo;
            haveClcarPlan = 0;
            for (int i = 1; i <= clcarNum; ++i) {
                if (clcar[i].isPlaned == 1) {
                    continue;
                }
                if (hasSnowAllCleaning() == 1) {
                    ++MainMess.clcarRetHomeNum;
                    clcar[i].isPlaned = 1;
                    clcar[i].taskEndTime += (link[clcar[i].posNodeNo][clcar[i].originalPosNodeNo].shorteDistance / ClcarMess.runSpeed);
                    plan.push_back({i, clcar[i].posNodeNo, clcar[i].originalPosNodeNo, -1, clcar[i].taskEndTime});
                    continue;
                    //回家
                }
                haveClcarPlan = 1;
                for (int j = 1; j <= SNOWNUM; ++j) {
                    if (snow[j].isCleanUp || (!snow[j].isCleanUp && snow[j].isCleaning)) {
                        continue;
                    }
                    /*
                    // XYB[i][j] = 1 +
                    printf("clcar[%d].taskenetime=%lf\n", clcar[i].taskEndTime);
                    printf("[clcar[%d].posNodeNo][snow[%d].posNodeNo]=[%d][%d]\n", i, j, clcar[i].posNodeNo, snow[j].posNodeNo);
                    printf("clcar[i].taskEndTime + (link[clcar[i].posNodeNo][snow[j].posNodeNo].shorteDistance / ClcarMess.runSpeed)=%lf\n", (clcar[i].taskEndTime + (link[clcar[i].posNodeNo][snow[j].posNodeNo].shorteDistance / ClcarMess.runSpeed)));
                    exit(0);*/
                    // printf("%lf\n", snow[j].weight / ClcarMess.cleanSpeed);
                    double XYB;
                    if (clcar[i].taskEndTime == 0) {
                        XYB = 100 / (link[clcar[i].posNodeNo][snow[j].posNodeNo].shorteDistance / ClcarMess.runSpeed + snow[j].weight / ClcarMess.cleanSpeed);
                    } else {
                        XYB = 1 +
                              clcar[i].taskEndTime /
                                  (link[clcar[i].posNodeNo][snow[j].posNodeNo].shorteDistance / ClcarMess.runSpeed + snow[j].weight / ClcarMess.cleanSpeed);
                    }
                    int Value = XYB * node[snow[j].posNodeNo].Value * node[snow[j].posNodeNo].Value;
                    // if (XYB > maxXYB) {
                    if (Value > maxValue) {
                        maxValue = Value;
                        // maxXYB = XYB;
                        planClcarNo = i;
                        cleaningSnowNo = j;
                    }
                }
            }
            int clcarBefPosNo;
            if (haveClcarPlan) {
                clcar[planClcarNo].isPlaned = 1;
                clcarBefPosNo = clcar[planClcarNo].posNodeNo;
                clcar[planClcarNo].posNodeNo = snow[cleaningSnowNo].posNodeNo;
                clcar[planClcarNo].taskEndTime +=
                    link[clcarBefPosNo][snow[cleaningSnowNo].posNodeNo].shorteDistance / ClcarMess.runSpeed + ((snow[cleaningSnowNo].weight) / ClcarMess.cleanSpeed);

                snow[cleaningSnowNo].isCleaning = 1;
                plan.push_back({planClcarNo, clcarBefPosNo, snow[cleaningSnowNo].posNodeNo, cleaningSnowNo, clcar[planClcarNo].taskEndTime}); //计划加入
                ++clcarPlanNum;
            }
        }

        // if (planidx >= clcarPlanNum) {
        if (MainMess.clcarRetHomeNum == clcarNum) {
            break;
        }
        if (haveClcarPlan) {
            sort(plan.begin(), plan.end(), plancmp);
        }
        MainMess.hasPastTime = clcar[plan[planidx].clcarNo].taskEndTime;
        clcar[plan[planidx].clcarNo].isPlaned = 0;
        snow[plan[planidx].snowNo].isCleanUp = 1;
        ++planidx;
    }
    sort(plan.begin(), plan.end(), plancmp);
}

void fOutputPlan() {
    FILE *fout = fopen("D://MathMode//outputPlan.txt", "w");
    fprintf(fout, "clcarNo,  clcarPos,  nextPos,  snowNo,  snowWeight,  clcArriveT,  clcTaskEndT, \n");
    for (int i = 0; i < plan.size(); ++i) {
        // fprintf(fout, "%7d%9d%8d%8d%12.4lf%11.0lf\n", plan[i].clcarNo, plan[i].clcarBefPosNo, plan[i].clcarNextPos, plan[i].snowNo, plan[i].taskEndTime, snow[plan[i].snowNo].weight);
        fprintf(fout, "%7d, %9d, %8d, %7d, %11.0lf, %11.4lf, %12.4lf,\n",
                plan[i].clcarNo, plan[i].clcarBefPosNo,
                plan[i].clcarNextPos, plan[i].snowNo, snow[plan[i].snowNo].weight,
                plan[i].taskEndTime - snow[plan[i].snowNo].weight / ClcarMess.cleanSpeed, plan[i].taskEndTime);
    }
    fclose(fout);
}

void inputSnowByFile() {
    double lon, lat;
    FILE *fin = fopen("D://MathMode//inputsnow.txt", "r");
    for (int i = 1; i <= SNOWNUM; ++i) {
        fscanf(fin, "%lf %lf %lf %d", &lon, &lat, &snow[i].area, &snow[i].posNodeNo);
        snow[i].weight = MainMess.snowDensity * MainMess.snowHeight * snow[i].area;
    }
    fclose(fin);
}

void inputLinkValue() {
    int na, nb, va;
    FILE *fin = fopen("D://MathMode//inputLinkValue.txt", "r");
    for (int i = 1; i <= LINKNUM; ++i) {
        fscanf(fin, "%d%d%d", &na, &nb, &va);
        link[na][nb].importantaceLv = link[nb][na].importantaceLv = va;
        node[na].Value += va, node[nb].Value += va;
    }
    fclose(fin);
}

void InitMode() {
    //初始化雪的高度要注意cm->m
    //所有车子的数组结构体初始化
    //初始化node
    {
        MainMess.snowHeight = 30 * 0.01; //cm->m
        MainMess.snowDensity = 136.36;   //https://www.xuexi88.com/zhishi/111404.html 呼和浩特是华北
    }
    {
        ClcarMess.cleanSpeed = 1500 * 1000;
        // ClcarMess.number = ;
        ClcarMess.runSpeed = 30;
    }
    {
        // TransCarMess.number = ;
        TransCarMess.run_speed = 30;
        // TransCarMess.box_size = ;
    }

    { //initpos
        FILE *fpin = fopen("D://MathMode//inputInitPos.txt", "r");
        fscanf(fpin, "%d", &initPosNumber);
        for (int i = 1; i <= initPosNumber; ++i) {
            fscanf(fpin, "%d %d %d %d", &initPos[i].nodeNo,
                   &initPos[i].clcPeoNumber,
                   &initPos[i].clcarNumber,
                   &initPos[i].transCarNumber);
            clcPeoNum += initPos[i].clcPeoNumber;
            clcarNum += initPos[i].clcarNumber;
            transcarNum += initPos[i].transCarNumber;
        }
        fclose(fpin);
    }

    {
        //clcar[]
        for (int i = 1, idx = 1; i <= initPosNumber; ++i) {
            for (int j = 1; j <= initPos[i].clcarNumber; ++j) {
                clcar[idx].originalPosNodeNo = clcar[idx].posNodeNo = initPos[i].nodeNo;
                ++idx;
            }
        }
    }
    inputLinkDisByFile();
    inputLinkValue();
    inputSnowByFile();
}

int main() {
    InitMode();
    CleanSnowPlan();
    fOutputPlan();
    return 0;
}