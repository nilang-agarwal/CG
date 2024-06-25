#include<stdio.h>

#include<math.h>
int main()
{
int n,a,b=0,d=0;
printf("Enter Any Number: ");
scanf("%d", &n);
a=n;
while(a>0)
{
	d++; // to find the number of digits
	a=a/10;
}
a=n;
while(a>0)
{
b=b+pow(a%10,d);
a=a/10;

}
b=(int)b;

if(b==n)
printf("Armstrong\n");
else
printf("Not Armstrong\n");

return 0;
}
