//basic "cat" command using system calls.
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd,n;
	char buff[500];
	
	//if file name is provided in command line argument then read that particular file
	if(argc >= 2)
	{
		int i;
		for(i=1;i<argc;i++)
		{
			fd = open(argv[i], O_RDONLY);
			n = read(fd, buff, sizeof(buff));
			write(1, buff, n);
			printf("\n--------------------\n");
			close(fd);
		}
	}
	//if filename is not present then program works as a 'cat' command (press ctrl+c to end)
	else
	{
		while(1)
		{
			n = read(0, buff, sizeof(buff));
			write(1, buff, n);
		}
	}
}
