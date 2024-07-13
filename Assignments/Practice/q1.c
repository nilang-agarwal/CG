#include<stdio.h>
#include<limits.h>
int main()
{
int arr[20],max=INT_MIN,i,j,n;
printf("Enter NUmber of integers: ");
scanf("%d", &n);
printf("Enter %d integers:\n",n);
for(i=0;i<n;i++)
{
	scanf("%d", &arr[i]);
}
max=arr[n-1];
printf("................\n%d ", arr[n-1]);
for(i=n-1;i>=0;i--)
{
	if(arr[i]>max)
	{	
		max=arr[i];
		printf("%d ", max);
	}
}

}
