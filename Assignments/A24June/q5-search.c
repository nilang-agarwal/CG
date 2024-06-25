#include<stdio.h>
int main()
{

int *a,i,ind,n,s;
printf("Enter Number of elements: ");
scanf("%d",&n);
printf("Enter %d Numbers\n",n);

for(i=0;i<n;i++)
{
	scanf("%d", &a[i]);
}

printf("Enter Value to be searched");
scanf("%d", &s);

ind=-1;
for(i=0;i<n;i++)
{	
	if(s==a[i])
	{
	ind=i;
	break;
	}

//	scanf("%d", &a[i]);
}

printf("Element at index %d.\n", ind);


}
