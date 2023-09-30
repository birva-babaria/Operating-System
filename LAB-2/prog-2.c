#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dir;
	char buff[500];
	scanf("%s",buff);
	if(strcmp(buff,"ls") == 0)
	{
		d = opendir(".");
		if(d != NULL)
		{
			while((dir = readdir(d)) != NULL)
			{
				if((strcmp(dir->d_name,".") == 0) || (strcmp(dir->d_name,"..") == 0))
				{
					continue;
				}
				else
				{
					printf("%s   ",dir->d_name);	
				}
			}
			printf("\n");
			closedir(d);
		}
		else
		{
			printf("Directory can not be opened.\n");
		}
	}
	else
	{
		printf("Command \"%s\" not found.\n",buff);
	}
	return 0;
}
