#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include<wait.h>
void main()
{
	char his[100][25];
 	int ptr = 0;
	while (1)
	{
 		char input[500];
 		printf("\nBirva $:");
 		scanf("%[^\n]%*c", input);
 		if (strlen(input) == 0)
 			continue;
 		strcpy(his[ptr++], input);
 		pid_t pid = fork();
 		if (pid == 0)
 		{
 			if (strcmp(input, "history") == 0)
 			{
 				for (int i = 0; i < ptr; i++)
 				{
 					printf("%s\n", his[i]);
 				}
 				continue;
 			}
 			else if (strcmp(input, "ls|sort") == 0)
 			{
 				int pipefd[2];
 				int status = pipe(pipefd);
 				if (status == -1)
 				{
 					printf("Error in creating pipe");
 					return;
 				}
 				pid_t pid;
 				pid = fork();
 				if (pid == -1)
 				{
 					printf("ERROR IN FORK");
 					return;
 				}
 				if (pid != 0)
 				{
 					wait(NULL);
 					close(pipefd[1]);
 					int status = dup2(pipefd[0], 0);
 					int s = execl("/bin/sort", "sort", (char *)NULL);
 					if (s == -1)
 					{
 						printf("ERROR");
 					}
 				}
 				if (pid == 0)
 				{
 					close(pipefd[0]);
 					int status = dup2(pipefd[1], 1);
 					int s = execl("/bin/ls", "ls", (char *)NULL);
 					if (s == -1)
 					{
 						printf("ERROR");
 					}
 				}
 			}
	 		else
	 		{
	 			char path[500] = "/bin/";
	 			int count = 0;
	 			for (int i = 0; i < strlen(input); i++)
	 			{
	 				char t = input[i];
	 				if (t == ' ')
	 					count++;
	 			}
	 			char *cmd[count + 2];
	 			cmd[0] = (char *)malloc(20);
	 			for (int i = 0, j = 0, k = 0; i < strlen(input); i++)
	 			{
	 				if (input[i] != ' ')
	 				{
	 					cmd[j][k] = input[i];
	 					k++;
	 				}
	 				else
	 				{
	 					cmd[j][k] = '\0';
	 					j++;
	 					k = 0;
	 					cmd[j] = (char *)malloc(20);
	 				}
	 			}
		 		cmd[count + 1] = NULL;
		 		strcat(path, cmd[0]);
		 		int s = execv(path, cmd);
		 		if (s == -1)
		 		{
		 			printf("-shell: %s: command not found", input);
		 		}
	 		}
 		}
 		else if (pid != 0)
 		{
 			wait(NULL);
 		}
 		else if (pid == -1)
 		{
 			printf("ERROR");
 		}
 	}
}
