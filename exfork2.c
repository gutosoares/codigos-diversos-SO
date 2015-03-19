#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid, pid1;

	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed\n");
		return 1;
	}

	else if(pid == 0)
	{
		pid = getpid();
		printf("Child: pid = %d\n", pid);
		printf("Child: pid1 = %d\n", pid1);

	}
}