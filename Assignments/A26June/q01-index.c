#include<stdio.h>
#include<string.h>
int main()
{
char a[100], b[100], c;
int na, nb, fs=-1, fc=-1;
printf("Enter any string: ");
fgets(a,100,stdin);
na=strlen(a);
if(a[na-1]=='\n')
	a[na-1]='\0';
na=strlen(a);

printf("Enter any sub-string: ");
fgets(b,100,stdin);
nb=strlen(b);
if(b[nb-1]=='\n')
	b[nb-1]='\0';
nb=strlen(b);

printf("Enter any Character: ");
scanf("%c", &c);

int i=0;
while(i<na)
{
if(a[i] == c)
{
	fc=i;
	break;
}
i++;
} i=0;

char *p=strstr(a,b);
if(p!=NULL)
	fs=p-a;


printf("Sub-string %s at %d\n", b, fs);
printf("Character at %d\n", fc);
return 0;
}
