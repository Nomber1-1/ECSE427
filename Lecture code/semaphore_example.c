#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t threads[5];
int tid[5];
sem_t sem;

void * thread_func(void *arg){
    int tid_ = tid[* (int *) arg];
    printf("Thread %d created\n", tid_);
    int j;

    sem_wait(&sem);
    for(j=0; j<3; j++){
        printf("T%d run %d\n", tid_, j);
        sleep(2);
    }
    sem_post(&sem);
}

int main(){
    int i;
    for (i=0; i<5; i++){
        tid[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &i);
    }

    for (i=0; i<5; i++){
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&sem);
    return 0;
}