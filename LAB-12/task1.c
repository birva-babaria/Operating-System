#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
sem_t customers, barbers, mutex;
int waiting = 0;
const int chairs = 10;
void *barber()
{
	while (1)
	{
 		sem_wait(&customers);
		sem_wait(&mutex);
		waiting--;
		sem_post(&barbers);
		sem_post(&mutex);
		puts("barber is cutting");
		printf("%d custmoers are in waiting\n", waiting);
		sleep(2);
 	}
}
void *customer()
{
	sem_wait(&mutex);
	if (waiting < chairs)
	{
		waiting++;
		sem_post(&customers);
		sem_post(&mutex);
		sem_wait(&barbers);
		sleep(5);
	}
 	else
 	{
 		sem_post(&mutex);
 	}
}
int main()
{
 	pthread_t barber_thread, customer_thread[3];
 	sem_init(&customers, 0, 0);
 	sem_init(&barbers, 0, 0);
 	sem_init(&mutex, 0, 1);
 	pthread_create(&barber_thread, NULL, barber, NULL);
 	for (int i = 0; i < 10; i++)
 	{
 		pthread_create(&customer_thread[i], NULL, customer, NULL);
 	}
 	pthread_join(barber_thread, NULL);
 	for (int i = 0; i < 10; i++)
 	{
 		pthread_join(customer_thread[i], NULL);
 	}
 	return 0;
}
