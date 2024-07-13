#include<stdio.h>
#include<string.h>
int palindrome(char str[100])
{
int n=strlen(str), flag=1;
for(int i=0;i<n/2;i++)
{
	if(str[i]!=str[n-1-i])
		flag=0;
}
return flag;
}

int main()
{
int n;
char a[50];
printf("Enter Any String: ");
fgets(a,50,stdin);

n=strlen(a);
if(a[n-1]=='\n')
	a[n-1]='\0';

int flag= palindrome(a);

if(flag==0)
	printf("Not Palindrome\n");
else
	printf("Palindrome\n");

return 0;
}
