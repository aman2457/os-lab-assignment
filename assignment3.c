#include<semaphore.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

int count=5;
sem_t sem_phore;
void *th1()
{
int i;
sem_wait(&sem_phore);
printf("Semaphore Wait started(p1 shraed).....\n");
int var_inc1;
var_inc1 = count;
for(i=1;i<=count;i++)
{
 var_inc1 += 1;
}
sleep(3);
count= var_inc1;
sem_post(&sem_phore);
printf("Semaphore Wait exited(p1 shared).....\n");
printf("Count value inside first thread =%d\n",count);
}
void *th2()
{
int i;
sem_wait(&sem_phore);
printf("Semaphore Wait started(p2 shared).....\n");
int var_inc2;
var_inc2 = count;
for(i=1;i<=count;i++)
{
 var_inc2 += 1;
}
sleep(3);
count = var_inc2;
sem_post(&sem_phore);
printf("Semaphore Wait exited(p2 shared).....\n");
printf("Count value inside second thread=%d\n",count);
}
void *th3()
{
int i;
sem_wait(&sem_phore);
printf("Semaphore Wait started(p3 not shared).....\n");

int var_inc3 = count;
for(i=1;i<=count;i++)
{

 var_inc3 += 1;
}
sleep(3);
count = var_inc3;
sem_post(&sem_phore);
printf("Semaphore Wait exited(p3 not shared).....\n");
printf("Count value inside third thread=%d\n",count);
}

int main()
{
printf("-----------------Problem 3------------------------\n");
printf("==================================================\n");;
		printf("--------------------------------------------------\n");  
	    printf("||\t      Name- Aman Kumar    \t\t ||\n");
		printf("||\t      Reg_no - 11803761     \t\t ||\n");
		printf("||\t      Sec - K18SJ              \t\t ||\n");
		printf("||\t      Roll - 25               \t\t ||\n");
		printf("||\t      Course Code - CSE325    \t \t ||\n");
		printf("||\t      Course - Operating System Lab      ||\n");
	    printf("--------------------------------------------------\n");
printf("initial value of count is=%d\n",count);
int i,k=0;
for(i= 0;i<2;i++)
{
i++;
}
sem_init(&sem_phore,0,i);
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,th1,NULL);
pthread_create(&t2,NULL,th2,NULL);
pthread_create(&t3,NULL,th3,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
printf("final value of count inside main=%d\n",count);
}
