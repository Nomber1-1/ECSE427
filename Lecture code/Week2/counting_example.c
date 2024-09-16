#include <stdio.h>
#include <pthread.h>

int count;
void *mythread(void *arg)
{
    int j;
    for (j = 0; j < 1000000; j++)
    {
        count = count + 1;
    }
    return NULL;
}

// Result will never be 2000000
// This is because the threads are not synchronized
// They are not waiting for each other to finish
// Hence, they are overwriting each other's values

int main(int argc, char *argv[])
{
    pthread_t p1, p2;
    count = 0;
    printf("main: begin (counter = %d)\n", count);
    pthread_create(&p1, NULL, mythread, NULL);
    pthread_create(&p2, NULL, mythread, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main: end (counter = %d)\n", count);
    return 0;
}