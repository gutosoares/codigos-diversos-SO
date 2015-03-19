#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define QUANT 20

int counter = 0;
pthread_mutex_t mutex;

void *thread_main_function(void *param)
{
// Inicio area critica
	pthread_mutex_lock(&mutex);
	int m_counter = counter;
	pthread_yield();
	m_counter++;
	counter = m_counter;
	printf("%d\n", counter);
	pthread_mutex_unlock(&mutex);
// Fim area critica
	return NULL;
} 

int main()
{
	pthread_t ts[QUANT];
	
	for(int i = 0; i < QUANT; i++)
	{
		pthread_create(&ts[i], NULL, thread_main_function, NULL);
	}
	
	for(int i = 0; i < QUANT; i++)
	{
		pthread_join(ts[i], NULL);
	}
	
	return 0;
}
