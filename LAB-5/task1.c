#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
int isNum(char a[])
{
	for(int i=0; a[i]!=0; i++)
	{
		if(isdigit(a[i]) == 0)
		{
			return 0;
		}
	}
	return 1;
}
void ps(char *dirname)
{
	DIR *dirp = opendir(dirname);
	struct dirent **dir;
	struct dirent *d;
	dir = (struct dirent **)malloc(10000 * sizeof(struct dirent *));
	if(dirp == NULL)
	{
		printf("Can't access '%s': No such file or Dir OR '%s' is a file",dirname,dirname);
		return;
	}
	int i = 0;
	char processinfo[100];
	while(d = readdir(dirp))
	{
		if(d->d_type == 4 && isNum(d->d_name))
		{
			dir[i] = d;
			i++;
		}
	}
	char x[100] = "PID";
	char y[100] = "P_NAME";
	printf("%5s %15s\n",x,y);
	for(int j=0;j<i;j++)
	{
		char stat_file[FILENAME_MAX];
		strcat(stat_file, dirname);
		strcat(stat_file, "/");
		strcat(stat_file, dir[j]->d_name);
		strcat(stat_file, "/stat");
		FILE *fptr;
		fptr = fopen(stat_file, "r");
		if(fptr == NULL)
		{
			printf("Unable to open file %s\n",stat_file);
		}
		fscanf(fptr, "%*s %s ",processinfo);
		printf("%5s %15s\n",dir[j]->d_name,processinfo);
		strcpy(stat_file, "");
	}
	closedir(dirp);
	free(d);
	free(dir);
}
int main()
{
	ps("/proc");
	return 0;
}
