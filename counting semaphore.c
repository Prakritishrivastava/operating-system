#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s;
void handler(int signal)
{
    sem_post(&s); 
}

void *singsong(void *param)
{
    sem_wait(&s); 
    printf("waiting till i am released\n");
}

int main()
{
    int x = sem_init(&s, 0, 0); 
    if (x == -1) {
       perror("unnamed semaphore");
       return 1;
    }
    signal(SIGINT, handler); 
    pthread_t tid;
    pthread_create(&tid, NULL, singsong, NULL);
    pthread_exit(NULL);
}
