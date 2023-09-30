//pass multiple arguments to the threaded function using struct
#include<stdio.h>
#include<pthread.h>
struct mystruct{
	int a;
	int b;
};
void *add(void *arg)
{
	struct mystruct *strct = (struct mystruct *)arg;
	int sum = strct->a + strct->b;
	printf("a: %d and b: %d\n",strct->a,strct->b);
	printf("Sum: %d\n",sum);
}
void main()
{
	pthread_t thread;
	struct mystruct *str;
	str->a = 10;
	str->b = 20;
	int status = pthread_create(&thread, NULL, add, (void *)str);
	pthread_join(thread,NULL);
	printf("Hello from main!!\n");
}
