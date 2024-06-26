#include<stdio.h>
#include<string.h>
int main()
{
int i,j=0,la,lb,ac[128]={0},bc[128]={0};
char a[100],b[100];

printf("Enter first string: ");
fgets(a, sizeof(a), stdin);  
a[strcspn(a, "\n")] = '\0';

printf("Enter second string: ");
fgets(b, sizeof(b), stdin);  
b[strcspn(b, "\n")] = '\0';


/*
printf("Enter first string: ");
scanf("%[^\n]s", a);

printf("Enter second string: ");
scanf("%[^\n]s", b);
*/
la=strlen(a);
lb=strlen(b);

if(la!=lb)
{
printf("Not Anagrams\n");
return 0;
}

for(i=0;i<la;i++)
{	
	ac[a[i]]++;
	bc[b[i]]++;
}

for(i=0;i<la;i++)
{
//printf("%d== %c: %d %d\n",a[i],a[i],ac[a[i]],bc[a[i]]);
if(ac[a[i]]!=bc[a[i]])
{	

//printf("..........j=1..............\n");
	j=1;
	
}
}

if(j==1)
{
printf("Not Anagrams\n");
}
else
printf("Anagrams\n");

return 0;
}
