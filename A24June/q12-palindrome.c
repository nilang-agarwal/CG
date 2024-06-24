#include<stdio.h>
int main()
{
int a[10],n=10,i,j;

printf("Enter 10 Numbers:\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}

j=0;
for(i=0;i<n;i++)
{
	if(a[i]!=a[n-1-i])
		j=1;
		break;
}

if(j==0) printf("Palindrome\n");
else	 printf("Not Palindrome\n");

return 0;
}
