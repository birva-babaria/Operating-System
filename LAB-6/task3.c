//parent should read the string from terminal
//parent should pass that string in the pipe
//child process should read from pipe and print on terminal
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
		close(pipefd[1]);
		read(pipefd[0], buff, sizeof(buff));
		printf("Child (%d) received \"%s\" from Parent (%d)\n",getpid(),buff,getppid());
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		printf("Enter the message to send it to child : ");
		scanf("%s",buff);
		write(pipefd[1], buff, sizeof(buff));
		printf("Parent (%d) sending message to Child (%d)\n",getpid(),pid);
		close(pipefd[1]);
	}
}

