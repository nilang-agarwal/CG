#include<stdio.h>
#include<string.h>
int main()
{
int n,now=0;
char str[100], *token, words[10][10];
printf("Enter the string in Lower Case: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
{
	str[n-1]='\0';
	n--;
}

token=strtok(str," ");
while(token!=NULL)
{	
//	printf("%s",token);	
	strcpy(words[now], token);
	token=strtok(NULL, " ");
	now++;
}

for(int i=0;i<now;i++)
{
	words[i][0]=words[i][0]-32;
	printf("%s ", words[i]);
}
printf("\n");

return 0;
}
