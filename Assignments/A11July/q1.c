#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid;
pid=fork();

if(pid<0)
{
	printf("Error in fork.\n");
}
else if(pid==0)
{
	printf("Hello from Parent.\n");
}
else
{
	printf("Hello from Child.\n");
}

return 0;
}
