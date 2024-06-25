//Comment
#include<stdio.h>
int main()
{
int t,c;
float far,cel;
printf("\n\nSelect to enter temperature in:\n1: Celsius\n2: Farenheit\n ");
scanf("%d",&c);
//printf("Enter Temp: ");
//scanf("%d",&t);
if(c==1)
{	
	printf("Enter Temp: ");
	scanf("%d",&t);
	cel=t;
	far= cel*1.8 + 32;
	printf("\nThe Tempurature is: %.2f Celsius or %.2f Farenheit\n",cel, far);
}
else if(c==2)
{	

	printf("Enter Temp: ");
	scanf("%d",&t);
	far=t;
	cel= (far-32)/1.8;
	printf("\nThe Tempurature is: %.2f Celsius or %.2f Farenheit\n",cel, far);
}
else
{
	printf("\nWrong Choice\n\n");
}
return 0;
}
