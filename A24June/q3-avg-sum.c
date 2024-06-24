#include<stdio.h>
int main()
{

int n,*a,i;

float avg,sum=0;
printf("Enter number of elements of the array: ");
scanf("%d", &n);
printf("Enter %d Numbers:\n",n);
for(i=0;i<n;i++)
  {
	scanf("%d", &a[i]); 
	sum+=a[i];
  }

avg= sum/n;
printf("SUM= %.0f \t AVG= %f\n",sum, avg);


}
