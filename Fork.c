#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	
	// gera um processo filho
	pid = fork();
	
	// um erro aconteceu
	if(pid < 0)
	{
		printf("Fork failed!");
		return 1;
	}
	
	//cria o processo filho
	else if(pid == 0)
	{
		execlp("bin/ls", "ls", NULL);
	}
	
	// Processo pai
	else
	{
		wait(NULL);		// o pai esperará o filho ser concluido
		printf("Child Complete!\n");
	}
	
	return 0;
}
