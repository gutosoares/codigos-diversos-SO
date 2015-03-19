#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
fd[0] -> leitura
fd[1] -> escrita

O pai tem que ler um numero enviado pelos
3 processos filhos.

*/

// Variaveis globais
pid_t pidProcesso1 = -1, pidProcesso2 = -1, pidProcesso3 = -1;
int fd1[2];
int fd2[2];
int fd3[2];

// função que ira tratar o sinal
void tratador(int sinal)
{
	char buffer;

	if(pidProcesso1 == 0)
	{
		printf("Sinal chamado, filho 1\n");
		buffer = 21;
		close(fd1[0]);	// fechando a leitura
		write(fd1[1], &buffer, 1);	// escrevendo 21 no buffer
	}

	if(pidProcesso2 == 0)
	{
		printf("Sinal chamado, filho 2\n");
		buffer = 45;
		close(fd2[0]);	// fechando a leitura
		write(fd2[1], &buffer, 1);	// escrevendo 45 no buffer
	}

	if(pidProcesso3 == 0)
	{
		printf("Sinal chamado, filho 3\n");
		buffer = 31;
		close(fd3[0]);	// fechando a leitura
		write(fd3[1], &buffer, 1);	// escrevendo 31 no buffer
	}

}

int main()
{
	char buffer;

	pipe(fd1);
	pipe(fd2);
	pipe(fd3);

	pidProcesso1 = fork();	// criando o primeiro processo filho

	if(pidProcesso1 != 0)	// apenas o pai entra neste if
	{
		pidProcesso2 = fork(); 	// criando o segundo processo filho

		if(pidProcesso2 != 0)	// apenas o pai entra neste if
		{
			pidProcesso3 = fork();	// criando o terceiro filho

			if(pidProcesso3 != 0)	// apenas o pai ira executar estes codigos
			{
				printf("Sou o processo pai %d\n", getpid());
				sleep(5);
				kill(pidProcesso1, SIGUSR1);	// manda o sinal para o filho 1
				kill(pidProcesso2, SIGUSR1);	// mando o sinal para o filho 2
				kill(pidProcesso3, SIGUSR1);	// mando o sinal para o filho 3

				close(fd1[1]);	// fecha a escrita
				close(fd2[1]);	// fecha a escrita
				close(fd3[1]);	// fecha a escrita

				read(fd1[0], &buffer, 1);
				read(fd2[0], &buffer, 1);
				read(fd3[0], &buffer, 1);
				
				printf("Pai recebeu %i\n", buffer);
				printf("Pai recebeu %i\n", buffer);
				printf("Pai recebeu %i\n", buffer);
			}
		}
	}

	if(pidProcesso1 == 0 || pidProcesso2 == 0 || pidProcesso3 == 0)
	{
		printf("Sou o processo filho %d\n", getpid());
		signal(SIGUSR1, tratador);
	}

	sleep(5);
	return 0;
}