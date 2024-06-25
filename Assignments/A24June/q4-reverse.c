#include<stdio.h>
int main()
{
int i, a[10], r[10], n;

//printf("Enter number of elements of the array: ");
//scanf("%d", &n);
printf("Enter 10 Numbers:\n");
n=10;
for(i=0;i<n;i++)
  {	printf("..%d..", i);
	scanf("%d", &a[i]); 
  }

for(i=0;i<n;i++)
  {
  	r[i]=a[n-i];
  }

printf("Array= ");

for(i=0;i<10;i++)
	printf("%d",a[i]);

for(i=0;i<n;i++)
  {
	printf("%d  ", a[i]);
  }

printf("\nReverse= ");


for(i=0;i<n;i++)
  {
	printf("%d  ", r[i]);
  }


return 0;
}
