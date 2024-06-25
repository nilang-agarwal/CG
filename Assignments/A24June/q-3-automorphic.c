#include<stdio.h>
#include<math.h>
int main()
{
int n,a,b,d=0;
printf("Enter any Number: ");
scanf("%d", &a);
n=a;

while(a>0)
{
a=a/10;
d++;
}
a=n*n;
if(n== n*n%(int)pow(10,d))
	printf("Automorphic");
else

	printf("Not Automorphic");

printf("\n");

return 0;
}
