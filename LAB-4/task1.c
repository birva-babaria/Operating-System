//display hello from thread function
#include<stdio.h>
#include<pthread.h>
void *hello()
{
	printf("Hello from thread!!\n");
}
void main()
{
	pthread_t thread;
	int status = pthread_create(&thread, NULL, hello, NULL);
	pthread_join(thread,NULL);
	printf("Hello from main!!\n");
}
