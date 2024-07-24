#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{


int n=argc-2, arr[100], fd[2], start, end;

for(int i=2;i<argc; i++)
{
int s= atoi(argv[i]);
arr[i-2]=s;
}

if(pipe(fd)==-1)
{
	printf("Error creating Pipe.\n");
	return 1;
}

int id=fork();

if(id==0)
{
	start=0;
	end=n/2;
}
else if(id>0)
{
	start=n/2;
	end=n;
}
else
{

	printf("Error in fork.\n");
	return 2;
}

int sum=0;
for(int i=start;i<end;i++)
{
	sum+=arr[i];
}

printf("Partial Sum= %d\n", sum);

if(id==0)
{
	close(fd[0]);
	write(fd[1], &sum, sizeof(int));
	printf("Child sent to parent sum=%d\n", sum);
	close(fd[1]);
}
else
{
	close(fd[1]);
	int sumc;
	read(fd[0], &sumc,sizeof(int));
	printf("sum got from child=%d\n", sumc);
	close(fd[0]);
	sum+=sumc;
	printf("Total Sum= %d\n", sum);
}


return 0;
}



