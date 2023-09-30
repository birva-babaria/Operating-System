//construct simple calculator
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
	printf("Addition: %d\n",sum);
}
void *sub(void *arg)
{
	struct mystruct *strct = (struct mystruct *)arg;
	int sub = strct->a - strct->b;
	printf("Subtraction: %d\n",sub);
}
void *mul(void *arg)
{
	struct mystruct *strct = (struct mystruct *)arg;
	int mul = strct->a * strct->b;
	printf("Multiplication: %d\n",mul);
}
void *div(void *arg)
{
	struct mystruct *strct = (struct mystruct *)arg;
	int div = strct->a / strct->b;
	printf("Division: %d\n",div);
}
void main()
{
	pthread_t thread;
	struct mystruct *str;
	int a,b;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	str->a = a;
	str->b = b;
	printf("----CALCULATE----\n");
	int status1 = pthread_create(&thread, NULL, add, (void *)str);
	int status2 = pthread_create(&thread, NULL, sub, (void *)str);
	int status3 = pthread_create(&thread, NULL, mul, (void *)str);
	int status4 = pthread_create(&thread, NULL, div, (void *)str);
	pthread_join(thread,NULL);
	printf("Back to Main!!\n");
}
