#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Função fork() não recebe nenhum parâmetro */

int main()
{
	pid_t pid;

	// gera um processo filho
	pid = fork();

	if(pid < 0)	// um erro ocorreu
	{
		fprintf(stderr, "Fork failed\n");
		return 1;
	}

	else if(pid == 0)  // processo filho
	{
		// lista todos os arquivos do diretorio corrente
		printf("Arquivos do diretorio corrente:\n");
		execlp("/bin/ls", "ls", NULL);
		// processo filho é encerrado
	}

	else  // processo pai
	{
		// processo pai espera o encerramento do processo filho
		wait(NULL);
		printf("Child complete\n");
	}

	return 0;
}
