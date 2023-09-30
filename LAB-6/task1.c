//create a pipe and print its descriptor values of that pipe.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//0,1,2 are reserved for stdin,stdout,stderr respectively.
void main()
{
	int pipefd[2];
	int status = pipe(pipefd);
	if(status != -1)
	{
		printf("pipefd[0] = %d\n",pipefd[0]);
		printf("pipefd[1] = %d\n",pipefd[1]);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	else
	{
		printf("ERROR OCCURED\n");
	}
}

