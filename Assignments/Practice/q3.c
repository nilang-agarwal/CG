// Given an array of integers, write a program to find all duplicate elements in the array.
#include<stdio.h>
int main()
{
int arr[20], i, j, n;
printf("Enter number of integers: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
	scanf("%d", &arr[i]);
}

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(i==j)
			continue;
		else
			if(arr[i]==arr[j])
				if(i<j)
					printf("%d ", arr[i]);
	}
}
return 0;
}
