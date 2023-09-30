#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	char *pathname = "/bin/ls";
 	execl(pathname, "ls", (char *)NULL);
 	//printf does not work after execl
 	//because current process image is overwritten
 	printf("hello");
}

