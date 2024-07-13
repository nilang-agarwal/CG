#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void* mythread(int n)
{
	printf("This is the thread.%dn", n);
	sleep(3);
	printf("Ending Thread.\n");
	return NULL;
}

int main()
{
pthread_t t1, t2;
pthread_create(&t1, NULL, &mythread,void* (*) 3);
pthread_create(&t2, NULL,&mythread, void* (*) 4 );
pthread_join(t1, NULL);
pthread_join(t2, NULL);

return 0;
}

