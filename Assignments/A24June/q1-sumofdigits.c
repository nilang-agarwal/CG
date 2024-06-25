#include<stdio.h>
int main()
{
int a,sum=0;
printf("Enter any number: ");
scanf("%d", &a);
while(a>0)
{
	sum=sum+a%10;
	a=a/10;
}

printf("Sum Of Digits= %d\n", sum);

return 0;
}
