#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/sem.h>

int mutexid_x, mutexid_y;

int main()
{
  int child;
  struct sembuf P,V;
  union semun arg;
  
  mutexid_x = semget(IPC_PRIVATE, 1, 0666 |  IPC_CREAT);
  mutexid_y = semget(IPC_PRIVATE, 1, 0666 |  IPC_CREAT);

  arg.val=1;
  if(semctl(mutexid_x, 0, SETVAL, arg) == -1)
    perror("semctl setval error");
  if(semctl(mutexid_y, 0, SETVAL, arg) == -1)
    perror("semctl setval error");
  
  P.sem_num = 0;
  P.sem_op = -1;
  P.sem_flg = SEM_UNDO;
  V.sem_num = 0;
  V.sem_op = 1;
  V.sem_flg = SEM_UNDO;

  while((child=fork())==-1);
  if(child>0)
  {
     semop(mutexid_x, &P, 1);
     printf("the parent get the lock x\n");
     sleep(1);
     semop(mutexid_y, &P, 1);
     printf("the parent get the lock y\n");

     printf("the parent enter the critical section\n");
     sleep(3);
     printf("the parent exit the critical section\n");
     semop(mutexid_x, &V, 1);
     semop(mutexid_y, &V, 1);

     wait(0);
     semctl(mutexid_x, IPC_RMID, 0);
     exit(0);
   }
   else
  {
     semop(mutexid_y, &P, 1);
     printf("the child get the lock y\n");
     sleep(1);
     semop(mutexid_x, &P, 1);
     printf("the child get the lock x\n");

     printf("the child enter the critical section\n");
     sleep(3);
     printf("the child exit the critical section\n");
     semop(mutexid_y, &V, 1); 
     semop(mutexid_x, &V, 1);
     exit(0);
  }

} 

/*
答：
1. 将信号灯PV操作注释掉后，运行程序，发现修改后的程序中父子进程同时进入临界区，在逻辑上发生错误。在修改之前，当父进程进入临界区后，由于信号灯对进程控制，也想要进入临界区的子进程将需要等待，直到父进程退出临界区，取消了信号灯的控制后，父子进程就会同时进入临界区，而这是不允许的。
2. 将第53行与第56行代码对换即可，使子进程同父进程一样，先得到锁x,再得到锁y即可。在原来会存在某一时刻父进程得到锁x，而子进程得到锁y，锁xy都被占用，而父子进程又需要得到另一把锁才能运行，因此发生死锁。对换之后，某一时刻父进程得到锁x，锁x被占用，而子进程要得到锁x才能运行，不会占用锁y，父进程得到锁y后继续运行直到释放锁xy，子进程便会继续正常运行
*/