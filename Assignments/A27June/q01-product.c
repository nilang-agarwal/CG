#include<stdio.h>
#include<string.h>
typedef struct product
{
	int sale;
	char pid[10];
	int uniq;
} PROD;
int main()
{
int n,i,uniq=0,j;
PROD prod[20],temp;
printf("Enter number of inputs: ");
scanf("%d", &n);

for(i=0;i<n;i++)
{
printf("Enter Product ID: ");
scanf("%s",prod[i].pid);
printf("Enter Total Sales: ");
scanf("%d",&prod[i].sale);
prod[i].uniq=0;
}

for(i=0;i<n-1;i++)
{
	for(j=0;j<n-1-i;j++)
	{
		if(prod[j].sale<prod[j+1].sale)
		{
			temp=prod[j];
			prod[j]=prod[j+1];
			prod[j+1]=temp;
		}
	}

}

///     Unique or Not
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
	if(strcmp(prod[i].pid,prod[j].pid)==0)
			prod[j].uniq=1;
}
}

for(i=0;i<n;i++)
	if(prod[i].uniq==0)
		printf("%s, %d\n", prod[i].pid, prod[i].sale);

return 0;
}
