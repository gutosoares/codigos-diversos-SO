#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	pid = fork();

	if(pid == 0)
	{
		printf("Processo filho: %d\n", getpid());
		printf("Processo pai: %d\n", getppid());
	}

	if(pid != 0)
	{
		printf("Processo pai: %d\n", getpid());
		printf("Processo filho: %d\n", pid);
	}

	return 0;
}
