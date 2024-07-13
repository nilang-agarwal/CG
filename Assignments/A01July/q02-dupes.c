#include<stdio.h>
#include<string.h>

int anag(char a[10], char b[10])
{
int i, n, asciia[256]={0}, asciib[256]={0};
if(strlen(a)!=strlen(b))
	return 0;
else
{
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		asciia[a[i]]++;
	}
	
	for(i=0;i<n;i++)
	{
		asciib[b[i]]++;
	}

	for(i=0;i<256;i++)
	{	
		//printf("%c: %d %d\n", asciia[i], asciia[a[i]], asciib[b[i]]);
		if(asciia[i]!=asciib[i])
			return 0;
		//	printf(".................return 0...............\n");

	}

return 1;
}
}

int main()
{
char str[100], *token, words[10][10];
int n,i=0,j, flag, check[10]={0};
printf("Enter '|' seprated Words: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
	str[n-1]='\0';
n=0;
token=strtok(str, "|");

while(token!=NULL)
{	
	strcpy(words[n],token);
	//printf("%d: %s \n", i,token);
	token = strtok(NULL, "|");
	n++;
}

for(i=0;i<n;i++)
{
flag=0;
// printf("%d: %s\n",i, words[i]);
for(j=i+1;j<n;j++)
{		

	if(anag(words[i],words[j])&& words[j]!="\n")
	{
		printf("%s ",words[j]);
		strcpy(words[j], "");
		flag=1;
	//	check[j]=1;
	//	check[i]=1;
	}
}
if(flag==1)
{
	//check[i]=1;
	printf("%s ", words[i]);
	
}
}
/*
for(i=0;i<n;i++)
{
	if(check[i]==1)
	{
		printf("%s", words[i]);
	}
}
*/
printf("\n");
return 0;
}	
