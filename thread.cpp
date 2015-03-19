// www.GeeksBR.com

#include <stdio.h>
#include <pthread.h>

void * start_timer(void * arg)
{
    int * mili = (int*)arg;

    printf("Comecou a thread! Aguarde %d milisegundos...\n", *(mili));
    Sleep(*(mili)); // faz o programa "dormir" por "x" milisegundos
    printf("Terminou a thread!\n");
    pthread_exit(0);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t my_thread; // declara��o da vari�vel do tipo pthread_t
    int mili = 10000; // declara��o dos milisegundos
    void *exit_status;

    // Logo abaixo a thread � criada, start_timer � a tarefa que vai ser executada
    if(pthread_create(&my_thread, NULL, start_timer, &mili))
    {
        printf("\nFalha ao criar thread!");
        return -1;
    }
    /* pthread_join espera at� a thread terminar, caso n�o queira esperar, � s�
       tirar a linha abaixo */
    pthread_join(my_thread, &exit_status);
    return 0;
}
