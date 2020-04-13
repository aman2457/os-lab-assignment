#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
int shared_variable=5;
pthread_mutex_t lock_p=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_q=PTHREAD_MUTEX_INITIALIZER;

void *writer_thread()  //writer thread with mutex lock.
{
int i;
pthread_mutex_lock(&lock_p);
printf("\nInside Writer \n");
int var_writer;
var_writer = shared_variable;
sleep(1);
for(i=0;i<shared_variable;i++)
{
var_writer += 1;
}

shared_variable = var_writer;
printf("\nthe value of shared variable inside writer is=%d\n",shared_variable);
pthread_mutex_unlock(&lock_p);
//printf("Exited from Lock\n");

}


void *reader_thread1()
{
pthread_mutex_lock(&lock_q);
int var_first_reader;
var_first_reader = shared_variable;
printf("\nInside First Reader\n");
sleep(2);
printf(" \nValue of shared variable is=%d\n",shared_variable);
pthread_mutex_unlock(&lock_q);
}

void *reader_thread2()
{
int var_second_reader;
var_second_reader = shared_variable;
printf("\nInside second reader\n");
printf("\nValue of shared variable is (second reader)%d\n",var_second_reader);
}
int main()
{
pthread_t t1,t2,t3;

pthread_create(&t1,NULL,writer_thread,NULL);
pthread_create(&t2,NULL,reader_thread1,NULL);
pthread_create(&t3,NULL,reader_thread2,NULL);

pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t1,NULL);
printf("the value of shared variable inside main =%d\n",shared_variable);
}
