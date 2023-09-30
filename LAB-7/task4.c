#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	int pipefd[2];
	int status = pipe(pipefd);
	if(status == -1)
	{
		printf("ERROR CREATING PIPE\n");
	}
	int pid = fork();
	if(pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		char *binaryPath = "/bin/sort";
 		execl(binaryPath, "sort", (char *)NULL);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		char *binaryPath = "/bin/ls";
 		execl(binaryPath, "ls", (char *)NULL);
	}
}
