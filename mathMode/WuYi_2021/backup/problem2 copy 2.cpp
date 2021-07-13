#include <bits/stdc++.h>
using namespace std;
double MINANS = DBL_MAX;
int MINANSorder[11];
// int order[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int order[11] = {0, 10, 9, 8, 7, 6, 5, 4, 3, 1, 2};

class Drug {
  public:
    int id;
};
queue<Drug> q[5];

double meanData[10 + 1][4 + 1] = {

    {0, 0, 0, 0, 0},
    {0, 13.2840, 14.9621, 19.8460, 20.0129},
    {0, 9.8709, 19.9075, 17.9282, 18.9424},
    {0, 20.0584, 15.9726, 14.9704, 15.1164},
    {0, 7.9887, 9.9366, 5.9359, 18.1284},
    {0, 8.7701, 13.7220, 13.0052, 11.2495},
    {0, 19.0741, 20.0944, 14.1485, 13.8839},
    {0, 11.1601, 16.4961, 12.0137, 19.0876},
    {0, 16.0201, 8.8275, 18.1144, 16.8314},
    {0, 15.0146, 12.0351, 7.0419, 8.9497},
    {0, 12.9524, 7.0110, 9.0492, 16.0524}}; //[种类][工序]

class WorkTable {
  public:
    int id;
    int nowProduceId;
    double resTime;
    bool hasFrontQueue() {
        return !q[id].empty();
    }
    bool isEmpty() {
        return resTime == 0;
    }
    void reset() {
        nowProduceId = 0;
        resTime = 0;
    }
    void getFrontQueue() {
        nowProduceId = q[id].front().id;
        resTime = meanData[nowProduceId][id];
        q[id].pop();
    }
    void pushBackQueue() {
        q[id + 1].push(Drug{nowProduceId});
    }
} workTable[5];

double pastTime;

void reset() {
    pastTime = 0;
    for (int i = 1; i <= 4; ++i) {
        workTable[i].id = i;
        workTable[i].reset();
    }
    for (int i = 1; i <= 10; ++i) {
        q[1].push(Drug{i});
    }
}

bool allQueueEmpty() {
    for (int i = 1; i <= 4; ++i) {
        if (!q[i].empty()) {
            return 0;
        }
    }
    return 1;
}

bool allWorkTableDone() {
    for (int i = 1; i <= 4; ++i) {
        if (!workTable[i].isEmpty()) {
            return 0;
        }
    }
    return 1;
}
FILE *fpout = fopen("output.txt", "w");

void recordMINANS() {
    MINANS = pastTime;
    for (int i = 1; i <= 10; ++i) {
        MINANSorder[i] = order[i];
    }
}
void printMINANS() {
    fprintf(fpout, "\nMINANS_order:");
    for (int i = 1; i <= 10; ++i) {
        fprintf(fpout, "%3d", MINANSorder[i]);
    }
    fprintf(fpout, "\nMINANS=%lf", MINANS);
}

int main() {
    do {

        fprintf(fpout, "\n");
        for (int i = 1; i <= 10; ++i) {
            fprintf(fpout, "%3d", order[i]);
        }
        fprintf(fpout, "\n");

        reset();
        do {
            int ti;
            double trs = DBL_MAX;
            for (int i = 1; i <= 4; ++i) {
                if (workTable[i].hasFrontQueue() || !workTable[i].isEmpty()) {
                    if (workTable[i].resTime < trs) {
                        trs = workTable[i].resTime;
                        ti = i;
                    }
                }
            }
            if (trs == 0) {
                workTable[ti].getFrontQueue();
                if (ti == 1) {
                    // printf("%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                } else {
                    // printf("%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                }
            } else { //trs!=0
                pastTime += trs;
                for (int i = 1; i <= 4; ++i) {
                    workTable[i].resTime -= trs;
                    workTable[i].resTime = max(0.0, workTable[i].resTime); //可以注释
                }
                if (ti != 4) {
                    // printf("%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    workTable[ti].pushBackQueue();
                    workTable[ti].reset();
                } else {
                    // printf("%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    if (workTable[ti].nowProduceId == order[10]) {
                        fprintf(fpout, ":%lf\n", pastTime);
                        if (pastTime < MINANS) {
                            // MINANS = pastTime;
                            recordMINANS();
                        }
                    }
                    workTable[ti].reset();
                }
            }
        } while (!(allQueueEmpty() && allWorkTableDone()));

    } while (next_permutation(order + 1, order + 1 + 10));

    printMINANS();
    fclose(fpout);
    return 0;
}