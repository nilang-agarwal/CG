#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
int i, n, id[100];
printf("argc= %d\n", argc);
n=atoi(argv[1]);
printf("main PID= %d, PPID= %d\n\n", getpid(), getppid());

for(i=0;i<n;i++)
{
id[i]=fork();

if(id[i]==0)
{ // CHILD PROCESS  
	printf("Child %d, PID= %d, PPID= %d\n", i, getpid(), getppid());
	return 0;
}


}

for(i=0;i<n;i++)
{
	wait(NULL);
}
return 0;
}
