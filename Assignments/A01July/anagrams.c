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
printf("%d\n", anag("adbc","dbac"));

printf("%d\n", anag("abcss","dacss"));
return 0;
}





