#include<stdio.h>
int main()
{
int a, s1=0, s2=0,r=0;
printf("Enter any number: ");
scanf("%d",&a);
while(s2<a)
{
	s1=r*r;
	s2=(r+1)*(r+1);
	r++;
}

if(a-s1>s2-a)
	r=s2;
else
	r=s1;


printf("Closest Perfect Square= %d\n", r);
return 0;
}
