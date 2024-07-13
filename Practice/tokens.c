#include<stdio.h>
#include<string.h>
int main()
{
int n,count=0;
char *token, str1[200];
printf("Enter a string of words: ");
scanf("%[^\n]s", str1);
token= strtok(str1, " ");
while(token!= NULL)
{
count++;
printf("%s\n", token);
token= strtok(NULL, " ");
}
return 0;
}
