#include <pthread.h> 
#include <semaphore.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h>
#define MaxItems 5
#define BufferSize 5
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void *producer(void *pno) 
{
    int item;
    while (1)
    {
		item = rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer : Insert Item %d at %d\n", buffer[in], in); 
		in = (in + 1) % BufferSize;
		sleep(1); 
		pthread_mutex_unlock(&mutex); 
		sem_post(&full);
	}
}
void *consumer(void *cno)
{
	while (1)
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer : Remove Item %d from %d\n", item, out); 
		out = (out + 1) % BufferSize;
		sleep(1);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	} 
}
int main() 
{
	pthread_t pro, con;
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BufferSize);
	sem_init(&full, 0, 0);
	pthread_create(&pro, NULL, (void *)producer, NULL); 
	pthread_create(&con, NULL, (void *)consumer, NULL); 
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
	pthread_mutex_destroy(&mutex); 
	sem_destroy(&empty); 
	sem_destroy(&full);
	return 0;
}
