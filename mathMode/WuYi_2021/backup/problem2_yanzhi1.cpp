#include <bits/stdc++.h>
using namespace std;

int order[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

class Drug {
  public:
    int id;
};
queue<Drug> q[5];

double meanData[10 + 1][4 + 1]; //[种类][工序]

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
    for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j <= 10; ++j) {
            meanData[i][j] = 1;
        }
    }
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

int main() {
    do {

        fprintf(fpout, "\n\n");
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
                    printf("%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                } else {
                    printf("%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d in CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                }
            } else { //trs!=0
                pastTime += trs;
                for (int i = 1; i <= 4; ++i) {
                    workTable[i].resTime -= trs;
                    workTable[i].resTime = max(0.0, workTable[i].resTime); //可以注释
                }
                if (ti != 4) {
                    printf("%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    workTable[ti].pushBackQueue();
                    workTable[ti].reset();
                } else {
                    printf("%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    fprintf(fpout, "%d out CJ%d at %lf\n", workTable[ti].nowProduceId, ti, pastTime);
                    workTable[ti].reset();
                }
            }
        } while (!(allQueueEmpty() && allWorkTableDone()));

    } while (next_permutation(order + 1, order + 1 + 10));

    fclose(fpout);
    return 0;
}