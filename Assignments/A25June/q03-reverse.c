#include<stdio.h>
#include<string.h>

int main()
{
int i=0, count=0, n;
char *token,a[100],words[20][20], new[20];

printf("Enter any string:\n");
fgets(a, sizeof(a), stdin);
a[strcspn(a, "\n")] = '\0';

token=strtok(a, " ");
while(token!=NULL & count<20)
{	
	strcpy(words[count],token);
	count++;
	token = strtok(NULL, " ");
}

strcpy(new, "\0");

for(int i=0;i<count;i++)
{
	strcat(new, words[count-i-1]);
	strcat(new, " ");
}

printf("\n%s\n\n", new);


return 0;
}
