#include<stdio.h>
#include<string.h>
int main()
{
int n, count=0;
char *token, aa[100], a[10][10];
printf("Enter space seprated words: ");
fgets(aa,100,stdin);
n=strlen(aa);
if(aa[n-1]=='\n')
	aa[n-1]='\0';
token=strtok(aa," ");
while(token !=NULL)
{
	count++;

	printf("%s\n", token);
	
	strcpy(a[count],token);
	token=strtok(NULL, " ");
}

int check[10]={0};
int i=0,j=0;
while(i<count)
{	
	if(check[i]==0)
	for(j=i+1;j<count;j++)
	{
		if(a[i]==a[j])
		{
			check[i]=1;
			check[j]=1;
		}
	}
i++;
}
i=1;

while(i<count+1)
{
printf("%s: %d\n", a[i], check[i]);
i++;
}	
return 0;
}
