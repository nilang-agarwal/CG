#include<stdio.h>
int main()
{
int i,a[10],max,min;
printf("Enter 10 numbers\n ");
for(i=0;i<10;i++)
  {
	scanf("%d", &a[i]);
  }


for(i=0;i<10;i++)
{	if(a[i]>=max)
		max=a[i];
	if(a[i]<=min)
		min=a[i];
}

printf("MAX= %d, MIN=%d\n\n",max, min);

return 0;
}
