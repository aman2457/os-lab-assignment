#include<stdio.h>
#include<unistd.h>
int main()
{
int fds[2];
int check_var;
int process_variable;
int flag;
char msg[]="hello parent,this is child process";
char buffer_read[50];
check_var = pipe(fds);
if(check_var == -1)
{
printf("unable to create a pipe\n");
return 1;
}
process_variable =fork();
if(process_variable == 0)
{
write(fds[1],msg,sizeof(msg));
}
else
{
flag = read(fds[0],buffer_read,sizeof(buffer_read)); 
if(flag)
{
printf("message from child to parent (inside parent)\n");
printf("%s\n",buffer_read);
printf("This is Parent Process\n");
}
}
return 0;
}
