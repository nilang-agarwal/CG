// Merge 2 arrays

#include<stdio.h>
int main()
{
int a[10],n,i,m,b[10],ab[20];
n=10;
m=10;


//printf("Enter Number of elements in first array: ");
//scanf("%d",&n);
printf("Enter %d Nmbers\n",n);
for(i=0;i<n;i++)
{
	scanf("%d", &a[i]);
}

//printf("Enter Number of elements in second array: ");
//scanf("%d",&m);
printf("Enter %d Numbers\n",m);
for(i=0;i<m;i++)
{
	scanf("%d", &b[i]);
}

for(i=0;i<n;i++)
{
	ab[i]=a[i];
}

for(i=0;i<m;i++)
{
	ab[n+i]=b[i];
}


for(i=0;i<m+n;i++)
{
	printf("%d  ", ab[i]);

}
printf("\n\n");
return 0;
}
