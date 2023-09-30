//Readers having priority
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int count = 0;
int value = 0;
sem_t x,wsem;
void *reader(void *arg)
{
	while(1)
	{
		int n = (intptr_t)(arg);
		sem_wait(&x);
		count++;
		if(count==1)
		{
			sem_wait(&wsem);
		}
		sem_post(&x);
		//READUNIT START
		printf("Reader %d is reading the value %d.\n",n,value);
		//READUNIT END
		sem_wait(&x);
		count--;
		if(count==0)
		{
			sem_post(&wsem);
		}
		sem_post(&x);
		sleep(1);
	}
}
void *writer()
{
	while(1)
	{
		sem_wait(&wsem);
		//WRITEUNIT START
		value++;
		printf("Write is updating the value as %d.\n",value);
		//WRITEUNIT END
		sem_post(&wsem);
		sleep(5);
	}
}
void main()
{
	pthread_t r[3],w;
	sem_init(&x,0,1);
	sem_init(&wsem,0,1);
	for(int i=0;i<3;i++)
	{
		pthread_create(&r[i],NULL,(void *)reader,(void *)(intptr_t)i);
	}
	pthread_create(&w,NULL,(void *)writer,NULL);
	pthread_join(r[0],NULL);
	pthread_join(r[1],NULL);
	pthread_join(r[2],NULL);
	pthread_join(w,NULL);
	sem_destroy(&x);
	sem_destroy(&wsem);
}
