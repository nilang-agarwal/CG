// Temperature
#include<stdio.h>
int main()
{
int t;
printf("Enter temperature in Celsius: ");
scanf("%d",&t);

if(t>>30)
{
	printf("It's hot outside, stay hydrated!");
}
else if(t>=20)
{
	printf("The weather is nice and warm.");
}
else if(t>=10)
{
	printf("It's a bit chilly, wear a jacket.");
}
else
{
	printf("It's cold outside, stay warm!");
}
printf("\n");
return 0;
}
