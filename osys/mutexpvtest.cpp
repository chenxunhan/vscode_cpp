#include <linux/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    struct sembuf P, V;   //定义PV操作
    P.sem_num = 0;        //索引值
    P.sem_op = -1;        //每次执行P操作减一(申请)
    P.sem_flg = SEM_UNDO; //操作标志
    V.sem_num = 0;
    V.sem_op = 1; //每次执行V操作加一(释放)
    V.sem_flg = SEM_UNDO;

    int mutexid;                                        //定义一个公共变量作为信号量
    mutexid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT); //生成1个信号量

    union semun arg; //定义信号量的控制参数
    arg.val = 1;     //设置初值

    if (semctl(mutexid, 0, SETVAL, arg) == -1)
        perror("semctl setval error"); //为信号量赋初值

    int child;
    while ((child = fork()) == -1)
        ; //创建子进程与父进程互斥

    if (child > 0) {
        sleep(1);
        semop(mutexid, &P, 1); // P操作
        printf("the parent enter the criti...\n");
        sleep(3); //进入临界区
        printf("the parent exit the criti....\n");
        semop(mutexid, &V, 1);        //V操作
        wait(0);                      //等待子进程退出
        semctl(mutexid, IPC_RMID, 0); //撤消信号量
        exit(0);
    } else {
        sleep(1);
        semop(mutexid, &P, 1); //P操作
        printf("the child enter the criti...\n");
        sleep(3); //进入临界区
        printf("the child exit the criti....\n");
        semop(mutexid, &V, 1); //V操作
    }
    return 0;
}