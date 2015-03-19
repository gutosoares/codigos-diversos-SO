#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define N 20
#define TRUE 1

int count = 0;

pthread_cond_t empty;
pthread_cond_t full;
pthread_mutex_t mutex;

void *Inserir()
{
  while(TRUE){
    pthread_mutex_lock(&mutex);//bloqueio da sessão critica
    if(count == N){
        printf("MAXIMO ATINGIDO\n");
        pthread_cond_wait(&full, &mutex);  // tamanho maximo atingido, o produtor dormi e o consumidor acorda
        //insert_item(item);
    }

    count = count+1;
    printf("produtor com %d itens\n", count);
    
    if(count == 1)
    {
      pthread_cond_signal(&empty);//,&mutex);// um novo item foi produzido, o consumidor é acordado
    }
    pthread_mutex_unlock(&mutex);//desbloqueio da sessão critica
    sleep(3);
  }   
 }

void *Remover()
{
    while(TRUE){
       pthread_mutex_lock(&mutex);//bloqueio da sessão critica    
       if(count == 0)
       {
         printf("VAZIO\n");
         pthread_cond_wait(&empty, &mutex); //o consumidor dorme, pois não há o que consumir, o produtor é acordado
         //insert_item(item);
       }
    
      count = count-1;
      printf("consumidor consumiu %d itens\n", count);
    
      if(count == N-1)//se o contador de itens for igual ao tamanho maximo menos um, um novo item pode ser produzido
      {
           pthread_cond_signal(&full);//, &mutex); // um item foi consumido, o produtor agora pode produzir um novo item
      }
      pthread_mutex_unlock(&mutex);//desbloqueio da sessão critica
      sleep(3);
   }
}

int main()
{
   //cria o produtor
   pthread_t produtor[1];
   pthread_create(&produtor[1], NULL, Inserir, NULL);	
   
   //cria o consumidor
   pthread_t consumidor[1];
   pthread_create(&consumidor[1], NULL, Remover, NULL);

   pthread_exit(NULL);
}
