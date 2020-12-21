#include <linux/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    struct sembuf P, V;   //����PV����
    P.sem_num = 0;        //����ֵ
    P.sem_op = -1;        //ÿ��ִ��P������һ(����)
    P.sem_flg = SEM_UNDO; //������־
    V.sem_num = 0;
    V.sem_op = 1; //ÿ��ִ��V������һ(�ͷ�)
    V.sem_flg = SEM_UNDO;

    int mutexid;                                        //����һ������������Ϊ�ź���
    mutexid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT); //����1���ź���

    union semun arg; //�����ź����Ŀ��Ʋ���
    arg.val = 1;     //���ó�ֵ

    if (semctl(mutexid, 0, SETVAL, arg) == -1)
        perror("semctl setval error"); //Ϊ�ź�������ֵ

    int child;
    while ((child = fork()) == -1)
        ; //�����ӽ����븸���̻���

    if (child > 0) {
        sleep(1);
        semop(mutexid, &P, 1); // P����
        printf("the parent enter the criti...\n");
        sleep(3); //�����ٽ���
        printf("the parent exit the criti....\n");
        semop(mutexid, &V, 1);        //V����
        wait(0);                      //�ȴ��ӽ����˳�
        semctl(mutexid, IPC_RMID, 0); //�����ź���
        exit(0);
    } else {
        sleep(1);
        semop(mutexid, &P, 1); //P����
        printf("the child enter the criti...\n");
        sleep(3); //�����ٽ���
        printf("the child exit the criti....\n");
        semop(mutexid, &V, 1); //V����
    }
    return 0;
}