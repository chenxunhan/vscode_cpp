#include <bits/stdc++.h>
using namespace std;

const int MAXINITPOSNUM = 5;
const int MAXCLCARNUM = 5 * MAXINITPOSNUM;
const int MAXTRANSCARNUM = 5 * MAXINITPOSNUM;
const int MAXCLCPEONUM = 5 * MAXINITPOSNUM;

const int SNOWNUM = 30;
const int NODENUM = 141;
const int LINKNUM = 241;

const int outPlanLineNum = 43 - 2 + 1; //need input
const int outPlanTitleNum = 7;

class GetPicXY {
  private:
    int clcarNo[outPlanLineNum + 1];
    int clcarPos[outPlanLineNum + 1];
    int nextPos[outPlanLineNum + 1];
    int snowNo[outPlanLineNum + 1];
    int snowWeight[outPlanLineNum + 1];
    double clcArriveT[outPlanLineNum + 1];
    double clcTaskEndT[outPlanLineNum + 1];

    double snowX[SNOWNUM + 1][3 + 1];
    double snowY[SNOWNUM + 1][3 + 1];
    double clcarCleanSnowX[MAXCLCARNUM][outPlanLineNum + 1];
    double clcarCleanSnowY[MAXCLCARNUM][outPlanLineNum + 1];

  public:
    void inputPlanData() {
        FILE *fpin = fopen("D://MathMode//outputPlan.txt", "r");

        char firstline[200];
        fgets(firstline, 200, fpin);
        for (int i = 1; i <= outPlanLineNum; ++i) {
            fscanf(fpin, "%d%d%d%d%d%lf%lf", clcarNo + i, clcarPos + i, nextPos + i,
                   snowNo + i, snowWeight + i, clcArriveT + i, clcTaskEndT + i);
        }

        fclose(fpin);
    }

    void foutSnowPic() {
        //getx y
        for (int i = 1; i <= SNOWNUM; ++i) {
            for (int j = 1; j <= outPlanLineNum; ++j) {
                if (snowNo[j] == i) {
                    snowX[i][1] = 0;
                    snowX[i][2] = clcArriveT[j];
                    snowX[i][3] = clcTaskEndT[j];

                    snowY[i][3] = 0;
                    snowY[i][1] = snowY[i][2] = snowWeight[j];

                    break;
                }
            }
        }
        FILE *fout = fopen("D://MathMode//outputSnowXY.txt", "w");
        //output x
        for (int i = 1; i <= SNOWNUM; ++i) {
            fprintf(fout, "0,%.4lf,%.4lf;\n", snowX[i][2], snowX[i][3]);
        }
        fprintf(fout, "\n\n");
        //output y
        for (int i = 1; i <= SNOWNUM; ++i) {
            fprintf(fout, "%.0lf,%.0lf,0;\n", snowY[i][1], snowY[i][2]);
        }
        fclose(fout);
    }

    void foutClcarCleanSnowPic() {
        //needinput
        int clcarNum = 4 + 4 + 4;
        //getx y
        // int idx = 2;
        int idx[clcarNum + 1];
        for (int i = 1; i <= clcarNum; ++i) {
            clcarCleanSnowX[i][1] = 0;
            idx[i] = 2;
            clcarCleanSnowY[i][1] = clcarCleanSnowY[i][2] = 0;

            for (int j = 1; j <= outPlanLineNum; ++j) {
                if (clcarNo[j] == i) {
                    clcarCleanSnowX[i][idx[i]] = clcArriveT[j];
                    clcarCleanSnowX[i][idx[i] + 1] = clcTaskEndT[j];

                    clcarCleanSnowY[i][idx[i] + 1] = clcarCleanSnowY[i][idx[i] + 2] = clcarCleanSnowY[i][idx[i] - 1] + snowWeight[j];

                    if (snowNo[j] == -1) {
                        break;
                    }
                    idx[i] += 2;
                }
            }
        }

        FILE *fout = fopen("D://MathMode//outputClcarCleanSnowXY.txt", "w");
        //output x
        for (int i = 1; i <= clcarNum; ++i) {
            fprintf(fout, "0,");
            for (int j = 2; j < idx[i]; ++j) {
                fprintf(fout, "%.4lf,", clcarCleanSnowX[i][j]);
            }
            fprintf(fout, "%.4lf;\n", clcarCleanSnowX[i][idx[i]]);
        }
        fprintf(fout, "\n\n");
        //output y
        for (int i = 1; i <= clcarNum; ++i) {
            fprintf(fout, "0,0,");
            for (int j = 3; j < idx[i]; ++j) {
                fprintf(fout, "%.0lf,", clcarCleanSnowY[i][j]);
            }
            fprintf(fout, "%.0lf;\n", clcarCleanSnowY[i][idx[i]]);
        }
        fclose(fout);
    }

} getPicXY;

int main() {
    //needinput const int outPlanLineNum = 43 - 2 + 1; //need input
    getPicXY.inputPlanData();
    getPicXY.foutSnowPic();

    //needinput// int clcarNum = 2+2+9;
    getPicXY.foutClcarCleanSnowPic();
    return 0;
}