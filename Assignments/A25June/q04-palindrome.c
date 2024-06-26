#include<stdio.h>
#include<string.h>

int main()
{
int n;
char a[50];
printf("Enter Any String: ");
fgets(a,50,stdin);

n=strlen(a);
if(a[n-1]=='\n')
	a[n-1]='\0';

n=strlen(a);

int flag=1;
for(int i=0;i<n/2;i++)
{
	if(a[i]!=a[n-1-i])
		flag=0;
}

if(flag==0)
	printf("Not Palindrome\n");
else
	printf("Palindrome\n");

return 0;
}
