#include <pthread.h>
#include <stdio.h>

int sum;	// estes dados são compratilhados pelos threads
void *runner(void *param);	// função que será executada pelo thread filho

int main(int argc, char *argv[])
{
	pthread_t tid;	// id do thread
	pthread_attr_t attr;	// conjunto de atributos do thread

	/*if(argc != 2)
	{
		fprintf(stderr, "usage: a.out <integer value>\n");
		return -1;
	}

	if(atoi(argv[1]) < 0)
	{
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return -1;
	}*/

	pthread_attr_init(&attr);	// obtem os atributos default
	pthread_create(&tid, &attr, runner, NULL);	// cria o thread
	pthread_join(tid, NULL);	// espera o thread ser encerrado

	printf("Sum = %d\n", sum);

	return 0;
}

// o thread assumirá o controle nessa função
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i <= upper; i++)
		sum += i;

	pthread_exit(0);
}
