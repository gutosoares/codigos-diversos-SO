#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h> 
 
#define NUMTHR 10 // Numero total de threads
 
int num_ptos [10]; // Total de pontos da thread
int num_ptos_cir[10]; // Pontos no circulo
 
 
void *calcula (void *param); // sorteia e verifica os pontos pela thread
 
 
int main (int argc, char *argv[]){
 
int j;
int i;
double pi = 0; // contem o valor de pi
int totalp = 0; // total de pontos
int totalc = 0; // pontos no circulo
pthread_t tid[10]; // ID das threads
 
 
// Para todas as threads
for (i = 0; i< NUMTHR ; i++){
// cria a i-esima thread
pthread_create (&tid[i], NULL, calcula, &i);
}	
 
// Para cada thread
for (i = 0; i< NUMTHR ; i++){
// espera que as threads terminem
pthread_join (tid[i], NULL);
}	
 
for (i = 0; i< NUMTHR ; i++){
totalp += num_ptos[i]; // totalp = totalp + num_ptos[i]
totalc += num_ptos_cir[i]; // totalc = totalp + num_ptos[i]
}	
 
 
// Calcula o valor de pi e imprime na tela
pi = 4.0*(((double)totalc)/((double)totalp)); // transforma totalp
// e totalc em double
printf("Valor de pi:%fn",pi);
}
 
 
 
 
 
void *calcula (void *param) {
 
int i;
int thrnum = *((int *)param); // O n�mero da thread ()
double x,y,quad;
num_ptos[thrnum] = 0;
num_ptos_cir[thrnum] = 0;
 
for (i = 0; i<1000000; i++){
 
x = rand() % 2; // sorteia um n�mero de 0 a 1
y = rand() % 2; // sorteia um n�mero de 0 a 1
quad = ((x*x) + (y*y));
// Se a soma dos quadrados for menor que R = 1
// ent�o caiu no c�rculo
if (quad <= 1){
num_ptos_cir[thrnum] ++; // conta pontos no c�rculo
}
 
num_ptos[thrnum] ++; // incrementa os pontos totais da thread N (0 a 9)
 
// A cada 10 mil itera��es imprime na tela
if (i%10000==0)
printf("thread: %i n",thrnum);
}
 
// Imprime na tela a qtde de pontos no c�rculo
// e no total de cada thread
printf ("Circ t%i:%dn",thrnum,num_ptos_cir[thrnum]);
printf ("Total t%i:%dn",thrnum,num_ptos[thrnum]);	
pthread_exit(0);
}
 
 
