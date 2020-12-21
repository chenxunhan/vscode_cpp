#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t count_lock;

void thread1()
{
        pthread_mutex_lock(&count_lock);
       	printf("the thread1 enter the cirtical section..\n");
	sleep(2);
	printf("the thread1 exit the cirtical section..\n");
        pthread_mutex_unlock(&count_lock);
        pthread_exit(NULL);
}

void thread2()
{
        pthread_mutex_lock(&count_lock);
       	printf("the thread2 enter the cirtical section..\n");
	sleep(2);
	printf("the thread2 exit the cirtical section..\n");
        pthread_mutex_unlock(&count_lock);
        pthread_exit(NULL);
}

int main()
{
        pthread_t id1, id2;
        pthread_mutex_init(&count_lock, NULL);
       
        pthread_create(&id1, NULL, (void*)thread1, NULL);
	pthread_create(&id2, NULL, (void*)thread2, NULL);

        pthread_join(id1, NULL);
	pthread_join(id2,NULL);
}
