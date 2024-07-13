#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
int id1=fork();
int id2=fork();

if(id1!=0)
{
	if(id2==0)
	{
		printf("Leaf Child of Root Parent.\t");
		printf("id1= %d, id2= %d, pid= %d, ppid= %d\n", id1, id2, getpid(), getppid());
	}
	else
	{	
		wait(NULL);
		printf("Root Parent. \t\t\t");
		printf("id1= %d, id2= %d, pid= %d, ppid= %d\n", id1, id2, getpid(), getppid());
	}
}
else
{
	if(id2==0)
	{	
		printf("Leaf child of Non-root parent.  ");
		printf("id1= %d, id2= %d, pid= %d, ppid= %d\n", id1, id2, getpid(), getppid());
	}
	else
	{
		wait(NULL);
		printf("non Leaf Child of Root Parent.  ");
		printf("id1= %d, id2= %d, pid= %d, ppid= %d\n", id1, id2, getpid(), getppid());
	}
}

return 0;
}
