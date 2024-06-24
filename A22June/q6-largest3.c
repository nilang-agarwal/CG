// Largest of 3 numbers
#include<stdio.h>
int main()
{
int a,b,c,g;
printf("Enter 3 numbers:\n");
scanf("%d%d%d", &a,&b,&c);
if (a>=b && a>=c) g=a;
else if (b>=a && b>=c) g=b;
else g=c;
 printf("\n%d is largest\n", g);

return 0;

}
