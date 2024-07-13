#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int palindrome(char str[100])
{
int n=strlen(str),j, flag=1;
for(int i=0;i<n/2;i++)
{
	if(str[i]!=str[n-1-i])
		flag=0;
}
return flag;
}

int main()
{
char a[50],b[4],c[5];
int n,j;
printf("Enter any string: ");
scanf("%s", a);
n=strlen(a);
if(a[n-1]=='\n')
	a[n-1]='\0';
n=strlen(a);
if(n<4)
{
	printf("Score=0");
	exit(0);
}
int score=0;
for(int i=0;i<=n-4;i++)
{	
	for(j=0;j<4;j++)
	{
		b[j]=a[j+i];
	}

		if (palindrome(b)==1 )
		{
			score+=5;	
			printf("%s: %d , ", b,5);
		}
		b[0]='\0';
	
	for(j=0;j<5;j++)
	{
		c[j]=a[j+i];
	}

		if (palindrome(c)==1)
		{
			score+=10;
			printf("%s: %d , ", c,10);
		}
b[0]='\0';
}
printf("\nScore= %d\n\n", score);
return 0;
}

