#include<stdio.h>
main()
{
	int arr[10],i,j,count=1,k=0;
	printf("Enter elements for the array:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);	
	}
	printf("The duplicate array elements are:\n");
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;			
			}
		}
		for(j=0;j<i;j++)
		{
			if(arr[i]!=arr[j])
			{
				k++;	
			}			
		}
		if(count>=2 && k==i)
				{
					printf("%d\n",arr[i]);
				}
		
		count=1;
		k=0;
	}
	
}
