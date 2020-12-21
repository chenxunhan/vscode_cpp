#include <linux/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

struct sembuf P, V;
union semun arg;

int ProcessBId;
int ProcessCId;

void init() {
    arg.val = 0;

    ProcessBId = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    if (semctl(ProcessBId, 0, SETVAL, arg) == -1)
        perror("ProcessBId semctl setval error");

    ProcessCId = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    if (semctl(ProcessCId, 0, SETVAL, arg) == -1)
        perror("ProcessCId semctl setval error");

    P.sem_num = 0;
    P.sem_op = -1;
    P.sem_flg = SEM_UNDO;
    V.sem_num = 0;
    V.sem_op = 1;
    V.sem_flg = SEM_UNDO;
}

void ProcessA() {
    sleep(3);
    printf("A finished\n");

    semop(ProcessBId, &V, 1);
    semop(ProcessCId, &V, 1);
}

void ProcessB() {
    printf("B is waiting...\n")
        semop(ProcessBId, &P, 1);
    printf("B finished\n")
}

void ProcessC() {
    printf("C is waiting...\n")
        semop(ProcessCId, &P, 1);
    printf("C finished\n")
}

int main() {
    init();
    pid_t childB = fork();
    if (childB == 0) { //this is child B
        ProcessB();
    } else { //this is father A
        pid_t childC = fork();
        if (childC == 0) {
            ProcessC();
        } else {
            ProcessA();
        }
    }

    return 0;
}