//Safety algorithm
#include <stdio.h>
int check(int i, int resource, int need[][resource], int work[])
{
	int k = 0;
	for (int j = 0; j < resource; j++)
	{
		if (need[i][j] <= work[j])
		{
			++k;
		}
	}
	return k;
}
void SafetyAlgo(int process, int resource, int allocation[][resource], int max[][resource], int available[])
{
	int finish[process], work[resource], order[process], need[process][resource];
	for (int i = 0; i < process; i++)
	{
	finish[i] = 0;
	}
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resource; j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	for (int i = 0; i < resource; i++)
	{
		work[i] = available[i];
	}
	int k = 0;
	for (int p = 0; p < 5; p++)
	{
		for (int i = 0; i < process; i++)
		{
			if (finish[i] == 0 && check(i, resource, need, work) == resource)
			{
				for (int j = 0; j < resource; j++)
				{
					work[j] = work[j] + allocation[i][j];
				}
				finish[i] = 1;
				order[k++] = i;
			}
		}
	}
	int p = 0;
	for (int i = 0; i < process; i++)
	{
		if (finish[i] == 1)
		{
			++p;
	}
	}
	printf("Allocation:\n");
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resource; j++)
		{
			printf("%d ", allocation[i][j]);
		}
		printf("\n");
	}
	printf("Need:\n");
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resource; j++)
		{
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	printf("Available:\n");
	for (int j = 0; j < resource; j++)
	{
		printf("%d ", available[j]);
	}
	printf("\n");
	if (k == process)
	{
		printf("Safe Sequence:\n");
		for (int i = 0; i < process; i++)
		{
			printf("P%d ", order[i]);
		}
		printf("\n");
	}
	if (p == process)
	{
		printf("System in safe state\n");
	}
	else
	{
		printf("System not in safe state\n");
	}
}
int main()
{
	int process, resource;
	printf("Enter Number of Process:\n");
	scanf("%d", &process);
	printf("Enter Number of Resource:\n");
	scanf("%d", &resource);
	int allocation[process][resource],
	max[process][resource], available[resource];
	printf("Enter Allocation :\n");
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resource; j++)
		{
			scanf("%d", &allocation[i][j]);
		}
	}
	printf("Enter Max :\n");
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resource; j++)
		{
			scanf("%d", &max[i][j]);
		}
	}
	printf("Enter Available:\n");
	for (int j = 0; j < resource; j++)
	{
		scanf("%d", &available[j]);
	}
	SafetyAlgo(process, resource, allocation, max, available);
	return 0;
}
