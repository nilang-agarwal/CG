#include<stdio.h>
#include<string.h>
typedef struct product{
char pid[10];
int quant;
int uniq;
} PROD;

int main()
{
int i,j,n;
PROD prod[20],temp;
printf("Enter number of inputs: ");
scanf("%d", &n);
getchar();
for(i=0;i<n;i++)
{	
	prod[i].uniq=0,temp;
	printf("Enter Product ID: ");
	
	fgets(prod[i].pid,10,stdin);

	j=strlen(prod[i].pid);
	if(prod[i].pid[j-1]=='\n')
		prod[i].pid[j-1]='\0';

	printf("Enter Quantity: ");
	//getchar();
	scanf("%d", &prod[i].quant);
	getchar();
	for(j=0;j<i;j++)
	{
		if(strcmp(prod[i].pid,prod[j].pid)==0)
		{
			prod[i].uniq=1;
			prod[j].uniq=0;
			prod[j].quant+=prod[i].quant;
			prod[i].quant=0;
		}
	}
}

for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(prod[i].quant<prod[j].quant)
		{
			temp=prod[i];
			prod[i]=prod[j];
			prod[j]=temp;
		}
	}
}


for(i=0;i<n;i++)
	if(prod[i].uniq==0)
		printf("%s, %d\n",prod[i].pid,prod[i].quant);

return 0;
}

