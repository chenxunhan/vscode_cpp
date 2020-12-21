#include <linux/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

struct sembuf P, V;   //定义PV操作
int cross_mutexid[4]; //第i个路口

void initPV();

void initAllMutex();

void carFleetUp();
void carFleetDown();
void carFleetLeft();
void carFleetRight();

int main() {

    initAllMutex();

    pid_t Down = fork();
    if (Down == 0) {
        while (1)
            carFleetDown();
    } else {
        pid_t Left = fork();
        if (Left == 0) {
            carFleetLeft();
        } else {
            pid_t Right = fork();
            if (Right == 0) {
                while (1)
                    carFleetRight();
            } else {
                while (1)
                    carFleetUp();
            }
        }
    }
    return 0;
}

void initPV() {
    P.sem_num = 0;        //索引值
    P.sem_op = -1;        //每次执行P操作减一(申请)
    P.sem_flg = SEM_UNDO; //操作标志
    V.sem_num = 0;
    V.sem_op = 1; //每次执行V操作加一(释放)
    V.sem_flg = SEM_UNDO;
}

void initAllMutex() {
    initPV();

    union semun arg; //定义信号量的控制参数
    arg.val = 1;     //设置初值
    for (int i = 0; i < 4; ++i) {
        cross_mutexid[i] = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT); //生成1个信号量
        if (semctl(mutexid, 0, SETVAL, arg) == -1)
            perror("cross_mutexid[%d] semctl setval error", i); //为信号量赋初值
    }
}

void carFleetUp() {
    semop(cross_mutexid[3], &P, 1); // P操作
    semop(cross_mutexid[1], &P, 1);
    int waitSec=rand()%5+2;
    printf("carFleetUp will running %d sec...\n",waitSec);
    sleep(waitSec);
    semop(cross_mutexid[3], &V, 1); // V操作
    semop(cross_mutexid[1], &V, 1);
    printf("carFleetUp exit...\n");
}

void carFleetDown() {
    semop(cross_mutexid[0], &P, 1); // P操作
    semop(cross_mutexid[2], &P, 1);
    int waitSec=rand()%5+2;
    printf("carFleetDown will running %d sec...\n",waitSec);
    sleep(waitSec);
    semop(cross_mutexid[0], &V, 1); // V操作
    semop(cross_mutexid[2], &V, 1);
    printf("carFleetDown exit...\n");
}

void carFleetLeft() {
    semop(cross_mutexid[1], &P, 1); // P操作
    semop(cross_mutexid[0], &P, 1);
    int waitSec=rand()%5+2;
    printf("carFleetLeft will running %d sec...\n",waitSec);
    sleep(waitSec);
    semop(cross_mutexid[1], &V, 1); // V操作
    semop(cross_mutexid[0], &V, 1);
    printf("carFleetLeft exit...\n");
}

void carFleetRight() {
    semop(cross_mutexid[2], &P, 1); // P操作
    semop(cross_mutexid[3], &P, 1);
    int waitSec=rand()%5+2;
    printf("carFleetRight will running %d sec...\n",waitSec);
    sleep(waitSec);
    semop(cross_mutexid[2], &V, 1); // V操作
    semop(cross_mutexid[3], &V, 1);
    printf("carFleetRight exit...\n");
}