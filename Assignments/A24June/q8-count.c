#include<stdio.h>
int main()
{
int i,n,j,a[10],freq[10], *b, count;
n=10; // NUmber of elements in array
printf("Enter 10 numbers:\n");
for(i=0;i<n;i++)
{
	freq[i]=-1;
	scanf("%d", &a[i]);
}

//printf("\nFREQ\n");


for(i=0;i<n;i++)
{	
	count=1;
	if(freq[i]!=0)
	{	//////////////////////
//		if(i==8)
//			printf("count=%d, a[8] = %d, freq[8] = %d",count,  a[8], freq[8]);
/////////////////////////////

		for(j=i+1;j<n;j++)
		{
			if(a[j]==a[i])
			{
					
//				if(i==8) printf("BS");
				count++;
				freq[j]=0;
			}
		}
		freq[i]=count;
		
//		if(i==8) printf("i=%d, freq= %d, count=%d", i, freq[i], count);
	}
}

for(i=0;i<n;i++)
{
	if(freq[i]>0)
		printf("Count of %d = %d\n" , a[i], freq[i]);
}

return 0;
}
