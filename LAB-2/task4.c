////task to check if the directory can be opened after providing the path and print the content of the directory
//#include<unistd.h>
//#include<stdio.h>
//#include<dirent.h>
//int main(int argc, char *argv[])
//{
//	DIR *d;
//	struct dirent *dir;
//	d = opendir("/mnt/c/Users/Admin/Documents/OS");
//	if(d)
//	{
//		while((dir = readdir(d)) != NULL)
//		{
//			printf("%s\n",dir->d_name);
//		}
//		closedir(d);
//	}
//	
//}

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

void printDir(char *path)
{
    DIR *dir;
    char temp[100];
    struct dirent *ptr;
    dir = opendir(path);
    strcpy(temp, path);
    if (dir != NULL)
    {
        while ((ptr = readdir(dir)) != NULL)
        {
            if ((ptr->d_name)[0] != '.' && ((ptr->d_type) == 4 || (ptr->d_type) == 8))
            {
                printf("%s\t", ptr->d_name);
            }
            if ((ptr->d_name)[0] != '.' && (ptr->d_type) == 4)
            {
                strcat(path, "/");
                strcat(path, ptr->d_name);
                strcat(path, "\0");
                printDir(path);
                strcpy(path, temp);
                printf("\n");
            }
        }
    }
}

void main()
{
    char buff[254];
    printf("Enter path:");
    scanf("%s", buff);
    printDir(buff);
}
