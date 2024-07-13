#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
int fd[2];
if(pipe(fd)==-1)
{
	printf("Error while opening pipe.\n");
}

int id = fork();
if(id<0){
	printf("Error while fork.\n");
	return 3;
}
else if(id==0)
{
	close(fd[0]);
	int x;
	printf("Enter any number to write to pipe from child: ");
	scanf("%d", &x);
	if(write(fd[1], &x, sizeof(int))==-1){
		printf("Error while writing to the pipe.\n");
		return 1;
	} 
	printf("From Child.  x=%d\n",x);
	close(fd[1]);
}
else
{	
//	wait(NULL);	
	close(fd[1]);
	int y;
	if(read(fd[0],&y, sizeof(int))==-1){
		printf("Error while Reading from pipe.\n");
		return 2;
	}
	printf("From Parent. y=%d\n", y);
	close(fd[0]);
}


return 0;
}
