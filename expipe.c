#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0       // valor 0 é so para leitura
#define WRITE_END 1     // valor 1 é so para escrita

int main()
{
        char write_msg[BUFFER_SIZE] = "Greetings";      // vetor de escrita
        char read_msg[BUFFER_SIZE];     // vetor de leitura
        int fd[2];
        pid_t pid;

        /* cria o pipe */
        if (pipe(fd) == -1)
        {
                fprintf(stderr, "Pipe failed!");
                return 1;
        }

        /* gera um processo filho */
        pid = fork();

        /* um erro aconteceu */
        if(pid < 0)
        {
                fprintf(stderr, "Fork failed!");
                return 1;
        }

        // processo pai
        if(pid > 0)
        {
                close(fd[READ_END]);    // fecha a extrmidade não usada do pipe
                write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);	// grava a mensagem no pipe
                close(fd[WRITE_END]);	// fecha a extrmidade de gravação do pipe
        }
        
        // processo filho 
        if(pid == 0)
        {
        	close(fd[WRITE_END]);	// fecha a extrmidade não usada do pipe
        	read(fd[READ_END], read_msg, BUFFER_SIZE);	// lê o pipe
        	printf("Mensagem do pai: %s\n", read_msg);
        	close(fd[READ_END]);	// fecha a extrmidade de gravação do pipe
        }
        
        return 0;
}
                
                
                
                
                
                
