#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// Variável que irá conter o Process ID retornado
	// pela função fork().
	int iPid;

	printf("Duplicando o processo...\n");
	iPid = fork();

	// Duplicando o processo e verificando
	// algum possível erro.
	if(iPid < 0)
	{
		printf("Erro na duplicação do processo!\n");
		return;
	}

	// Este código será executado apenas no pai.
	if(iPid != 0)	
	{
		printf("\nCódigo executado no processo pai!\n");
		printf("PAI - Processo pai. PID:|%d|\n", getpid());	// retorna o id do processo corrente, no caso o id do processo pai
		printf("PAI - Processo filho. PID:|%d|\n", iPid);
		
	}

	sleep(3);

	// Este código será executado apenas no filho.
	if(iPid == 0)
	{
		printf("\nCódigo executado no processo filho!\n");
		printf("FILHO - Processo pai. PID: |%d|\n", getppid());	// retorna o id do processo pai do processo corrente!
		printf("FILHO - Processo filho. PID: |%d|\n", getpid());	// retorna o id do provesso corrente, no caso o id do processo filho

		
	}

	return 0;
}
