
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

void *producer_process(void *args);
void *consumer_process(void *args);

int counter=0;
int data[10];

pthread_mutex_t P;

int main(){

    pthread_t thread1,thread2;

    pthread_create(&thread1, NULL, producer_process, NULL);
    pthread_create(&thread2, NULL, consumer_process, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}



void *producer_process(void *args){
    pthread_mutex_lock(&P);
    printf("Entering producer...\n Buffer Size before production =%d  items\n",counter);
    sleep(3);
    if (counter==0){
	printf("Producing Random Values()...\n");
        for(int i=1; i<=10; i++){
            data[i] = (i*i*i*i*i);     //producing a random number
            ++counter;
        }
    }
    sleep(3);
    printf("Exiting producer...\n Buffer Size after production=%d items\n\n",counter);
    sleep(3);
    pthread_mutex_unlock(&P);
}

void *consumer_process(void *args){
    pthread_mutex_lock(&P);
    printf("Entering consumer...\nAvailable items in buffer for consumer =%d items\n",counter);
    sleep(3);
    if (counter>0){
	printf("Reading Randoms Values...\n");
	sleep(3);
        for(int i=1; i<=10; i++){
            printf("%d ",data[i]);     //consuming random numbers from array
            --counter;
        }
	printf("\n\n");
    }
    printf("Exiting Consumer...\nAvailable items in buffer for consumer after consumption =%d items\n", counter);
    sleep(3);
    pthread_mutex_unlock(&P);
}

