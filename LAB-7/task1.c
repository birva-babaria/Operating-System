#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	char buff[100] = "Hello to terminal!!\n";
	int fd = open("test.txt", O_WRONLY);
	int n = read(fd, buff, sizeof(buff));
	write(1,buff,sizeof(buff));
	char buff1[100] = "Hello to file!!\n";
	dup2(fd,1);
	write(1,buff1,sizeof(buff1));
}

