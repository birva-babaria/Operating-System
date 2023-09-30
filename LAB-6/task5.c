//Parent process should read file name
//using command line arguments
//Parent should pass file name through pipe
//Child process should read file name, open the file, print the contents
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
void main(int argc, char *argv[])
{
	if (argc == 1)
	{
 		printf("FILENAME NOT PROVIDED!\n");
 		return;
 	}
 	int pipefd[2];
 	int status = pipe(pipefd);
 	if (status == -1)
 	{		
 		printf("ERROR IN CREATING PIPE\n");
 		return;
 	}
 	pid_t pid = fork();
 	if (pid == -1)
 	{
 		printf("ERROR IN CREATING PROCESS\n");
 	}
 	else if (pid)
 	{
 		close(pipefd[0]);
 		char buff[1024];
 		write(pipefd[1], argv[1], strlen(argv[1]));
 	}
 	else
 	{
 		close(pipefd[1]);
 		char buff[500];
 		int n = read(pipefd[0], buff, sizeof(buff));
 		buff[n] = '\0';
 		char buff1[1000];
 		int fd = open(buff, O_RDONLY);
 		n = read(fd, buff1, sizeof(buff1));
 		buff1[n] = '\0';
 		write(1, buff1, n);
 	}
}
