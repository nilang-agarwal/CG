#include<stdio.h>
int main()
{
int nums[10],n,i=0,j,flag;
printf("Enter the number of integers: " );
scanf("%d", &n);
printf("Enter %d integers:\n",n);
for(i=0;i<n;i++)
{
scanf("%d", &nums[i]);
}
printf(".......................\n");

for(i=0;i<n;i++)
{
	flag=1;
	for(j=0;j<n;j++)
	{
		if(nums[i]==nums[j] && i!=j)
			flag=0;
	}

	if(flag==1)
		printf("%d \n",nums[i]);
}

return 0;
}
