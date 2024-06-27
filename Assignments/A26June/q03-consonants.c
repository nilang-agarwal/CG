#include<stdio.h>
#include<string.h>
int main()
{
int n,c[50], ind;
int count=0;
char a[50];
printf("Enter any word in lower case: ");
fgets(a,50,stdin);
n=strlen(a);
if(a[n-1]=='\n')
	a[n-1]='\0';
n=strlen(a);
int i=0;
while(i<n)
{
	if(	
		a[i]=='b' || 
		a[i]=='c' || 
		a[i]=='d' || 
		a[i]=='f' || 
		a[i]=='g' ||
		a[i]=='h' || 
		a[i]=='j' || 
		a[i]=='k' || 
		a[i]=='l' || 
		a[i]=='m' ||		
		a[i]=='n' || 
		a[i]=='p' || 
		a[i]=='q' || 
		a[i]=='r' || 
		a[i]=='s' || 
		a[i]=='t' ||
		a[i]=='v' || 
		a[i]=='w' || 
		a[i]=='x' || 
		a[i]=='y' ||
		a[i]=='z'
	)
		count++;
	c[i]=count;	
//	printf("\n%d. %c = %d\n",i, a[i], c[i]);
	i++;
}i=0;
int h= count/2 + 1;
while(i<count)
{
 if(c[i]==h)
 {	 ind=i;
	 break;
  }
 i++;
}
printf("We can split the string in %d ways\n",n-ind-1 );

return 0;
}
