#include<stdio.h>
#include<string.h>
void myflush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main()
{
int n,i,flag=0;
char str[100], a, b;
printf("Enter String: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
{
	str[n-1]='\0';
	n--;
}
printf("Enter which character to replace: ");
scanf("%c", &a);
myflush();
printf("Enter the character to replace with: ");
scanf("%c", &b);

for(i=0;i<n;i++)
{
	if(str[i]==a)
	{
		str[i]=b;
		flag=1;
		break;
	}
}

if(flag==0)
{
	printf("Character Not Found");
}

else
{
	printf("String after character replacement:\n%s\n", str);
}

//printf("%s , %c, %c", str, a,b);

return 0;
}
