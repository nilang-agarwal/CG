#include<stdio.h>
int main()
{
int b[10], a[10], n=10,ls, i,j;
printf("Enter 10 numbers");
for(i=0;i<n;i++)
	scanf("%d", &a[i]);
printf("Enter number of left shifts: ");
scanf("%d", &ls);

for(i=ls;i<n;i++)
	b[i-ls]=a[i];

for(i=0;i<ls;i++)
	b[n-ls+i]=a[i];

for(i=0;i<n;i++)
	printf("%d  ", b[i]);

return 0;
}
