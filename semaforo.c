#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define QUANT 30

int global_counter = 0;
pthread_mutex_t mutex;

void *imprimir (void *threadid)
{	

	pthread_mutex_lock(&mutex);
	int count = global_counter;
	pthread_yield();	
	count++;
	global_counter = count;	
	printf("Contador = %d\n", global_counter);
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t *threads = (pthread_t *) malloc (sizeof(pthread_t) * QUANT);
   // ptread_t threads[N];

   for(int i = 0; i < QUANT; i++)
   {
		int *t = ((int *) malloc (sizeof(int)));
		*t = i;
		pthread_create((threads + i), NULL, imprimir, (void *) t);
		//&treads[i];
		// threads[i] -> *(threads + 1);
   }

   pthread_exit(NULL);

}
