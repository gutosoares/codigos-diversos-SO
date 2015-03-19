#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t filho;
	int status, i;

	filho = fork();

	if(filho == 0) // código do filho
	{
		printf("Sou o processo filho\n");
		for(i = 1; i <= 5; i++)
		{
			printf("%d\n", i);
			sleep(2);
		}

		_exit(0);
	}

	else // código do pai
	{
		wait(filho, // nome do processo que foi criado 
			&status, // verifica o status filho do processo criado
			0);
		printf("Sou o pai\n");
		printf("Agora eu posso executar o meu código\n");
	}
}
