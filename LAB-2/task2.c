//task to check if the directory can be opened after providing the path
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	int fd,n;
	char buff[500];
	getcwd(buff,sizeof(buff));
	printf("%s",buff);
	DIR *dir = opendir(buff);
	if(dir != NULL)
	{
		printf("opened");
	}
}
