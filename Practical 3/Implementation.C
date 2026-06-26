#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define MAX_CONCURRENT 3
#define INCREMENTS 100000

int counter = 0;
sem_t semaphore;

void *increment(void *arg)
{
    sem_wait(&semaphore); // Enter semaphore

    printf("Thread %ld entered the critical section.\n", (long)arg);

    for (int i = 0; i < INCREMENTS; i++)
    {
        counter++;
    }

    printf("Thread %ld leaving the critical section.\n", (long)arg);

    sem_post(&semaphore); // Leave semaphore

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // Counting semaphore allows 3 threads at a time
    sem_init(&semaphore, 0, MAX_CONCURRENT);

    for (long i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, increment, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal Counter = %d\n", counter);

    sem_destroy(&semaphore);

    return 0;
}
