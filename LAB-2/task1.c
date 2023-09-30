//task to print the path of the current directory(pwd in linux)

#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	int fd,n;
	char buff[500],*path;
	path = getcwd(buff,sizeof(buff));
	printf("%s %s\n",buff,path);
	//or
//	getcwd(buff,sizeof(buff));
//	printf("%s\n",buff);
}
