#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/utsname.h>

/*[UTSLEN];

struct utsname
{
	char sysname[UTSLEN];
	char nodename[UTSLEN];
	char release[UTSLEN];
	char version[UTSLEN];
	char machine[UTSLEN];
	char idnumber[UTSLEN];
};

*/

void main()
{
	struct utsname info;

	// erro no retorna da função
	if(uname (&info) < 0)
	{
		perror("");
		exit(errno);
	}

	printf("Nome do Sistema    :  |%s|\n", info.sysname);
	printf("Nome do Node       :  |%s|\n", info.nodename);
	printf("Release do S.O     :  |%s|\n", info.release);
	printf("Versão do S.O      :  |%s|\n", info.version);
	printf("Tipo de Hardware   :  |%s|\n", info.machine);
	
	exit(0);
}