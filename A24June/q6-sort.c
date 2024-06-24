#include<stdio.h>
int main()
{
int *a,n,i,r,j;

printf("Enter Number of elements: ");
scanf("%d",&n);
printf("Enter %d Numbers\n",n);

for(i=0;i<n;i++)
{
	scanf("%d", &a[i]);
}


printf("Unsorted Array:");
for(i=0;i<n;i++)
{
	printf("%d  ", a[i]);
}

for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{
			r=a[i];
			a[i]=a[j];
			a[j]=r;
		}
	}
}


printf("Sorted Array:");
for(i=0;i<n;i++)
{
	printf("%d  ", a[i]);
}

printf("\n");

}
