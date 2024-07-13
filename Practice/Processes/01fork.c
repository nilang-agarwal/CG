#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int id=fork(), i=0;

if(id==0)
{	
	sleep(2);
//	printf("In Child..................id=%d, pid=%d, ppid=%d\n", id, getpid(), getppid());	
	for(i=1;i<=5;i++)
		printf("%d ", i);
}
else if(id>0)
{	
	sleep(4);

	wait(NULL);
	for(i=6;i<=10;i++)
		printf("%d ", i);
	printf("\n");
	if(wait(NULL)==-1)
	{
		printf("No child process to wait for..\n");
	}
//	printf("In Parent..................pid=%d, id=%d\n", getpid(), id);	
//	printf("In Parent..................id=%d, pid=%d, ppid=%d\n", id, getpid(), getppid());	
}

return 0;
}
