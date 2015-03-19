#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 20
#define TRUE 1

int qtd = 0;

pthread_cond_t empty, full;
pthread_mutex_t mutex;

void *producer()
{
	printf("Produtor!\n");

	while(TRUE)
	{

		pthread_mutex_lock(&mutex);

		if(qtd == MAX)
		{
			printf("Maximo atingido!\n");
			// Maximo atingido, o produtor dorme
			pthread_cond_wait(&full, &mutex);
		}

		qtd++;
		printf("Produtor com %d itens\n", qtd);

		// Produtor 
		if(qtd == 1)
			// Acorda o consumidor
			pthread_cond_signal(&empty);

		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}


void *consumer()
{
	printf("Consumidor\n");

	while(TRUE)
	{
		pthread_mutex_lock(&mutex);

		if(qtd == 0)
		{
			printf("Minimo atingido!\n");
			// Minimo atingido, o consumidor dorme
			pthread_cond_wait(&empty, &mutex);
		}

		qtd--;
		printf("Consumidor com %d itens\n", qtd);

		if(qtd == MAX -1)
			// Acorda o produtor
			pthread_cond_signal(&full);
	
		pthread_mutex_unlock(&mutex);
		sleep(3);
	}
}

int main()
{
	//int p,c;

	/*printf("Entre com a qtd de Produtor: ");
	scanf("%d",&p);

	printf("Entre com a qtd de Consumidor: ");
	scanf("%d",&c);*/

	// Vetor de produtores
	pthread_t producers[1];

	// Vetor de consumidores
	pthread_t consumers[1];

	// Criando as threads, consumidor
	//for(int i = 0; i < c; i++)
	//{
		pthread_create(&consumers[1], NULL, consumer, NULL);
	//}

	// Criando as threads, produtor
	//for(int i = 0; i < p; i++)
	//{
		pthread_create(&producers[1], NULL, producer, NULL);
	//}

	// Todas as threads juntas
	/*for(int i = 0; i < c; i++)
	{
		pthread_join(producers[i], NULL);
		pthread_join(consumers[i], NULL);
	}*/

	pthread_exit(NULL);
}