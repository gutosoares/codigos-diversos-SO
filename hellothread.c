#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg);
void *thread2(void *arg);

int main(void)
{
	pthread_t tid1, tid2; // variavel do tipo thread
	printf("Hello world da thread princial!\n\n");
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	pthread_join(tid1, NULL);
	pthread_exit((void *)NULL);
}

void *thread1(void *arg)
{
	printf("Hello world da primeira thread criada pela thread principal!\n\n");
	pthread_exit((void *)NULL);
}

void *thread2(void *arg)
{
	printf("Hello world da segunda thread criada pela thread principal!\n\n");
	pthread_exit((void *)NULL);
}