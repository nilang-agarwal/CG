#include<stdio.h>
int main()
{
int a[10],b[10], n, i, j,count;
n=10;
printf("Enter 10 elements:");
for(i=0; i<n; i++)
{
	b[i]=-1;
	scanf("%d", &a[i]);
}
for(i=0; i<n; i++)
{	
	count=0;
	for(j=i+1;j<n;j++)
	{
		if(a[i]==a[j])
		{
			count++;
		}

	}
	if(count==0)
		b[i]=a[i];

}

printf("Unique Elements:\n");
for(i=0; i<n; i++)
{	
	if(b[i]!=-1)
	printf("%d \n", a[i]);
}
//for(i=0;i<sizeof(b);i++)
//printf("%d\n",b[i]);

}
