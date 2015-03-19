#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int value = 5;

int main()
{
	pid_t pid;

	printf("Vão ser escritos dois valores na tela...\n");
	
	pid = fork();	
	
	printf("%d\n", pid);	// vai ser escrito dois valores na tela

	if(pid == 0)
	{
		value += 15;	// variavel local, visivel apenas dentro do if do processo filho
		return 0;
	}
	
	else if(pid > 0)
	{
		wait(NULL);
		printf("Parent: value = %d\n", value);
		return 0;
	}
}
