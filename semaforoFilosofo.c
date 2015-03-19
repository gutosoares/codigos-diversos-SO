#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t thread[5];


int main()
{




	for(int i = 0; i < 5; i++)
	{
		int *p = ((int *)malloc(sizeof(int)));
		*p = i;
		pthread_creat(&thread, NULL, criar, p);
	}

	pthread_exit(NULL);
	
}