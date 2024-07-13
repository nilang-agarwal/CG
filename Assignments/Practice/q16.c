#include<stdio.h>
#include<string.h>

int pal(char *str)
{
int i,n;
n=strlen(str);
for(i=0;i<n/2;i++)
{
	if(str[i]!=str[n-i-1])
		return 0;
}
return 1;
}

int main()
{
int score=0,n,i,j;
char str[100],w1[5]="",w2[6]="";
printf("Enter the string: ");
fgets(str,100,stdin);
n=strlen(str);
if(str[n-1]=='\n')
	str[n-1]='\0';
n=strlen(str);
for(i=0;i<=n-5;i++)
{

//	printf("%d..%s, %s, %d..\n",i,w1,w2,score);
/*
	w1[0]='\0';
	w1[0]=str[i];	
	w1[1]='\0';
	w1[1]=str[i+1];
	w1[2]='\0';
	w1[2]=str[i+2];	
	w1[3]='\0';
	w1[3]=str[i+3];
	w1[4]='\0';

	w2[0]='\0';
	w2[0]=str[i];	
	w2[1]=str[i+1];
	w2[2]=str[i+2];	
	w2[3]=str[i+3];
	w2[4]=str[i+4];	
	w2[5]='\0';
*/
	strncpy(w1, str + i, 4);
        w1[4] = '\0';

        // Form substrings w2 of length 5
        strncpy(w2, str + i, 5);
        w2[5] = '\0';

//	printf("%d..%s, %s, %d..\n",i,w1,w2,score);
	if(pal(w1)==1)
		score+=5;
	if(pal(w2)==1)
		score+=10;
//	printf("%d..%s, %s, %d..\n",i,w1,w2,score);
}

	strncpy(w1, str + n - 4, 4);
    	w1[4] = '\0';
        if(pal(w1)==1)
                score+=5;

printf("Score= %d\n", score);

return 0;
}
