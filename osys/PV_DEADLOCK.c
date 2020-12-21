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
��
1. ���źŵ�PV����ע�͵������г��򣬷����޸ĺ�ĳ����и��ӽ���ͬʱ�����ٽ��������߼��Ϸ����������޸�֮ǰ���������̽����ٽ����������źŵƶԽ��̿��ƣ�Ҳ��Ҫ�����ٽ������ӽ��̽���Ҫ�ȴ���ֱ���������˳��ٽ�����ȡ�����źŵƵĿ��ƺ󣬸��ӽ��̾ͻ�ͬʱ�����ٽ����������ǲ�����ġ�
2. ����53�����56�д���Ի����ɣ�ʹ�ӽ���ͬ������һ�����ȵõ���x,�ٵõ���y���ɡ���ԭ�������ĳһʱ�̸����̵õ���x�����ӽ��̵õ���y����xy����ռ�ã������ӽ�������Ҫ�õ���һ�����������У���˷����������Ի�֮��ĳһʱ�̸����̵õ���x����x��ռ�ã����ӽ���Ҫ�õ���x�������У�����ռ����y�������̵õ���y���������ֱ���ͷ���xy���ӽ��̱�������������
*/