//pass a character string to the threaded function
#include<stdio.h>
#include<pthread.h>
void *func(void *arg)
{
	char *str = (char *)arg;
	printf("Argument is: %s\n",str);
}
void main()
{
	pthread_t thread;
	int status = pthread_create(&thread, NULL, func, (void *)"hello world");
	pthread_join(thread,NULL);
	printf("Back to Main!!\n");
}
