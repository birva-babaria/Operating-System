//child should read the string from terminal
//child should pass that string in the pipe
//parent process should read from pipe and print on terminal
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
void main()
{
	char buff[100];
	int pipefd[2];
	int status = pipe(pipefd);
	int pid = fork();
	if(status==-1 || pid==-1)
	{
		printf("ERROR OCCURED\n");
	}
	else if(pid == 0)
	{
		close(pipefd[0]);
		printf("Enter the message to send it to parent : ");
		scanf("%s",buff);
		write(pipefd[1], buff, sizeof(buff));
		printf("Child (%d) sending message to parent (%d)\n",getpid(),getppid());
		close(pipefd[1]);
	}
	else
	{
		close(pipefd[1]);
		read(pipefd[0], buff, 100);
		printf("Parent (%d) received \"%s\" from Child (%d)\n",getpid(),buff,pid);
		close(pipefd[0]);
	}
}

