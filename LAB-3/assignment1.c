#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//if child process is running currently then print the following statement and terminate the process
		if(fork() == 0)
		{
			printf("Hello from child (%d) of parent (%d)\n",getpid(),getppid());
			exit(0);
		}
	}
	return 0;
}
