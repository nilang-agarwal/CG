#include<stdio.h>
int main()
{

int i,a[5];
printf("Enter 5 Elements for array.\n");
for(i=0;i<5;i++)
	scanf("%d",&a[i]);

printf("The Entered array is:\n");


for(i=0;i<6;i++)
	printf("Value= %d\tAddress=%u\n",a[i],&a[i]);

return 0;
}
