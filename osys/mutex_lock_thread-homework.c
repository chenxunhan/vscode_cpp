#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t count_lock;
int sum;

void thread1()
{
	int t=1;
	while(t<=99){
		//这里还是保留了对sum写入前的上锁
		pthread_mutex_lock(&count_lock);
		sum=sum+t;
		t=t+2;
		printf("thread1 get new result: %d\n", sum);
		pthread_mutex_unlock(&count_lock);
		//这里跟实验课讲的不同的是，开锁之后睡一下，这样就不会马上又循环地把锁锁上了。
		sleep(1);
	}
        pthread_exit(NULL);
}

void thread2()
{
	int t=2;
	while(t<=100){
		//这里还是保留了对sum写入前的上锁
		pthread_mutex_lock(&count_lock);
		sum=sum+t;
		t=t+2;
		printf("thread2 get new result: %d\n", sum);
		pthread_mutex_unlock(&count_lock);
		//这里跟实验课讲的不同的是，开锁之后睡一下，这样就不会马上又循环地把锁锁上了。
		sleep(1);
	}
        pthread_exit(NULL);
}

int main()
{
	sum=0;
        pthread_t id1, id2;
        pthread_mutex_init(&count_lock, NULL);
       
        pthread_create(&id1, NULL, (void*)thread1, NULL);
	pthread_create(&id2, NULL, (void*)thread2, NULL);

        pthread_join(id1, NULL);
	pthread_join(id2,NULL);
}
