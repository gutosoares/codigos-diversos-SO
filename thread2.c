//gcc meu.c  -o meu -std=c99 -pthread && ./meu



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num 30


int global_counter = 0;

pthread_mutex_t mutex;

void *soma(void* param){

	pthread_mutex_lock(&mutex);

	int count;
	count = global_counter;
	sched_yield();
	count++;
	global_counter = count;
	printf("%d\n", global_counter);
	pthread_mutex_unlock(&mutex);

	return NULL;

              }

int main(){

	int i;
	
	pthread_t ts[num];
		
for (i=0;i<num;i++){

		pthread_create(&ts[i],NULL,soma,NULL);

			}

for(i=0;i< num;i++){

	pthread_join(ts[i],NULL);
			}


	return 0;
   }


