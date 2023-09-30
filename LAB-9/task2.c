//Writers having priority
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define max 3
sem_t x, y, z, rsem, wsem;
int readcount, writecount;
void *reader();
void *writer();
int value = 1;
void *reader(void *arg)
{
    while (1)
    {
        int n = (intptr_t)arg;
        sem_wait(&z);
        sem_wait(&rsem);
        sem_wait(&x);
        readcount++;
        if (readcount == 1)
        {
            sem_wait(&wsem);
        }
        sem_post(&x);
        sem_post(&rsem);
        sem_post(&z);
        printf("Reader %d is Reading the Value as %d.\n",n,value);
        sem_wait(&x);
        readcount--;
        if (readcount == 0)
        {
            sem_post(&wsem);
        }
        sem_post(&x);
        sleep(1);
    }
}
void *writer(void *arg)
{
    while (1)
    {
        sem_wait(&y);
        writecount++;
        if (writecount == 1)
        {
            sem_wait(&rsem);
        }
        sem_post(&y);
        sem_wait(&wsem);
        value++;
        int n=(intptr_t)arg;
        printf("Writer %d has updated the Value to %d.\n",n,value);
        sem_post(&wsem);
        sem_wait(&y);
        writecount--;
        if (writecount == 0)
        {
            sem_post(&rsem);
        }
        sem_post(&y);
        sleep(3);
    }
}
void main()
{
    pthread_t read[max], write[max];
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    sem_init(&z, 0, 1);
    sem_init(&rsem, 0, 1);
    sem_init(&wsem, 0, 1);
    for (int i = 0; i < max; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)(intptr_t)i);
    }
    for (int i=0; i<max; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)(intptr_t)i);
    }
    for (int i=0; i<max; i++)
    {
        pthread_join(read[i], NULL);
    }
    for (int i=0; i<max; i++)
    {
        pthread_join(write[i], NULL);
    }
    sem_destroy(&x);
    sem_destroy(&y);
    sem_destroy(&z);
    sem_destroy(&rsem);
    sem_destroy(&wsem);
}
