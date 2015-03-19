#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUMCONS 2
#define NUMPROD 2
#define BUFFERSIZE 1000

pthread_t cons[NUMCONS];
pthread_t prod[NUMPROD];
pthread_mutex_t bufferMutex;
int buffer[BUFFERSIZE];
int currentidx;
sem_t bufferFull, bufferEmpty;

// Duas funções
void *consumidor(void *arg);
void *produtor(void *arg);

int main(int arg, char **argv)
{
	srand48(time());
	currentidx = 0;
	pthread_mutex_init(&bufferMutex, NULL);

	sem_init(&bufferFull, 0, BUFFERSIZE);
	sem_init(&bufferEmpty, 0, 0);

	for(int i = 0; i < NUMCONS; i++)
		pthread_create(&(cons[i]), NULL, consumidor, NULL);

	for(int i = 0; i < NUMPROD; i++)
		pthread_create(&(prod[i]), NULL, produtor, NULL);

	for(int i = 0; i < NUMCONS; i++)
		pthread_join(cons[i], NULL);

	for(int i = 0; i < NUMPROD; i++)
		pthread_join(prod[i], NULL);
}

// Função produtor
void *produtor(void *arg)
{
	int n;

	while(1)
	{
		n = (int)(drand48() *1000.0);
		// Inicio da area critica
		sem_wait(&bufferFull);		
		pthread_mutex_lock(&bufferMutex);
		buffer[currentidx++] = n;		
		pthread_mutex_unlock(&bufferMutex);
		sem_post(&bufferEmpty);
		// Fim da area critica
		printf("Produzindo numero %d\n", n);
		sleep((int)(drand48() * 4.0));
	}
}

// Função consumidor
void *consumidor(void *arg)
{
	int n;

	while(1)
	{
		sem_wait(&bufferEmpty);
		pthread_mutex_lock(&bufferMutex);
		n = buffer[--currentidx];		
		pthread_mutex_unlock(&bufferMutex);
		sem_post(&bufferFull);
		// Fim da area critica
		printf("Consumindo numero %d\n", n);
		sleep((int)(drand48() * 4.0));
	}
}
