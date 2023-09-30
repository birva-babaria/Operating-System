#include<unistd.h>
#include <sys/types.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
int count = 0;
void printFiles(char *path)
{
	DIR *dir;
	struct dirent *dptr;
	char temp[100];
	dir = opendir(path);
	strcpy(temp,path);
	if(dir != NULL)
	{
		while ((dptr = readdir(dir)) != NULL)
		{
			if((dptr->d_name)[0] != '.' && ((dptr->d_type) == 4 || (dptr->d_type) == 8))
			{
				int i=0;
				while(i<count)
				{
					printf("--");
					i++;
				}
				printf("%s\n",dptr->d_name);
			}
			if((dptr->d_name)[0] != '.' && (dptr->d_type) == 4)
			{
				strcat(path,"/");
				strcat(path,dptr->d_name);
                strcat(path,"\0");
                count++;
				printFiles(path);
				count--;
				strcpy(path,temp);
			}
		}
		closedir(dir);
	}
}
int main(int argc, char *argv[])
{
	char buff[200];
	getcwd(buff,sizeof(buff));
	if(argc == 1)
	{
		printFiles(buff);
	}
	else if(argc == 2)
	{
		printFiles(argv[1]);
	}
	else
	{
		printf("Incorrect arguments provided.");
	}
	return 0;
}
