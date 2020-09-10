#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int x,y;
sem_t sem;
void ScanNumbers(void *ptr){
    for (;;){
        printf("%s", (char *)ptr);
        scanf("%d %d", &x, &y);
        sem_post(&sem);
        usleep(100 * 1000);
    }
}
void SumAndPrint(void *ptr){
    for (;;){
        sem_wait(&sem);
        printf("%s %d\n", (char *)ptr, x + y);
    }
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    char *m1 = "Enter Number Two No\n";
    char *m2 = "sum = ";
    sem_init(&sem, 0, 0);
    pthread_create(&thread1, NULL, (void *)ScanNumbers, (void *)m1);
    pthread_create(&thread2, NULL, (void *)SumAndPrint, (void *)m2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Wait For Both Thread Finished\n");
    sem_destroy(&sem);
    return 0;
}
