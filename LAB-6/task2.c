//create two pipe and print descriptor values of both.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	int pipefd1[2];
	int pipefd2[2];
	int status1 = pipe(pipefd1);
	int status2 = pipe(pipefd2);
	if(status1 != -1)
	{
		printf("For pipe 1:\n");
		printf("pipefd1[0] = %d\n",pipefd1[0]);
		printf("pipefd1[1] = %d\n",pipefd1[1]);
		close(pipefd1[0]);
		close(pipefd1[1]);
	}
	else
	{
		printf("ERROR OCCURED\n");
	}
	if(status2 != -1)
	{
		printf("For pipe 2:\n");
		printf("pipefd2[0] = %d\n",pipefd2[0]);
		printf("pipefd2[1] = %d\n",pipefd2[1]);
		close(pipefd2[0]);
		close(pipefd2[1]);
	}
	else
	{
		printf("ERROR OCCURED\n");
	}
}

