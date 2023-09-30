#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
int main()
{
	if(fork() == 0)
	{
		printf("hello from child\n");
	}
	else
	{
		printf("hello from parent\n");
	}
	return 0;
}
