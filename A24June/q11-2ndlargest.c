#include<stdio.h>
int main()
{
int n=10, a[10], i, j, r;
printf("Enter 10 Numbers:\n");
for(i=0;i<n;i++)
	scanf("%d", &a[i]);


///////////////
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
//////////////


for(i=n-1;i>=1;i--)
{
	if(a[i]!=a[i-1])
	{	//printf("%d",a[i]);
		j=a[i-1];
		break;
	}
}


if(a[0]==a[n-1])
{
	printf("All Elements Same, SO No Second Largest\n");
}
else
printf("Second Largest = %d\n\n", j);

return 0;

}
