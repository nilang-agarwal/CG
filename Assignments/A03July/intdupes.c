#include<stdio.h>
#include<string.h>
int main()
{
int nums[20], n, j, i=0, flag;
printf("Enter the number of integers: ");
scanf("%d", &n);

printf("Enter %d integers: \n",n);
while(i<n)
{
	scanf("%d", &nums[i]);
	i++;
}
printf("..........................\n");
/*for(i=0;i<n;i++)
{
	flag=1;
	for(j=i+1;j<n;j++)
	{
		if(nums[i]==nums[j])
			flag=0;
	}

	if(flag==1)
		printf("%d \n",nums[i]);
}*/


for(i=n-1;i>=0;i--)
{
	flag=1;
	for(j=i-1;j>=0;j--)
	{
		if(nums[i]==nums[j])
		{
			flag=0;
			printf("%d ", nums[i]);
		}

	}

	if(flag==0)
		printf("%d \n",nums[i]);
}



return 0;
}


