#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
static int shdata = 4;
void *create(void *arg) {
    printf("new pthread ... \n");
    printf("shared data = %d  \n", shdata);
    return (void *) 0;
}
int main(int argc, char *argv[]) {
    //用pthread_create()创建新线程
    pthread_t threadid;
    int error = pthread_create(&threadid,NULL,(void *)create,NULL);
    if (error) {
        printf("new thread is not create ... \n");
        return -1;
    }
    //休眠一段时间
    sleep(1);
    printf("new thread is created ... \n");
    return 0;
}
