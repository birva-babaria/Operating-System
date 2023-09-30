//Parent writes file name in pipe
//child reads file content
//Child should write contents in pipe , parent reads file contents and prints
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>
int main(int args, char *argv[])
{
 	if (args == 1)
 	{
 		printf("FILENAME NOT PROVIDED!\n");
 	}
 	else
 	{
 		int pipefd1[2], pipefd2[2];
 		if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1)
 		{
 			printf("ERROR IN CREATING PIPE\n");
 			exit(0);
 		}
 		else
 		{
 			int pid = fork();
 			if (pid == -1)
 			{
 				printf("ERROR IN CREATING PROCESS\n");
 				exit(0);
 			}
		 	if (pid)
		 	{
		 		char buff[1000];
		 		close(pipefd1[0]);
		 		close(pipefd2[1]);
		 		write(pipefd1[1], argv[1], strlen(argv[1]));
		 		printf("Parent (%d) have sent file name: %s to Child (%d)\n",getpid(),argv[1],pid);
		 		close(pipefd1[1]);
		 		wait(NULL);
		 		printf("Parent(%d) read from pipe\n", getpid());
		 		int n = read(pipefd2[0], buff, sizeof(buff));
		 		buff[n] = '\0';
		 		write(1, buff, n);
		 		close(pipefd2[0]);
		 	}
		 	else
		 	{
		 		wait(NULL);
		 		close(pipefd1[1]);
		 		close(pipefd2[0]);
		 		char buff[500];
		 		int n = read(pipefd1[0], buff, sizeof(buff));
		 		buff[n] = '\0';
		 		printf("Child (%d) received file name: %s from Parent (%d)\n",getpid(),buff,getppid());
		 		close(pipefd1[0]);
		 		int fd = open(buff, O_RDONLY);
		 		char buff1[1000];
		 		if (fd == -1)
		 		{
		 			printf("FILE NOT FOUND\n");
		 			exit(0);
		 		}
		 		int m = read(fd, buff1, sizeof(buff1));
		 		buff1[m] = '\0';
		 		printf("Child (%d) Write data in to pipe\n",getpid());
		 		write(pipefd2[1], buff1, m);
		 		close(pipefd2[1]);
		 	}
 		}
	}
return 0;
}
