#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;
	int i;

	pid = fork();

	if(pid == 0)	// código do filho
	{
		printf("Eu sou o processo filho!\n");
		for(i = 1; i <= 5; i++)
		{
			printf("%d\n", i);
			sleep(2);
		}
			
		_exit(0);	// identificar a saida imediata de um processo filho
	}

	if(pid != 0)	// código do pai
	{
		wait(pid, &status, 0);
		printf("Sou o processo pai!\n");
		printf("Agora eu posso executar o meu código!\n");
	}

	return 0;
}