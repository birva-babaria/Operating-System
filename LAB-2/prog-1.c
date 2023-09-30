#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	char buff[500],*path;
	path = getcwd(buff,sizeof(buff));
	printf("Current working directory is: %s\n",path);
	return 0;
}
