#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5

void *teste (void *threadid)
{
	for(;;)
	{
		printf("Sou a thread %i\n", *((int*) threadid));	
    }

	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t *threads = (pthread_t *) malloc (sizeof(pthread_t) * N);
   // ptread_t threads[N];

   for(int i = 0; i < N; i++)
   {
		int *t = ((int *) malloc (sizeof(int)));
		*t = i;
		pthread_create((threads + i), NULL, teste, (void *) t);
		//&treads[i];
		// threads[i] -> *(threads + 1);
   }

   pthread_exit(NULL);

}
