//multiply two matrices (4 X 4)
#include<stdio.h>
#include<pthread.h>
int a[4][4] = {{5,7,9,10},
			   {2,3,3,8},
			   {8,10,2,3},
			   {3,3,4,8}
			  };
int b[4][4] = {{3,10,12,18},
			   {12,1,4,9},
			   {9,10,12,2},
			   {3,12,4,10}
			  };
void *mul(void *arg)
{
	int i = *(int *)arg;
	int arr[4] = {0};
	for(int j=0;j<4;j++)
	{
		for(int k=0;k<4;k++)
		{
			arr[j] += (a[i][k] * b[k][j]);
		}
	}
	for(int j=0;j<4;j++)
	{
		printf(" %3d ",arr[j]);
	}
	printf("\n");
}
void main()
{
	pthread_t thread;
	int a=0,b=1,c=2,d=3;
	printf("----MATRIX MULTIPLICATION (4 X 4)----\n");
	int status1 = pthread_create(&thread, NULL, mul, (void *)&a);
	pthread_join(thread,NULL);
	int status2 = pthread_create(&thread, NULL, mul, (void *)&b);
	pthread_join(thread,NULL);
	int status3 = pthread_create(&thread, NULL, mul, (void *)&c);
	pthread_join(thread,NULL);
	int status4 = pthread_create(&thread, NULL, mul, (void *)&d);
	pthread_join(thread,NULL);
	printf("\nBack to main!!\n");
}
