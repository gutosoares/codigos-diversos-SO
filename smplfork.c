//Modificado do exemplo 14.2 do livro:
//Gnu/Linux Application Programming
//M TIM JONES

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int ret;
    int status, i;
    int role = -1;
    int loops = 6;

    ret = fork(); //No Pai ret>0 e no filho ret=0
	   			//Cria o outro processo apartir daqui
			    //que executará as instruções seguintes

    if (ret > 0) 
    {
	   //O pai entra aqui
        printf("Pai: o meu pid eh %d\n", getpid());

        for (i = 0 ; i < loops ; i++) 
        {
            printf("Pai: contando %d\n", i);
            sleep(2); //aguarda 1s
        }

        ret = wait(&status);
        role = 0;
    } 

	//O filho entra aqui 
	if (ret == 0) 
    {
        printf("Filho: o meu pid %d\n", getpid());

    	for (i = 0 ; i < loops ; i++) 
        {
      	    printf("Filho: contando %d\n", i);
      	    sleep(2); //aguarda 1s
    	}

    	role = 1;

    } 

    if (role == 0)
	   printf("Pai saindo\n");
  
    else
	printf("Filho saindo\n");

  return 0;

}