//basic "cp" command using system calls.
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd1,fd2,n;
	char buff[500];
	
	//if two file names are provided
	if(argc == 3)
	{
		//open and read from file 1
		fd1 = open(argv[1], O_RDONLY);
		n = read(fd1, buff, sizeof(buff));
		
		//open and write in file 2
		fd2 = open(argv[2], O_WRONLY | O_CREAT, 666);
		write(fd2, buff, n);
		
		close(fd1);
		close(fd2);
	}
	else
	{
		printf("INVALID NUMBER OF ARGUMENTS ENTERED!!\n");
	}
}
