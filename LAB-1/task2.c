#include<unistd.h>

int main()
{
	int fd,n;
	char buff[50];
	
	fd = open("test.txt",O_RDONLY);
	n = read(fd,buff,sizeof(buff));
	write(1,buff,n);
}
