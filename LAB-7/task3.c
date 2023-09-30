#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	int pid = fork();
	if(pid == 0)
	{
		printf("Child executing pwd command!!\n");
		char buff[500],*path;
		path = getcwd(buff,sizeof(buff));
		printf("PWD: %s\n\n",path);
	}
	else
	{
		wait(NULL);
		printf("Parent executing ls command!!\n");
		char *binaryPath = "/bin/ls";
 		execl(binaryPath, "ls", (char *)NULL);
	}
}

