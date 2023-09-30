#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
int main()
{
	int pid = fork();
	//pid=0 for child process and pid=child's pid for parent process.
	if(pid == 0)
	{
		printf("Hello from child (%d) of parent (%d)\n",getpid(),getppid());
	}
	else
	{
		//wait until child changes its state
		wait(NULL);
		printf("Hello from parent (%d) of child (%d)\n",getpid(),pid);
	}
	return 0;
}
