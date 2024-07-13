#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char *token, str[100];
int i,n;
printf("Enter string number: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
	str[n-1]='\0';
token=strtok(str,",");

while(token!=NULL)
{
i=atoi(token);
printf("Integer: %d\n\n",i*2);
token=strtok(NULL,",");
}
return 0;
}
