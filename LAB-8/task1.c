//WAP for creating 5 threads, which share and increment a global variable count. 
//Threads should print the count value.
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int count = 0;
sem_t s;
void *fun()
{
	sem_wait(&s);
	count++;
	printf("<");
	printf("Hello from thread %d",count);
	printf(">\n");
	sem_post(&s);
}
void main()
{
	sem_init(&s, 0, 1);
	pthread_t t[5];
	for(int i=0;i<5;i++)
	{
		int status = pthread_create(&t[i], NULL, fun, NULL);
	}
	for(int i=0;i<5;i++)
	{
		pthread_join(t[i],NULL);
	}
}
