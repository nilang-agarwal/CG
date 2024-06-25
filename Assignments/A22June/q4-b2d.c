//Binary To Decimal
#include<stdio.h>
#include<math.h>
int main()
{
int b,n=0,on,x;
float d;
printf("Enter a Binary Number: ");
scanf("%d",&b);
printf("\nBinary= %d\n",b);
while(b>0)
{
on=b%10;
b=b/10;
x= pow(2,n);
d = d + on* x;
n++;
}
printf("Decimal= %d\n\n",(int)d);
return 0;
}
