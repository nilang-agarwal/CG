#include<stdio.h>
int main()
{
int arr[20], i, j, n=10, sum=0, min=2147483647;
//printf("Enter number of integers: ");
//scanf("%d", &n);
printf("Enter %d integers:\n",n);
for(i=0;i<n;i++)
{	
	scanf("%d", &arr[i]);
	sum=sum+arr[i];
	if(arr[i]<min)
		min=arr[i];
}

j=sum-n*(min-1);

printf("Missing num=%d\n", min+(66-j-1));

return 0;
}
