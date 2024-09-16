#include <stdio.h>
#include <pthread.h>

pthread_cond_t is_zero;
pthread_mutex_t mutex;
int shared_data = 100;

void *thread_func(void *arg)
{
    while (shared_data > 0)
    {
        pthread_mutex_lock(&mutex);
        shared_data--;
        printf("Shared_data = %d\n", shared_data);
        pthread_mutex_unlock(&mutex);
    }

    printf("Signaling main\n");
    pthread_cond_signal(&is_zero);
    return NULL;
}

// This is a simple example of how to use conditional variables
// Conditional variables are used to synchronize threads
// In this example, we have a shared_data variable
// The main thread waits for shared_data to be 0
// The thread_func decrements shared_data
// When shared_data is 0, the thread_func signals the main thread
// This is done by using pthread_cond_signal

int main(void)
{
    pthread_t tid;
    void *exit_status;
    int i;

    pthread_cond_init(&is_zero, NULL);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid, NULL, thread_func, NULL);

    pthread_mutex_lock(&mutex);
    printf("Start waiting in main\n");
    while (shared_data != 0)
    {
        pthread_cond_wait(&is_zero, &mutex); // wait for signal
    }
    pthread_mutex_unlock(&mutex);

    printf("Done waiting in main!\n");

    pthread_join(tid, &exit_status);
    return 0;
}