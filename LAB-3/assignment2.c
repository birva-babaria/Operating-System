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
		int pid = fork();
		if(pid == 0)
		{
			printf("Hello from child (%d) of parent (%d)\n",getpid(),getppid());
		}
		else
		{
			wait(NULL);
			exit(0);
		}
	}
	return 0;
}
