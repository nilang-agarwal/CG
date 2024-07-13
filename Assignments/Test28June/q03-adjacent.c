#include<stdio.h>
#include<string.h>
int main()
{
int n,i;
char str[20],temp[20];
printf("Enter any word: ");
fgets(str,20,stdin);
n=strlen(str);
if(str[n-1]=='\n');
	str[n-1]=' ';

int j=0;
int flag 1;
while(flag==1)
for(i=0;i<n;i++)
{	
	flag=0;
	if(str[i]==str[i+1]+1 || str[i]==str[i+1]-1)
	{	
		str[i]=' ';
		str[i+1]=' ';
		flag=1;	
	}
}

printf("\n%s\n", str);
return 0;
}
