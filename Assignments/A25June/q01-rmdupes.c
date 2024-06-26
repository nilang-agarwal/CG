#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
int n,count=0,i,j=0;
bool check[256] = {false};

char str1[200];
printf("Enter a string of words: ");
//strncat(buff,str1[0],200);

scanf("%[^\n]s", str1);
n=strlen(str1);
for(int i=0;i<n;i++)
{
	if(check[str1[i]]==false)
	{	
		check[str1[i]]= true;
		str1[j]=str1[i];
		j++;
	}
}

str1[j]='\0';

printf("%s\n", str1);

return 0;
}


