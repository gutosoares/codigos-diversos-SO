#include <stdio.h>
#include <stdlib.h>

int main()
{
	uid_t uidReal;
	uid_t uidEfet;

	uidReal = getuid();
	uidEfet = geteuid();

	printf("Valores retornados:\n");
	printf("User ID real     : |%d|\n", uidReal);
	printf("User ID efetivo  : |%d|\n", uidEfet);

	printf("Digite 'id' para obter o UID do processo shell");
	printf(" que chamou este programa.\n");

	return 0;
}