#include<stdio.h>
#include<string.h>
int main()
{
int len,n,i=0,flag=1;
char str[20],ans[20];
printf("Enter any word: ");
fgets(str,20,stdin);
len=strlen(str);
if(str[len-1]=='\n')
	str[len-1]=' ';

strcat(str," ");
printf("%d", len);
ans[0]='\0';
while(flag==1)
{
flag=0;
for(i=0;i<len;i++)
{
	flag=0;	
	if(str[i]!=str[1+i] && str[i]!=str[i-1])
	{	
		char temp[2]={str[i],'\0'};
		strcat(ans,temp);
		str[0]='\0';
		strcpy(str,ans);
		flag=1;
		len=strlen(str)+1;
	}

}
//flag=1;
flag=0;
printf("\n%s\n", str);

}

printf("\n%s\n", str);
return 0;
}

