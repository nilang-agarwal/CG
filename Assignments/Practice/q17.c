#include<string.h>
#include<stdio.h>
int main()
{
int n,i,flag=0;
char *tok, str[100], words[10][10], rem[10];
printf("Input string: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
	str[n-1]='\0';

printf("Input word to remove: ");
fgets(rem,10,stdin);
n=strlen(rem);
if(rem[n-1]=='\n')
	rem[n-1]='\0';

tok= strtok(str," ");
n=0;

while(tok!=NULL)
{
	strcpy(words[n],tok);
	n++;
	tok=strtok(NULL," ");
}

for(i=n-1; i>=0;i--)
{
	if(strcmp(words[i],rem)==0)
	{
		strcpy(words[i],"");
		flag=1;
		break;
	}	
}

if(flag==0)
	printf("%s Not found in string.\n",rem);
else
{
	printf("String after removing %s: ",rem);
	for(i=0;i<n;i++)
		printf("%s ",words[i]);
}

		printf("\n");


return 0;
}

