#include<stdio.h>
#include<string.h>
int main()
{
int len, n, lin;
char str[100],in[10], ans[110]="\0";
printf("Enter the string: ");
fgets(str,100,stdin);
len=strlen(str);
if(str[len-1]=='\n')
	str[len-1]='\0';
len=strlen(str);

printf("Enter character to insert: ");
fgets(in,10,stdin);
lin=strlen(in);
if(in[lin-1]=='\n')
	in[lin-1]='\0';
lin=strlen(in);

printf("Enter Index: ");
scanf("%d", &n);

printf("To insert %s at index %d in %s\n", in, n, str);

strncat(ans, str, n);
strncat(ans, in, lin);
strncat(ans, str+n, len-n);

printf(".....................\n%s\n", ans);
return 0;
}
