#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
void main()
{
	fork();
	fork();
	fork();
	printf("hello\n");
}
