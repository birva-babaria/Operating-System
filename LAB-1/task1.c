#include<unistd.h>

int main()
{
	int fd,n;
	char buff[50];
//for one time output
//	n = read(0,buff,sizeof(buff));
//	write(1,buff,n); 

//for multiple time output
	int t=5;
	int i;
	while(i<t)
	{
		n = read(0,buff,sizeof(buff));
		write(1,buff,n); 
		i++;
	}
}
