//Modificado do exemplo 14.1 do livro:
//Gnu/Linux Application Programming
//M TIM JONES

#include <stdio.h>
#include <unistd.h>

int main()
{
  int myPid;
  int myParentPid;
  int myGid;
  int  myUid;

  myPid = getpid(); 		//Retorna o PID
  myParentPid = getppid();	// Retorna o PID do Pai
  myGid = getgid();		// Retorna o Gid do Grupo do Processo
  myUid = getuid();		// Retorna o Uid do usuário que criou o processo

  printf( "Meu ID de processo é: %d\n", myPid );

  printf( "O ID de processo do meu pai é: %d\n", myParentPid );

  printf( "Meu ID de grupo é: %d\n", myGid );

  printf( "O uid  do usuario que me chamou é: %d\n", myUid );

  return 0;
}


