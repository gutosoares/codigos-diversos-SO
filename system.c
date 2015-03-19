#include <stdio.h>
#include <stdlib.h>

int main()
{
	int status;

	printf("Relação de arquivos do diretorio '/home/augusto/Dropbox/Programacao/Codigos_SO'\n");
	status = system("ls /home/augusto/Dropbox/Programacao/Codigos_SO");

	if(status < 0)
	{
		printf("Erro!\n");
		return;
	}

	printf("Comando terminou com status |%d|\n", status);

	return 0;
}