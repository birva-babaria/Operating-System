//task to check if the directory can be opened after providing the path and print the content of the directory
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if(d)
	{
		while((dir = readdir(d)) != NULL)
		{
			printf("%s\n",dir->d_name);
		}
		closedir(d);
	}
	
}
