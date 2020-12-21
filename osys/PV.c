#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/sem.h>

int mutexid;

int main()
{
  int child;
  struct sembuf P,V;
  union semun arg;
  
  mutexid = semget(IPC_PRIVATE, 1, 0666 |  IPC_CREAT);
  arg.val=1;
  if(semctl(mutexid, 0, SETVAL, arg) == -1)
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
     sleep(1);
     semop(mutexid, &P, 1);
     printf("the parent enter the critical section\n");
     sleep(3);
     printf("the parent exit the critical section\n");
     semop(mutexid, &V, 1);

     wait(0);
     semctl(mutexid, IPC_RMID, 0);
     exit(0);
   }
   else
  {
     sleep(1);
     semop(mutexid, &P, 1);
     printf("the child enter the critical section\n");
     sleep(3);
     printf("the child exit the critical section\n");
     semop(mutexid, &V, 1);
     exit(0);
  }

} 

   




