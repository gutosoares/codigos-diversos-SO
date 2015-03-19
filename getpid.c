#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pidProcesso;
	pid_t pidPai;

	//pidProcesso = getpid();
	//pidPai = getppid();

	printf("Valores retornados:\n");
	printf("Process ID         : |%d|\n", getpid());
	printf("Process ID Parent  : |%d|\n", getppid());

	printf("Digite 'echo $$' para obter o PID do processo shell");
	printf(" que chamou o este programa.\n");

	return 0;

}
