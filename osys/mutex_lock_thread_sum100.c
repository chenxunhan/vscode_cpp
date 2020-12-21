#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum;
void thread1() {
    for (int i = 0; i <= 100; i += 2) {
        sum += i;
        printf("sum is %d now.\n", sum);
        sleep(1);
    }
    pthread_exit(NULL);
}

void thread2() {
   for (int i = 1; i <= 100; i += 2) {
        sum += i;
        printf("sum is %d now.\n", sum);
        sleep(1);
    }
}

int main() {
    pthread_t id1, id2;
    pthread_mutex_init(&count_lock, NULL);
    sum = 0;
    
    pthread_create(&id1, NULL, (void *) thread1, NULL);
    pthread_create(&id2, NULL, (void *) thread2, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}
