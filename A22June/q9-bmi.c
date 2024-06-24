// BMI
#include<stdio.h>
int main()
{
float w, h, bmi;
printf("Enter Weight in kgs:");
scanf("%f", &w);
printf("Enter Height in meters");
scanf("%f", &h);
bmi = w/(h*h);

if (bmi>=30)
	printf("Obesity");

else if (bmi>=25)
	printf("Overweight");

else if (bmi>=18.5)
	printf("Normal Weight");

else
	printf("Underweight");

printf("\n");
return 0;
}

