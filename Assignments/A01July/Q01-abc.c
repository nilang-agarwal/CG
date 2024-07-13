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
		if(asciia[i]!=asciib[i])
			return 0;

	}

return 1;
}
}

int main()
{
int i,na, nb, nc;
char a[10], b[10], c[20];
printf("Enter String A: ");
fgets(a,10,stdin);
printf("Enter String B: ");
fgets(b,10,stdin);
printf("Enter String C: ");
fgets(c,20,stdin);
na=strlen(a);
if(a[na-1]=='\n')
	a[na-1]='\0';
na=strlen(a);
nb=strlen(b);
if(b[nb-1]=='\n')
	b[nb-1]='\0';
nb=strlen(b);
nc=strlen(c);
if(c[nc-1]=='\n')
	c[nc-1]='\0';
nc=strlen(c);
strcat(a,b);
i=anag(a,c);
if(i==0)
	printf("NO:");
else
	printf("YES\n");
return 0;
}
