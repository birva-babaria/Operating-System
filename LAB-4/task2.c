//create two threads and each thread should invoke different function
#include<stdio.h>
#include<pthread.h>
void *hello1()
{
	printf("Hello from thread one!!\n");
}
void *hello2()
{
	printf("Hello from thread two!!\n");
}
void main()
{
	pthread_t thread;
	int status1 = pthread_create(&thread, NULL, hello1, NULL);
	int status2 = pthread_create(&thread, NULL, hello2, NULL);
	pthread_join(thread,NULL);
	printf("Hello from main!!\n");
}
