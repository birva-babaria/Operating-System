#include<unistd.h>
#include <sys/types.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
int count = 0;
void displayLsR(char *path)
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
				displayLsR(path);
				count--;
				strcpy(path,temp);
			}
		}
		closedir(dir);
	}
}
void displayLs(char *path)
{
	DIR *dir;
	struct dirent *dptr;
	dir = opendir(path);
	if(dir != NULL)
		{
			while((dptr = readdir(dir)) != NULL)
			{
				if((strcmp(dptr->d_name,".") == 0) || (strcmp(dptr->d_name,"..") == 0))
				{
					continue;
				}
				else
				{
					printf("%s   ",dptr->d_name);	
				}
			}
			printf("\n");
			closedir(dir);
		}
		else
		{
			printf("Directory can not be opened.\n");
		}
}
int main(int argc, char *argv[])
{
	char buff[200];
	getcwd(buff,sizeof(buff));
	if(argc == 2 && strcmp(argv[1],"ls")==0)
	{
		displayLs(buff);
	}
	else if(argc == 3 && (strcmp(argv[1],"ls")==0 && strcmp(argv[2],"-R")==0))
	{
		displayLsR(buff);
	}
	else
	{
		printf("Invalid command.\n");
	}
	return 0;
}
